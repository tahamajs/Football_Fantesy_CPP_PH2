#pragma once 
#include <string>

using namespace std;
enum Player_type
{
    GOALKEEPER,
    DEFENDER,
    MIDFIELDER,
    FORWARD
};

enum Teansfare_window_status
{
    OPEN,
    CLOSED
};


const string PREMIER_LEAGUE_FILE_PATH = "./data/premier_league.csv" ;
const string WEEKS_FILE_PATH = "./data/weeks_stats/week_";

const int NUMBER_OF_WEEK = 19;


const string SUMMERIES_GOALKEEPER_INSTRUCTION = "gk";
const string SUMMERIES_DEFENDER_INSTRUCTION = "df";
const string SUMMERIES_MIDFIELDER_INSTRUCTION = "mf";
const string SUMMERIES_FORWARD_INSTRUCTION = "fw";

const vector<string> SUMMERIES_INSTRUCTIONS = {SUMMERIES_GOALKEEPER_INSTRUCTION, SUMMERIES_DEFENDER_INSTRUCTION, SUMMERIES_MIDFIELDER_INSTRUCTION, SUMMERIES_FORWARD_INSTRUCTION};

const string RANK_INSTRUCTION = "rank";

const int DEFULT_WEEK_NUMBER = 0;


const int MAX_SELL_IN_WEEK = 2;
const int MAX_BUY_IN_WEEK = 1;

const int WIN_SCORE = 3;
const int DRAW_SCORE = 1;
const int LOSE_SCORE = 0;

const int EMPTY_NUMBER = -1;
const string EMPTY_STRING = "";


const string DEFULT_ADMIN_USERNAME = "admin";

const int DEFULT_FANTASY_TEAM_PRICE = 2500;
const int DEFULT_PLAYER_PRICE = 0;