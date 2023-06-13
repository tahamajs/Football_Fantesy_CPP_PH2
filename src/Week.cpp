#include "../include/Week.hpp"

bool cmp(pair<Player *, double> a, pair<Player *, double> b)
{
    if (a.second == b.second)
    {
        return a.first->get_name() < b.first->get_name();
    }
    return a.second > b.second;
}

Week::Week(int week_number, vector<vector<pair<string, string>>> _goal_with_assist, vector<pair<vector<pair<string, double>>, vector<pair<string, double>>>> _players_of_team, vector<Match *> matches, vector<string> Red_cards, vector<string> Yellow_cards, vector<string> injured_players)
{
    this->week_number = week_number;
    this->goal_with_assist = _goal_with_assist;
    this->players_of_team = _players_of_team;
    this->matches = matches;
    this->Red_cards = Red_cards;
    this->Yellow_cards = Yellow_cards;
    this->injured_players = injured_players;
}

void Week::add_match(MainTeam *team1, MainTeam *team2, int result1, int result2)
{
    Match *match = new Match(team1, team2, result1, result2);
    this->matches.push_back(match);
}

Player *Week::find_player(string player_name)
{
    for (auto player : this->All_playyers)
    {
        if (player->get_name() == player_name)
        {
            return player;
        }
    }
    return nullptr;
}

void Week::update_players()
{
    update_scores();

    int i = 0;
    for (auto players_team : this->players_of_team)
    {
        for (auto player_of_team : players_team.first)
        {
            if (find_player(player_of_team.first) != nullptr)
            {
                Player *player = find_player(player_of_team.first);
                player->set_score(player_of_team.second);
                player->increase_score(player_of_team.second);

                player->increase_assists_goals(number_of_assist(player_of_team.first, i));

                player->increase_goals(number_of_goal(player_of_team.first, i));
                player->increase_clean_sheet(matches[1]->get_result2() == 0);
            }
        }
        for (auto player_of_team : players_team.second)
        {
            if (find_player(player_of_team.first) != nullptr)
            {
                Player *player = find_player(player_of_team.first);
                player->set_score(player_of_team.second);
                player->increase_score(player_of_team.second);

                player->increase_assists_goals(number_of_assist(player_of_team.first, i));
                player->increase_goals(number_of_goal(player_of_team.first, i));
                player->increase_clean_sheet(matches[i]->get_result1() == 0);
            }
        }
        i++;
    }

    // }
    for (auto red_card : this->Red_cards)
    {
        Player *player = this->find_player(red_card);
        if (player != nullptr)
        {
            player->set_last_week_red_card(week_number);
        }
    }
    for (auto yellow_card : this->Yellow_cards)
    {
        Player *player = this->find_player(yellow_card);
        if (player != nullptr)
        {
            player->increase_count_of_yellow_card();
        }
    }
    for (auto injured_player : this->injured_players)
    {
        Player *player = this->find_player(injured_player);
        if (player != nullptr)
        {
            player->set_last_week_injury(week_number);
        }
    }
    update_matchs();
}

vector<pair<Player *, double>> Week::get_best_team_week()
{
    vector<pair<Player *, double>> best_team_week;
    sort(this->goalkeepers_players.begin(), this->goalkeepers_players.end(), cmp);
    sort(this->defenders_players.begin(), this->defenders_players.end(), cmp);
    // cheak
    sort(this->midfielders_players.begin(), this->midfielders_players.end(), cmp);
    sort(this->forwards_players.begin(), this->forwards_players.end(), cmp);

    best_team_week.push_back(this->goalkeepers_players[0]);
    for (int i = 0; i < 2; i++)
    {
        best_team_week.push_back(this->defenders_players[i]);
    }
    best_team_week.push_back(this->midfielders_players[0]);
    best_team_week.push_back(this->forwards_players[0]);
    return best_team_week;
}

void Week::update_type_players()
{
    for (auto player : players_of_team)
    {
        for (auto player1 : player.first)
        {
            // cout << player1.first << endl;
            if (find_player(player1.first) != nullptr)
            {

                Player *player2 = find_player(player1.first);
                if (player2->get_type() == DEFENDER)
                {
                    this->defenders_players.push_back(make_pair(find_player(player1.first), player1.second));
                }
                else if (player2->get_type() == MIDFIELDER)
                {
                    this->midfielders_players.push_back(make_pair(find_player(player1.first), player1.second));
                }
                else if (player2->get_type() == FORWARD)
                {
                    this->forwards_players.push_back(make_pair(find_player(player1.first), player1.second));
                }
                else if (player2->get_type() == GOALKEEPER)
                {
                    this->goalkeepers_players.push_back(make_pair(find_player(player1.first), player1.second));
                }
            }
        }
        for (auto player1 : player.second)
        {
            if (find_player(player1.first) != nullptr)
            {
                Player *player2 = find_player(player1.first);
                if (player2->get_type() == DEFENDER)
                {
                    this->defenders_players.push_back(make_pair(find_player(player1.first), player1.second));
                }
                else if (player2->get_type() == MIDFIELDER)
                {
                    this->midfielders_players.push_back(make_pair(find_player(player1.first), player1.second));
                }
                else if (player2->get_type() == FORWARD)
                {
                    this->forwards_players.push_back(make_pair(find_player(player1.first), player1.second));
                }
                else if (player2->get_type() == GOALKEEPER)
                {
                    this->goalkeepers_players.push_back(make_pair(find_player(player1.first), player1.second));
                }
            }
        }
    }
}

void Week::update_matchs()
{
    for (auto match : this->matches)
    {
        match->update_match();
    }
}

int Week::number_of_goal(string player_name, int row_number)
{
    int number_of_goal = 0;
    for (auto gwa : this->goal_with_assist[row_number])
    {
        if (gwa.first == player_name)
        {
            number_of_goal++;
        }
    }
    return number_of_goal;
}

int Week::number_of_assist(string player_name, int row_number)
{
    int number_of_assist = 0;
    for (auto gwa : this->goal_with_assist[row_number])
    {
        if (gwa.second == player_name)
        {
            number_of_assist++;
        }
    }
    return number_of_assist;
}


double Week::score_calculator(double x)
{
    return 10.0 / (1.0 + exp(-x / 6.0));
}

void Week::update_scores()
{
    for (int i = 0; i < 10; i++)
    {

        set_type_of_player_position(i);

        if (matches[i]->get_result1() > matches[i]->get_result2())
        {
            // team 1 win
            for (size_t k = 0; k < players_of_team[i].first.size(); k++)
            {
                players_of_team[i].first[k].second += DEFULT_WIN_SCORE_WEEK;
            }
            for (size_t k = 0; k < players_of_team[i].second.size(); k++)
            {
                players_of_team[i].second[k].second += DEFULT_LOSE_SCORE_WEEK;
            }
        }
        else if (matches[i]->get_result1() == matches[i]->get_result2())
        {
            // draw
            for (size_t k = 0; k < players_of_team[i].first.size(); k++)
            {
                players_of_team[i].first[k].second += DEFULT_DRAW_SCORE_WEEK;
            }
            for (size_t k = 0; k < players_of_team[i].second.size(); k++)
            {
                players_of_team[i].second[k].second += DEFULT_DRAW_SCORE_WEEK;
            }
        }
        else
        {
            // team 2 win
            for (size_t k = 0; k < players_of_team[i].first.size(); k++)
            {
                players_of_team[i].first[k].second += DEFULT_LOSE_SCORE_WEEK;
            }
            for (size_t k = 0; k < players_of_team[i].second.size(); k++)
            {
                players_of_team[i].second[k].second += DEFULT_WIN_SCORE_WEEK;
            }
        }

        // goals and assist for goalkeeper
        if (matches[i]->get_result2() == 0)
        {
            players_of_team[i].first[0].second += DEFULT_GOALKEEPER_CLEAN_SHEET_SCORE_WEEK;
        }
        else
        {
            players_of_team[i].first[0].second -= matches[i]->get_result2();
        }

        if (matches[i]->get_result1() == 0)
        {
            players_of_team[i].second[0].second += DEFULT_GOALKEEPER_CLEAN_SHEET_SCORE_WEEK;
        }
        else
        {
            // cout << "nkkk"
            players_of_team[i].second[0].second -= matches[i]->get_result1();
        }

        players_of_team[i].first[0].second += DEFULT_SCORE_GOALKEEPER_IN_WEEK;
        players_of_team[i].second[0].second += DEFULT_SCORE_GOALKEEPER_IN_WEEK;

        if (matches[i]->get_result2() == 0)
        {
            for (int j = 1; j < 5; j++)
            {
                players_of_team[i].first[j].second += DEFULT_DEFENDER_CLEAN_SHEET_SCORE_WEEK;
            }
        }
        if (matches[i]->get_result1() == 0)
        {
            for (int j = 1; j < 5; j++)
            {
                players_of_team[i].second[j].second += DEFULT_DEFENDER_CLEAN_SHEET_SCORE_WEEK;
            }
        }
        for (int j = 1; j < 5; j++)
        {
            players_of_team[i].first[j].second += number_of_goal(players_of_team[i].first[j].first, i) * DEFULT_GOAL_SCORE_DEFENDER;
            players_of_team[i].first[j].second += number_of_assist(players_of_team[i].first[j].first, i) * DEFULT_GOAL_ASSIST_SCORE_DEFENDER;
            players_of_team[i].second[j].second += number_of_goal(players_of_team[i].second[j].first, i) * DEFULT_GOAL_SCORE_DEFENDER;
            players_of_team[i].second[j].second += number_of_assist(players_of_team[i].second[j].first, i) * DEFULT_GOAL_ASSIST_SCORE_DEFENDER;

            players_of_team[i].first[j].second += DEFULT_SCORE_DEFENDER_IN_WEEK;
            players_of_team[i].second[j].second += DEFULT_SCORE_DEFENDER_IN_WEEK;
        }

        if (matches[i]->get_result2() == 0)
        {
            for (int j = 5; j < 8; j++)
            {
                players_of_team[i].first[j].second += DEFULT_MIDFIELDER_CLEAN_SHEET_SCORE_WEEK;
            }
        }
        if (matches[i]->get_result1() == 0)
        {
            for (int j = 5; j < 8; j++)
            {
                players_of_team[i].second[j].second += DEFULT_MIDFIELDER_CLEAN_SHEET_SCORE_WEEK;
            }
        }
        for (int j = 5; j < 8; j++)
        {
            players_of_team[i].first[j].second += number_of_goal(players_of_team[i].first[j].first, i) * DEFULT_GOAL_SCORE_MIDFIELDER;
            players_of_team[i].first[j].second += number_of_assist(players_of_team[i].first[j].first, i) * DEFULT_GOAL_ASSIST_SCORE_MIDFIELDER;
            players_of_team[i].second[j].second += number_of_goal(players_of_team[i].second[j].first, i) * DEFULT_GOAL_SCORE_MIDFIELDER;
            players_of_team[i].second[j].second += number_of_assist(players_of_team[i].second[j].first, i) * DEFULT_GOAL_ASSIST_SCORE_MIDFIELDER;
        }

        for (int j = 8; j < 11; j++)
        {
            if (number_of_goal(players_of_team[i].first[j].first, i) == 0)
            {
                players_of_team[i].first[j].second += DEFULT_NOT_GOAL_SCORE_FORWARD;
            }
            else
            {
                players_of_team[i].first[j].second += number_of_goal(players_of_team[i].first[j].first, i) * DEFULT_GOAL_SCORE_FORWARD;
            }
            if (number_of_goal(players_of_team[i].second[j].first, i) == 0)
            {
                players_of_team[i].second[j].second += DEFULT_NOT_GOAL_SCORE_FORWARD;
            }
            else
            {
                players_of_team[i].second[j].second += number_of_goal(players_of_team[i].second[j].first, i) * DEFULT_GOAL_SCORE_FORWARD;
            }

            players_of_team[i].first[j].second += number_of_assist(players_of_team[i].first[j].first, i) * DEFULT_GOAL_ASSIST_SCORE_FORWARD;
            players_of_team[i].second[j].second += number_of_assist(players_of_team[i].second[j].first, i) * DEFULT_GOAL_ASSIST_SCORE_FORWARD;
        }

        for (size_t k = 0; k < players_of_team.size(); k++)
        {

            for (int x = 0; x < players_of_team[k].first.size(); x++)
            {
                if (is_OWN_GOAL(players_of_team[k].first[x].first, i))
                {
                    players_of_team[k].first[x].second += DEFULT_OWN_GOAL_SCORE;
                }
            }

            for (int x = 0; x < players_of_team[k].second.size(); x++)
            {
                if (is_OWN_GOAL(players_of_team[k].second[x].first, i))
                {
                    players_of_team[k].second[x].second += DEFULT_OWN_GOAL_SCORE;
                }
            }
        }

        for (size_t k = 0; k < goal_with_assist[i].size(); k++)
        {
            vector<pair<string, double>> *team1;
            vector<pair<string, double>> *team2;
            if (get_player_local_team(goal_with_assist[i][k].first) == TEAM_ONE)
            {
                team1 = &players_of_team[i].first;
                team2 = &players_of_team[i].second;
            }
            else
            {
                team1 = &players_of_team[i].second;
                team2 = &players_of_team[i].first;
            }

            if (find_player(goal_with_assist[i][k].first)->get_type() == DEFENDER)
            {
                DefenderPlayer *defender_player = dynamic_cast<DefenderPlayer *>(find_player(goal_with_assist[i][k].first));
                Defender_position defender_position = defender_player->get_player_position();
                if (defender_position == RIGHT_CORNER)
                {
                    team2->at(1).second -= 1;
                }
                if (defender_position == LEFT_CORNER)
                {
                    team2->at(4).second -= 1;
                }
                if (defender_position == LEFT_MIDDLE || defender_position == LEFT_MIDDLE)
                {
                    team2->at(2).second -= 1;
                    team2->at(3).second -= 1;
                }
            }
            if (find_player(goal_with_assist[i][k].first)->get_type() == MIDFIELDER)
            {
                MidfielderPlayer *midfielder_player = dynamic_cast<MidfielderPlayer *>(find_player(goal_with_assist[i][k].first));
                Midfielder_position midfielder_position = midfielder_player->get_player_position();
                if (midfielder_position == LEFT || midfielder_position == RIGHT || midfielder_position == CENTER)
                {
                    team2->at(5).second -= 1;
                    team2->at(6).second -= 1;
                    team2->at(7).second -= 1;
                }
            }
            if (find_player(goal_with_assist[i][k].first)->get_type() == FORWARD)
            {
                ForwardPlayer *forward_player = dynamic_cast<ForwardPlayer *>(find_player(goal_with_assist[i][k].first));
                Forward_position forward_position = forward_player->get_player_position();
                if (forward_position == LEFT_WING)
                {
                    team2->at(4).second -= 1;
                }
                if (forward_position == CENTER_FORWARD)
                {
                    team2->at(2).second -= 1;
                    team2->at(3).second -= 1;
                }
                if (forward_position == RIGHT_WING)
                {
                    team2->at(1).second -= 1;
                }
            }
        }
    }

    // for (auto x : players_of_team)
    // {
    //     for (auto y : x.first)
    //     {
    //         cout << "xxxxxxnnxxxx " << y.first << " " << y.second << endl;
    //     }
    // }

    for (int i = 0; i < players_of_team.size(); i++)
    {
        for (int j = 0; j < players_of_team[i].first.size(); j++)
        {
            players_of_team[i].first[j].second = score_calculator(players_of_team[i].first[j].second);
        }
        for (int j = 0; j < players_of_team[i].second.size(); j++)
        {
            players_of_team[i].second[j].second = score_calculator(players_of_team[i].second[j].second);
        }
    }

    update_type_players();
}

bool Week::is_OWN_GOAL(string player_name, int row_number)
{
    for (auto x : goal_with_assist[row_number])
    {
        if (x.first == player_name && x.second == OWN_GOAL_STRING)
        {
            return true;
        }
    }
    return false;
}

int Week::number_of_goal_total(string player_name)
{
    int number_of_goal = 0;
    for (auto x : goal_with_assist)
    {
        for (auto y : x)
        {
            if (y.first == player_name)
            {
                number_of_goal++;
            }
        }
    }
    return number_of_goal;
}

int Week::number_of_assist_total(string player_name)
{
    int number_of_assist = 0;
    for (auto x : goal_with_assist)
    {
        for (auto y : x)
        {
            if (y.second == player_name)
            {
                number_of_assist++;
            }
        }
    }
    return number_of_assist;
}

void Week::set_all_players(vector<Player *> _players)
{
    this->All_playyers = _players;
}

void Week::print_goal_with_assist()
{
    for (auto x : goal_with_assist)
    {
        for (auto y : x)
        {
            cout << y.first << " " << y.second << endl;
        }
    }
}

bool Week::is_player_goal(string player_name, int row_number)
{
    for (auto x : goal_with_assist[row_number])
    {
        if (x.first == player_name)
        {
            return true;
        }
    }
    return false;
}

int Week::get_player_local_team(string player_name)
{
    for (auto x : players_of_team)
    {
        for (auto y : x.first)
        {
            if (y.first == player_name)
            {
                return TEAM_ONE;
            }
        }
        for (auto y : x.second)
        {
            if (y.first == player_name)
            {
                return TEAM_TWO;
            }
        }
    }
    return 0;
}

void Week::set_type_of_player_position(int i)
{
    DefenderPlayer *defender_player1 = dynamic_cast<DefenderPlayer *>(find_player(players_of_team[i].first[1].first));
    if (defender_player1 == NULL)
    {
        cout << ERROR_FILE << endl;
        return;
    }
    defender_player1->set_player_position(Defender_position::LEFT_CORNER);

    DefenderPlayer *defender_player2 = dynamic_cast<DefenderPlayer *>(find_player(players_of_team[i].first[2].first));
    if (defender_player2 == NULL)
    {
        cout << ERROR_FILE << endl;
        return;
    }
    defender_player2->set_player_position(Defender_position::LEFT_MIDDLE);

    DefenderPlayer *defender_player3 = dynamic_cast<DefenderPlayer *>(find_player(players_of_team[i].first[3].first));
    if (defender_player3 == NULL)
    {
        cout << ERROR_FILE << find_player(players_of_team[i].first[3].first)->get_type() << " " << find_player(players_of_team[i].first[3].first)->get_name() << endl;
        return;
    }
    defender_player3->set_player_position(Defender_position::RIGHT_MIDDLE);

    DefenderPlayer *defender_player4 = dynamic_cast<DefenderPlayer *>(find_player(players_of_team[i].first[4].first));
    if (defender_player4 == NULL)
    {
        cout << ERROR_FILE << endl;
        return;
    }
    defender_player4->set_player_position(Defender_position::RIGHT_CORNER);

    MidfielderPlayer *midfielder_player1 = dynamic_cast<MidfielderPlayer *>(find_player(players_of_team[i].first[5].first));
    if (midfielder_player1 == NULL)
    {
        cout << ERROR_FILE << endl;
        return;
    }
    midfielder_player1->set_player_position(Midfielder_position::LEFT);

    MidfielderPlayer *midfielder_player2 = dynamic_cast<MidfielderPlayer *>(find_player(players_of_team[i].first[6].first));
    if (midfielder_player2 == NULL)
    {
        cout << ERROR_FILE << endl;
        return;
    }
    midfielder_player2->set_player_position(Midfielder_position::CENTER);

    MidfielderPlayer *midfielder_player3 = dynamic_cast<MidfielderPlayer *>(find_player(players_of_team[i].first[7].first));
    if (midfielder_player3 == NULL)
    {
        cout << ERROR_FILE << endl;
        return;
    }
    midfielder_player3->set_player_position(Midfielder_position::RIGHT);

    ForwardPlayer *forward_player1 = dynamic_cast<ForwardPlayer *>(find_player(players_of_team[i].first[8].first));
    if (forward_player1 == NULL)
    {
        cout << ERROR_FILE << endl;
        return;
    }
    forward_player1->set_player_position(Forward_position::LEFT_WING);

    ForwardPlayer *forward_player2 = dynamic_cast<ForwardPlayer *>(find_player(players_of_team[i].first[9].first));
    if (forward_player2 == NULL)
    {
        cout << ERROR_FILE << endl;
        return;
    }
    forward_player2->set_player_position(Forward_position::CENTER_FORWARD);

    ForwardPlayer *forward_player3 = dynamic_cast<ForwardPlayer *>(find_player(players_of_team[i].first[10].first));
    if (forward_player3 == NULL)
    {
        cout << ERROR_FILE << endl;
        return;
    }
    forward_player3->set_player_position(Forward_position::RIGHT_WING);

    defender_player1 = dynamic_cast<DefenderPlayer *>(find_player(players_of_team[i].second[1].first));
    if (defender_player1 == NULL)
    {
        cout << ERROR_FILE << endl;
        return;
    }
    defender_player1->set_player_position(Defender_position::LEFT_CORNER);

    defender_player2 = dynamic_cast<DefenderPlayer *>(find_player(players_of_team[i].second[2].first));
    if (defender_player2 == NULL)
    {
        cout << ERROR_FILE << endl;
        return;
    }
    defender_player2->set_player_position(Defender_position::LEFT_MIDDLE);
    // cout << i << endl;
    defender_player3 = dynamic_cast<DefenderPlayer *>(find_player(players_of_team[i].second[3].first));
    if (defender_player3 == NULL)
    {
        cout << ERROR_FILE << endl;
        return;
    }

    defender_player3->set_player_position(Defender_position::RIGHT_MIDDLE);

    defender_player4 = dynamic_cast<DefenderPlayer *>(find_player(players_of_team[i].second[4].first));
    if (defender_player4 == NULL)
    {
        cout << ERROR_FILE << endl;
        return;
    }
    defender_player4->set_player_position(Defender_position::RIGHT_CORNER);

    midfielder_player1 = dynamic_cast<MidfielderPlayer *>(find_player(players_of_team[i].second[5].first));
    if (midfielder_player1 == NULL)
    {
        cout << ERROR_FILE << endl;
        return;
    }
    midfielder_player1->set_player_position(Midfielder_position::LEFT);

    midfielder_player2 = dynamic_cast<MidfielderPlayer *>(find_player(players_of_team[i].second[6].first));
    if (midfielder_player2 == NULL)
    {
        cout << ERROR_FILE << endl;
        return;
    }
    midfielder_player2->set_player_position(Midfielder_position::CENTER);

    midfielder_player3 = dynamic_cast<MidfielderPlayer *>(find_player(players_of_team[i].second[7].first));
    if (midfielder_player3 == NULL)
    {
        cout << ERROR_FILE << endl;
        return;
    }
    midfielder_player3->set_player_position(Midfielder_position::RIGHT);

    forward_player1 = dynamic_cast<ForwardPlayer *>(find_player(players_of_team[i].second[8].first));
    if (forward_player1 == NULL)
    {
        cout << ERROR_FILE << endl;
        return;
    }
    forward_player1->set_player_position(Forward_position::LEFT_WING);

    forward_player2 = dynamic_cast<ForwardPlayer *>(find_player(players_of_team[i].second[9].first));
    if (forward_player2 == NULL)
    {
        cout << ERROR_FILE << endl;
        return;
    }
    forward_player2->set_player_position(Forward_position::CENTER_FORWARD);

    forward_player3 = dynamic_cast<ForwardPlayer *>(find_player(players_of_team[i].second[10].first));
    if (forward_player3 == NULL)
    {
        cout << ERROR_FILE << endl;
        return;
    }
    forward_player3->set_player_position(Forward_position::RIGHT_WING);
}