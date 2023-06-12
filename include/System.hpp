#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>
#include <regex>
#include "Consts.hpp"
#include "../include/User.hpp"
#include "../include/MainTeam.hpp"
#include "../include/Player.hpp"
#include "../include/Admin.hpp"
#include "../include/Week.hpp"
#include "../include/FantasyTeam.hpp"
// #include "../include/Exeptions.hpp"

using namespace std;
const double DEFULT_SCORE = 0 ;

class System
{
public:
    System();
    ~System();
    void update_week();
    void signup(const string& user_name, const string& password);
    void login(const string& user_name, const string& password);
    void login_admin(const string& _password);
    void logout();
    void open_transfare_window();
    void cloes_transfare_window();
    void pass_week();
    void buy_player(const string& player_name);
    void sell_player(const string& player_name);
    void print_team_of_week(int week_number);
    void print_fantasy_team(string team_name);
    void print_matches_result_league(int _week_number);
    void print_users_ranking();
    void print_main_team_players(string team_name ,string type ,bool rank);
    void print_league_standings();
    void show_price(string player_name);
    void set_capitan(string player_name);
    void print_week_1();
    void print_players();
    void show_budget();

private:
    void init_main_teams();
    void init_weeks();
    Player* find_player(string player_name);
    vector<string> split(const string& str, char delim);
    User* find_user(string user_name);
    bool is_user_exist(string user_name);
    MainTeam* find_team(string team_name);
    FantasyTeam* find_fantasy_team(string team_name);
    vector<User*> get_user_ranks();
    double get_total_cost_of_fantasy_team(FantasyTeam* fantasy_team);


    vector<User*> users;
    vector<MainTeam*> main_teams;
    vector<Player*> players;
    vector<Week*> weeks;
    vector<FantasyTeam*> fantasy_teams;
    Admin* admin;
    int week_number = DEFULT_WEEK_NUMBER;
    enum Teansfare_window_status transfare_state = OPEN;
    User* current_user;
    bool is_admin_login = false;
    
};