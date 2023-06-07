#pragma once
#include <iostream>
#include <string>
#include "../include/Player.hpp"
#include "../include/Exeptions.hpp"
#include "../include/Consts.hpp"

using namespace std;

class FantasyTeam
{
public:
    FantasyTeam(string name);
    string get_name(){return team_name;}
    void sell_player(string player_name , Teansfare_window_status tws , int week_number);
    void add_player(Player* player , Teansfare_window_status tws , int week_number);
    int get_number_of_player(){return number_of_player;}
    void update_score();
    bool is_full(){return number_of_player == 5;}
    vector<Player*> get_fantasy_team_players();
    double get_score(){return score;}
    int get_price(){return price;}
    void set_capitan(Player* player);

private:
    string team_name;
    double score = 0;
    Player* Forward_player;
    Player* Midfielder_player;
    Player* Defender_1_player;
    Player* Defender_2_player;
    Player* Goalkeeper_player;
    Player* Captain_player;
    int number_of_player = 0;
    bool is_full_yet = false;

    bool is_in_team(Player* player);

    int price = DEFULT_FANTASY_TEAM_PRICE;

    int sell_count_week[NUMBER_OF_WEEK] = {};
    int add_count_week[NUMBER_OF_WEEK] = {};
    

    
};