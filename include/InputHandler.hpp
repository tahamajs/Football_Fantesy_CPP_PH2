#pragma once
#include "../include/Consts.hpp"
#include "../include/System.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>

using namespace std;
const string REQUEST_GET = "GET";
const string REQUEST_POST = "POST";
const string REQUEST_DELETE = "DELETE";
const string REQUEST_PUT = "PUT";
const string COMMAND_DELIMITER = "?";

const string SUCCESSFUL_MASSAGE = "OK";

const string SIGNUP = "signup";
const string LOGIN = "login";
const string LOGOUT = "logout";
const string TEAM_OF_THE_WEEK = "team_of_the_week";
const string PLAYERS = "players";
const string LEAGUE_STANDING = "league_standings";
const string USER_RANKING = "users_ranking";
const string SHOW_MATCH_RESULT = "matches_result_league";
const string LOGIN_ADMIN = "register_admin";
const string SELL_PLAYER = "sell_player";
const string BUY_PLAYER = "buy_player";
const string SHOW_FANTASY_TEAM = "squad";
const string CLOSE_TRANSFARE_WINDOW = "close_transfer_window";
const string OPEN_TRANSFARE_WINDOW = "open_transfer_window";
const string PASS_WEEK = "pass_week";

const string TEAM_NAME = "team_name";
const string PASSWORD = "password";
const string USERNAME = "username";
const string NAME = "name";
const string FANTASY_TEAM = "fantasy_team";
const string WEEK_NUM = "week_num";
const string WEEK = "week";

class InputHandler
{
public:
    InputHandler();
    void run();

private:

    System *system;
    stringstream command_line;

    void signup();
    void login();
    void logout();

    void handle_command();
    bool cmnd_dlmtr_check();
    void print_team_of_the_week();
    void sell_player();
    void buy_player();
    void show_fantasy_team();
    void close_transfer_window();
    void open_transfer_window();
    void pass_week();
    void login_admin();
    void show_players();
    void show_league_standings();
    void show_users_ranking();
    void show_match_result();
    bool check_reapeted_input_type(const vector<string> &inputs_type);
    bool cmnd_end_check();
    bool has_empty_field(const vector<string> &inputs, const vector<string> &needed_inputs);
    void print_successfull_massage();
    int count_of_input_word();
    void replaceUnderscoresWithSpaces(std::string& str);


    const vector<string> signup_field = {USERNAME, PASSWORD};
    const vector<string> login_field = {USERNAME, PASSWORD};
    const vector<string> show_players_fiels = {TEAM_NAME};
    const vector<string> sell_player_fiels = {NAME};
    const vector<string> buy_player_fiels = {NAME};
    

    typedef void (InputHandler::*call_func_ptr)();
    const unordered_map<string, call_func_ptr> POST_commands =
    {
        {SIGNUP, &InputHandler::signup},
        {LOGIN, &InputHandler::login},
        {LOGOUT, &InputHandler::logout},
        {SELL_PLAYER, &InputHandler::sell_player},
        {BUY_PLAYER, &InputHandler::buy_player},
        {CLOSE_TRANSFARE_WINDOW, &InputHandler::close_transfer_window},
        {OPEN_TRANSFARE_WINDOW, &InputHandler::open_transfer_window},
        {PASS_WEEK, &InputHandler::pass_week},
        {LOGIN_ADMIN, &InputHandler::login_admin}
    };

    const unordered_map<string, call_func_ptr> GET_commands =
    {
        {TEAM_OF_THE_WEEK, &InputHandler::print_team_of_the_week},
        {PLAYERS, &InputHandler::show_players},
        {LEAGUE_STANDING, &InputHandler::show_league_standings},
        {USER_RANKING, &InputHandler::show_users_ranking},
        {SHOW_MATCH_RESULT, &InputHandler::show_match_result},
        {SHOW_FANTASY_TEAM, &InputHandler::show_fantasy_team}
    };
};