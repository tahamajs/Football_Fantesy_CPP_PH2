#include "../include/System.hpp"

System::System()
{
    this->admin = new Admin(&transfare_state);
    this->current_user = nullptr;
    init_main_teams();
    init_weeks();
    

    // for(Player* _Player : players)
    // {
    //     cout << _Player->get_name() << " " << _Player->get_score() << "\n";
    // }

    // for(Week* week : weeks)
    // {
        // weeks[0]->print_week();
    // }

}

System::~System()
{
    for (auto user : users)
    {
        delete user;
    }
    for (auto team : main_teams)
    {
        delete team;
    }
    for (auto player : players)
    {
        delete player;
    }
    for (auto week : weeks)
    {
        delete week;
    }
    for (auto team : fantasy_teams)
    {
        delete team;
    }
    delete admin;
}

vector<string> System::split(const string& str, char delim) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) {
        // if(token != "")
            tokens.push_back(token);
    }

    // Check if the last character in the input string is equal to the delimiter
    if (!str.empty() && str.back() == delim) {
        // tokens.push_back("") ;
    }
    return tokens;
}


//need to check
void System::init_main_teams()
{
    ifstream file;
    file.open(PREMIER_LEAGUE_FILE_PATH);
    string line;
    if(!file.is_open())
    {
        cout << "Error opening file" << endl;
    }
    getline(file, line); 
    //for first line
    while (getline(file, line))
    {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        vector<string> splitted_line_team = split(line, ',');
        vector<Player*> playerTemp;
        string team_name = splitted_line_team[0];

        vector<string> Goalkeeper_players = split(splitted_line_team[1], ';');
        for (auto player : Goalkeeper_players)
        {
            vector<string> temp = split(player, ':');
            string name = temp[0];

            //check .....................................................
            double price = stod(temp[1].erase(temp[1].find('$'), 1));


            Player* new_player = new GoalkeeperPlayer(name, DEFULT_SCORE, GOALKEEPER);
            new_player->set_player_price(price);
            playerTemp.push_back(new_player);
            this->players.push_back(new_player);
        }
        
        vector<string> Defender_players = split(splitted_line_team[2], ';');
        for (auto player : Defender_players)
        {
            // string name = player;
            vector<string> temp = split(player, ':');
            string name = temp[0];
            
            //check .....................................................
            double price = stod(temp[1].erase(temp[1].find('$'), 1));


            Player* new_player = new DefenderPlayer(name, DEFULT_SCORE, DEFENDER);
            new_player->set_player_price(price);
            playerTemp.push_back(new_player);
            this->players.push_back(new_player);
        }

        vector<string> Midfielder_players = split(splitted_line_team[3], ';');
        for (auto player : Midfielder_players)
        {
            // string name = player;
            vector<string> temp = split(player, ':');
            string name = temp[0];

            //check .....................................................
            double price = stod(temp[1].erase(temp[1].find('$'), 1));


            Player* new_player = new MidfielderPlayer(name, DEFULT_SCORE, MIDFIELDER);
            new_player->set_player_price(price);
            playerTemp.push_back(new_player);
            this->players.push_back(new_player);
        }

        vector<string> Forward_players = split(splitted_line_team[4], ';');
        for (auto player : Forward_players)
        {
            // string name = player;
            vector<string> temp = split(player, ':');
            string name = temp[0];

            //check .....................................................
            double price = stod(temp[1].erase(temp[1].find('$'), 1));


            Player* new_player = new ForwardPlayer(name, DEFULT_SCORE, FORWARD);
            new_player->set_player_price(price);
            playerTemp.push_back(new_player);
            this->players.push_back(new_player);
        }

        main_teams.push_back(new MainTeam(team_name, playerTemp));

        

    }
    
}


//need to be completed
//
//
//
//
//
//need to be completed ---------------------------------------
void System::init_weeks()
{
    for (int i = 0; i < 19; i++)
    {
        string week_file_path = WEEKS_FILE_PATH + to_string(i + 1) + ".csv";
        ifstream file;
        file.open(week_file_path);
        if(!file.is_open())
        {
            cout << "file not found" << endl;
            exit(1);
        }

        string line;
        //for each line
        // vector<pair<Player*,double>> scores ;
        vector< pair< vector<pair<string,double>> , vector<pair<string,double>> > > players_of_team ;
        vector<vector<pair<string ,string>>> goal_with_assist ;

        // vector<pair<string,double>> team1;
        // vector<pair<string,double>> team2;

        vector<string> yellow_card;
        vector<string> red_card;
        vector<string> injure;
        vector<Match*> match;
        getline(file, line);
        //for first line


        while (getline(file, line))
        {
            line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());

            vector<string> splitted_line = split(line, ',');
            vector<string> team_names_temp = split(splitted_line[0], ':');
            vector<string> result_temp = split(splitted_line[1], ':');
            Match *match_temp = new Match(find_team(team_names_temp[0]), find_team(team_names_temp[1]), stoi(result_temp[0]), stoi(result_temp[1]));
            match.push_back(match_temp);
            vector<string> yellow_card_temp = split(splitted_line[3], ';');
            vector<string> red_card_temp = split(splitted_line[4], ';');
            vector<string> injure_temp = split(splitted_line[2], ';');
            vector<string> goal_with_assist_temp = split(splitted_line[5], ';');
            vector<string> team1_temp = split(splitted_line[6], ';');
            vector<string> team2_temp = split(splitted_line[7], ';');
            vector<pair<string,string>> goal_assist = {};

            for(auto player : goal_with_assist_temp)
            {
                vector<string> goal_with_assist_temp2 = split(player, ':');
                pair<string,string> pair_temp = make_pair(goal_with_assist_temp2[0],goal_with_assist_temp2[1]);
                goal_assist.push_back(pair_temp);
            }
            goal_with_assist.push_back(goal_assist);


            vector<pair<string,double>> team1;
            for(auto player : team1_temp)
            {
                ///////////////////////////////////////////////////////////////// need to be correct ///////////////////////////////////////////////////
                pair<string,double> pair_temp = make_pair(player,DEFULT_SCORE);
                team1.push_back(pair_temp);
            }
            vector<pair<string,double>> team2;
            for(auto player : team2_temp)
            {
                ///////////////////////////////////////////////////////////////// need to be correct ///////////////////////////////////////////////////
                pair<string,double> pair_temp = make_pair(player,DEFULT_SCORE);
                team2.push_back(pair_temp);
            }
            
            players_of_team.push_back(make_pair(team1,team2));


            
            yellow_card.insert(yellow_card.end(), yellow_card_temp.begin(), yellow_card_temp.end());
            red_card.insert(red_card.end(), red_card_temp.begin(), red_card_temp.end());
            injure.insert(injure.end(), injure_temp.begin(), injure_temp.end());
        }
        weeks.push_back(new Week(i+1,goal_with_assist ,players_of_team ,match, yellow_card, red_card, injure));
    }
}


MainTeam* System::find_team(string team_name)
{
    for(auto team : this->main_teams)
    {
        if(team->get_team_name() == team_name)
        {
            return team;
        }
    }
    return nullptr;
}


Player* System::find_player(string player_name)
{
    for(auto player : this->players)
    {
        if(player->get_name() == player_name)
        {
            return player;
        }
    }
    return nullptr;
}

void System::signup(const string& user_name, const string& password)
{
    if(is_admin_login || current_user != nullptr)
    {
        throw Bad_request();
    }
    
    if(is_user_exist(user_name))
    {
        throw Bad_request();
    }
    FantasyTeam* new_fantasy_team = new FantasyTeam(user_name);
    fantasy_teams.push_back(new_fantasy_team);
    
    User* new_user = new User(user_name, password , new_fantasy_team);
    this->users.push_back(new_user);
    current_user = new_user;
}

User* System::find_user(string user_name)
{
    for(auto user : this->users)
    {
        if(user->get_user_name() == user_name)
        {
            return user;
        }
    }
    return nullptr;
}

bool System::is_user_exist(string user_name)
{
    for(auto user : this->users)
    {
        if(user->get_user_name() == user_name)
        {
            return true;
        }
    }
    return false;
}

void System::login(const string& user_name, const string& password)
{
    // ??????????????
    if(this->current_user != nullptr || is_admin_login)
    {
        throw Bad_request();
    }
    // ??????????????

    User* user = find_user(user_name);
    if(user == nullptr)
    {
        throw Bad_request();
    }
    if(user->get_password() != password)
    {
        throw Bad_request();
    }

    this->current_user = user;
}

void System::logout()
{
    if(this->current_user == nullptr && !is_admin_login)
    {
        throw Bad_request();
    }
    this->current_user = nullptr;
    if (is_admin_login)
    {
        is_admin_login = false;
    }
}

void System::login_admin(const string& _password)
{
    if(this->current_user != nullptr)
    {
        throw Bad_request();
    }
    if(!admin->check_password(_password))
    {
        throw Bad_request();
    }
    this->is_admin_login = true;

}

void System::update_week()
{
    for(auto player : players)
    {
        player->set_score(0);
    }
    
    weeks[week_number-1]->update_players();

    for(auto player : players)
    {
        player->update_can_be_sold(week_number);
    }
    for(auto FantasyTeam : fantasy_teams)
    {
        FantasyTeam->update_score();
    }

}


void System::cloes_transfare_window()
{
    if(!is_admin_login)
        throw Bad_request();
    admin->set_transfer_window_status(Teansfare_window_status::CLOSED);
}


void System::open_transfare_window()
{
    if(!is_admin_login)
        throw Bad_request();
    admin->set_transfer_window_status(Teansfare_window_status::CLOSED);
}

void System::pass_week()
{
    if(!is_admin_login)
        throw Bad_request();
    week_number++;

    update_week();

}

void System::buy_player(const string& player_name)
{
    if(current_user == nullptr)
        throw Bad_request();
    Player* player = find_player(player_name);
    if(player == nullptr)
        // cout << "jjj" << endl;
        // cout << ",,,," << endl;
        throw Not_Found();
    current_user->get_fantasy_team()->add_player(player,transfare_state, week_number);
}

void System::sell_player(const string& player_name)
{
    if(current_user == nullptr)
        throw Bad_request();
    // Player* player = find_player(player_name);
    // if(player == nullptr)
    //     throw Not_Found();
    current_user->get_fantasy_team()->sell_player(player_name,transfare_state, week_number);
}

void System::print_team_of_week(int _week_number)
{

    // if(!is_admin_login)
    //     throw Bad_request();

    if(_week_number == EMPTY_NUMBER)
        _week_number = week_number +1;

    if(_week_number < 1 || _week_number > 19)
        throw Bad_request();
    
    vector< pair<Player*,double> > best_players = weeks[_week_number-1]->get_best_team_week();
    
    cout << "team of the week:" << endl ;
    cout << "GoalKeeper: " << best_players[0].first->get_name() << " | " << "score: " << best_players[0].second<< endl;
    cout << "Defender 1: " << best_players[1].first->get_name() << " | " << "score: " << best_players[1].second<< endl;
    cout << "Defender 2: " << best_players[2].first->get_name() << " | " << "score: " << best_players[2].second<< endl;
    cout << "Midfielder: " << best_players[3].first->get_name() << " | " << "score: " << best_players[3].second<< endl;
    cout << "Forward: " << best_players[4].first->get_name() << " | " << "score: " << best_players[4].second<< endl;
}

FantasyTeam* System::find_fantasy_team(string team_name)
{
    for(auto team : fantasy_teams)
    {
        if(team->get_name() == team_name)
        {
            return team;
        }
    }
    return nullptr;
}

void System::print_fantasy_team(string team_name = "")
{
    if(team_name == "")
    {
        if(current_user == nullptr)
            throw Permission_denied();
        team_name = current_user->get_fantasy_team()->get_name();
    }
    FantasyTeam* fantasy_team = find_fantasy_team(team_name);
    if(current_user == nullptr)
        throw Permission_denied();
    if(fantasy_team == nullptr)
        throw Not_Found();
    if(fantasy_team->is_full() == false)
        throw Empty();
    vector<Player*> players = fantasy_team->get_fantasy_team_players();
    cout << "Fantasy Team: " << team_name << endl;
    // cout << "GoalKeeper: " << players[0]->get_name() << endl;
    // cout << "Defender 1: " << players[1]->get_name() << endl;
    // cout << "Defender 2: " << players[2]->get_name() << endl;
    // cout << "Midfielder: " << players[3]->get_name() << endl;
    // cout << "Striker: " << players[4]->get_name() << endl;


    /////////////////////////////////// need to be deleted /////////////////////////////////////////
    cout << "GoalKeeper: " << players[0]->get_name() << " " << endl;
    cout << "Defender 1: " << players[1]->get_name() << " " << endl;
    cout << "Defender 2: " << players[2]->get_name() << " " << endl;
    cout << "Midfielder: " << players[3]->get_name() << " " << endl;
    cout << "Striker: " << players[4]->get_name() << " " << endl;
    /////////////////////////////////// need to be deleted /////////////////////////////////////////

    cout << "Total score: " << fantasy_team->get_score() << endl;
}

void System::print_matches_result_league(int _week_number)
{
    vector<Match*> matches = weeks[_week_number-1]->get_matches();
    for(auto match : matches)
    {
        cout << match->get_team1()->get_team_name() << " " << match->get_result1() << " | " << match->get_team2()->get_team_name() << " " << match->get_result2() << endl;
    }
}

vector<User*> System::get_user_ranks()
{
    vector<User*> users = this->users;
    sort(users.begin(), users.end(), [](User* user1, User* user2){
        // return user1->get_fantasy_team()->get_score() > user2->get_fantasy_team()->get_score();
        if (user1->get_fantasy_team()->get_score() == user2->get_fantasy_team()->get_score())
        {
            return user1->get_user_name() < user2->get_user_name();
        }
        else
        {
            return user1->get_fantasy_team()->get_score() > user2->get_fantasy_team()->get_score();
        }
        
    });
    return users;
}

void System::print_users_ranking()
{
    vector<User*> users = get_user_ranks();
    for(int i = 0; i < users.size(); i++)
    {
        cout << i+1 << ". " << "team_name: " << users[i]->get_user_name() << " | " << users[i]->get_fantasy_team()->get_score() << endl;
    }
}

void System::print_main_team_players(string _team_name ,string _type = "" , bool rank = false)
{
    MainTeam* team = find_team(_team_name);
    if(team == nullptr)
    {
        throw Not_Found();
    }
    vector<Player*> players ;
    cout << "list of players: " << endl;
    if(_type == SUMMERIES_GOALKEEPER_INSTRUCTION)
    {
        players = team->get_goalkeeper_players(rank);
        for(auto player : players)
        {
            cout << "name: " << player->get_name() << " | " << "role:" << SUMMERIES_GOALKEEPER_INSTRUCTION << " | " << "score: " ;
            // printf("%.1f\n", player->get_average_score()) << pla;
            printf("%.1f", player->get_average_score()); 
            // cout<<   player->get_score();

            //downcast to GoalkeeperPlayer
            GoalkeeperPlayer* goalkeeper_player = dynamic_cast<GoalkeeperPlayer*>(player);
            cout << " | " << "clean sheets: " << goalkeeper_player->get_clean_sheet() << endl;





        }
    }
    else if(_type == SUMMERIES_DEFENDER_INSTRUCTION)
    {
        players = team->get_defender_players(rank);
        for(auto player : players)
        {
            cout << "name: " << player->get_name() << " | " << "role:" << SUMMERIES_DEFENDER_INSTRUCTION << " | " << "score: " ;
            printf("%.1f", player->get_average_score());
            // printf("%.1f", player->get_average_score());
            // cout << " " << player->get_score() << endl;

            // downcast to DefenderPlayer
            DefenderPlayer* defender_player = dynamic_cast<DefenderPlayer*>(player);
            cout << " | " << "goals: " << defender_player->get_goals() << " | " << "assists: " << defender_player->get_assists_goals() << " | " << "clean sheets: " << defender_player->get_clean_sheet() << endl;
        }
    }
    else if(_type == SUMMERIES_MIDFIELDER_INSTRUCTION)
    {
        players = team->get_midfielder_players(rank);
        for(auto player : players)
        {
            cout << "name: " << player->get_name() << " | " << "role:" << SUMMERIES_MIDFIELDER_INSTRUCTION << " | " << "score: " ;
            printf("%.1f", player->get_average_score());

            // downcast to MidfielderPlayer
            MidfielderPlayer* midfielder_player = dynamic_cast<MidfielderPlayer*>(player);
            cout << " | " << "goals: " << midfielder_player->get_goals() << " | " << "assists: " << midfielder_player->get_assists_goals() << " | " << "clean sheets: " << midfielder_player->get_clean_sheet() << endl;

        }
    }
    else if(_type == SUMMERIES_FORWARD_INSTRUCTION)
    {
        players = team->get_forward_players(rank);
        for(auto player : players)
        {
            cout << "name: " << player->get_name() << " | " << "role:" << SUMMERIES_FORWARD_INSTRUCTION << " | " << "score: " ;
            printf("%.1f", player->get_average_score());

            // downcast to ForwardPlayer
            ForwardPlayer* forward_player = dynamic_cast<ForwardPlayer*>(player);
            cout << " | " << "goals: " << forward_player->get_goals() << " | " << "assists: " << forward_player->get_assists_goals() << endl;

        }
    }
    else if (_type == "")
    {
        players = team->get_players(rank);
        
        for(auto player : players)
        {
            cout << "name: " << player->get_name() << " | " << "role:" << player->get_player_role() << " | " << "score: " ;
            printf("%.1f\n", player->get_average_score());
            // cout << player->get_score() << endl;
        }
    }
}

void System::print_league_standings()
{
    vector<MainTeam*> teams = this->main_teams;
    sort(teams.begin(), teams.end(), [](MainTeam* team1, MainTeam* team2){
        // return team1->get_score() > team2->get_score;
        if(team1->get_score() > team2->get_score())
            return true;
        else if(team1->get_score() == team2->get_score())
        {
            if(team1->get_goal_difference() > team2->get_goal_difference())
                return true;
            else if(team1->get_goal_difference() == team2->get_goal_difference())
            {
                if(team1->get_goal_for() > team2->get_goal_for())
                    return true;
                else if(team1->get_goal_for() == team2->get_goal_for())
                {
                    if(team1->get_team_name() < team2->get_team_name())
                        return true;
                    else
                        return false;
                }
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
    });
    for(int i = 0; i < teams.size(); i++)
    {
        cout << i+1 << ". " << teams[i]->get_team_name() << ": " << "score: " << teams[i]->get_score() << " | " << "GF: " << teams[i]->get_goal_for() << " | " << "GA: " << teams[i]->get_goal_against() << endl;
    }
}


/// @brief /////////////////////////////////  CLEAN  //////////////////////////////////////
void System::print_week_1()
{
    weeks[0]->print_week();
}

void System::print_players()
{
    for(auto player : players)
    {
        cout << player->get_name() << " " << player->get_score() << "\n";
    }
}

void System::show_price(string player_name)
{
    Player* player = find_player(player_name);
    if(player == nullptr)
        throw Not_Found();
    cout << player->get_player_price() << endl;
}