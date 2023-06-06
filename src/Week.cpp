#include "../include/Week.hpp"

Week::Week(int week_number , vector< pair<Player*,double> > _scores , vector<Match*> matches , vector<string> Red_cards , vector<string> Yellow_cards , vector<string> injured_players)
{
    this->week_number = week_number;
    this->scores = _scores;
    this->matches = matches;
    this->Red_cards = Red_cards;
    this->Yellow_cards = Yellow_cards;
    this->injured_players = injured_players;
    update_type_players();
}
void Week::add_match(MainTeam* team1, MainTeam* team2 , int result1 , int result2)
{
    Match* match = new Match(team1 , team2 , result1 , result2);
    this->matches.push_back(match);
}

// void Week::print_week()
// {
//     cout << endl << "Week " << this->week_number << ":" << endl;
//     for(auto match : this->matches)
//     {
//         cout << match->get_team1()->get_team_name() << " " << match->get_result1() << " - " << match->get_result2() << " " << match->get_team2()->get_team_name() << endl;
//     }
//     cout << "Scores:" << endl;
//     cout << "size of scores: " << this->scores.size() << endl;
//     for(auto score : this->scores)
//     {
//         cout << score.first->getName() << " " << score.second << endl;
//     }
//     cout << "Red cards:" << endl;
//     for(auto red_card : this->Red_cards)
//     {
//         cout << red_card << endl;
//     }
//     cout << "Yellow cards:" << endl;
//     for(auto yellow_card : this->Yellow_cards)
//     {
//         cout << yellow_card << endl;
//     }
//     cout << "Injured players:" << endl;
//     for(auto injured_player : this->injured_players)
//     {
//         cout << injured_player << endl;
//     }
// }

Player* Week::find_player(string player_name)
{
    for(auto score : this->scores)
    {
        if(score.first->getName() == player_name)
        {
            return score.first;
        }
    }
    return nullptr;
}



// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 

void Week::update_players()
{
    for(auto score : this->scores)
    {
        // cout << scores.size()<< endl;
        score.first->set_score(score.second);
        score.first->increase_score(score.second);

        //////////////////////////////
        // cout << score.first->get_name()  << " score: " << score.second << " " << score.first->get_score() << endl;
        //////////////////////////////
    }
    for(auto red_card : this->Red_cards)
    {
        Player* player = this->find_player(red_card);
        if(player != nullptr)
        {
            player->set_last_week_red_card(week_number);
        }
    }
    for(auto yellow_card : this->Yellow_cards)
    {
        Player* player = this->find_player(yellow_card);
        if(player != nullptr)
        {
            player->increase_count_of_yellow_card();
        }
    }
    for(auto injured_player : this->injured_players)
    {
        Player* player = this->find_player(injured_player);
        if(player != nullptr)
        {
            player->set_last_week_injury(week_number);
        }
    }
    update_matchs();
}

vector< pair<Player*,double> > Week::get_best_team_week()
{
    vector< pair<Player*,double> > best_team_week;
    sort(this->goalkeepers_players.begin() , this->goalkeepers_players.end() , [](pair<Player*,double> a , pair<Player*,double> b){
        if(a.second == b.second)
        {
            return a.first->get_name() < b.first->get_name();
        }
        return a.second > b.second;
    });
    sort(this->defenders_players.begin() , this->defenders_players.end() , [](pair<Player*,double> a , pair<Player*,double> b){
        if(a.second == b.second)
        {
            return a.first->get_name() < b.first->get_name();
        }
        return a.second > b.second;
    });
    //cheak
    sort(this->midfielders_players.begin() , this->midfielders_players.end() , [](pair<Player*,double> a , pair<Player*,double> b){
        if(a.second == b.second)
        {
            return a.first->get_name() < b.first->get_name();
        }
        return a.second > b.second;
    
    });
    sort(this->forwards_players.begin() , this->forwards_players.end() , [](pair<Player*,double> a , pair<Player*,double> b){
        if(a.second == b.second)
        {
            return a.first->get_name() < b.first->get_name();
        }
        return a.second > b.second;
    });

    best_team_week.push_back(this->goalkeepers_players[0]);
    for(int i = 0 ; i < 2 ; i++)
    {
        best_team_week.push_back(this->defenders_players[i]);
    }
    best_team_week.push_back(this->midfielders_players[0]);
    best_team_week.push_back(this->forwards_players[0]);
    return best_team_week;
}

void Week::update_type_players()
{
    // pair<Player*,double> temp;
    for(auto score : this->scores)
    {
        if(score.first->get_type() == DEFENDER)
        {
            this->defenders_players.push_back(score);
        }
        else if(score.first->get_type() == MIDFIELDER)
        {
            this->midfielders_players.push_back(score);
        }
        else if(score.first->get_type() == FORWARD)
        {
            this->forwards_players.push_back(score);
        }
        else if(score.first->get_type() == GOALKEEPER)
        {
            this->goalkeepers_players.push_back(score);
        }
    }
}

void Week::update_matchs()
{
    for(auto match : this->matches)
    {
        match->update_match();
    }
}





// need to be deleted
void Week::print_week()
{
    cout << endl << "Week " << this->week_number << ":" << endl;
    cout << "Scores:" << endl;
    cout << "size of scores: " << this->scores.size() << endl;
    for(auto score : this->scores)
    {
        cout << score.first->getName() << " " << score.second << endl;
    }
}