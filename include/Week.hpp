#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string>
#include "Consts.hpp"
#include "../include/Player.hpp"
#include "../include/MainTeam.hpp"
#include "../include/Admin.hpp"
#include "../include/Match.hpp"
#include "../include/GoalkeeperPlayer.hpp"
#include "../include/DefenderPlayer.hpp"
#include "../include/MidfielderPlayer.hpp"
#include "../include/ForwardPlayer.hpp"



using namespace std;

class Week
{
public:
    Week(int week_number ,vector<vector<pair<string,string>>> goal_with_assist , vector< pair< vector<pair<string,double>> , vector<pair<string,double>> > > players_of_team , vector<Match*> matches , vector<string> Red_cards , vector<string> Yellow_cards , vector<string> injured_players);

    void add_match(MainTeam* team1, MainTeam* team2 , int result1 , int result2);
    vector<Match*> get_matches(){return matches;}
    vector<string> get_Red_cards(){return Red_cards;}
    vector<string> get_Yellow_cards(){return Yellow_cards;}
    vector<string> get_injured_players(){return injured_players;}
    Player* find_player(string player_name);
    void update_players();
    // void print_week();
    vector< pair<Player*,double> > get_best_team_week();
    void update_type_players();
    void update_scores();
    void update_matchs();
    double score_calculator(double x);
    int number_of_goal(string player_name , int row_number);
    int number_of_assist(string player_nam , int row_number);
    bool is_OWN_GOAL(string player_name , int row_number);
    int number_of_goal_total(string player_name);
    int number_of_assist_total(string player_name);
    void set_all_players(vector<Player*> players);



    // need to be deleted
    void print_week();
    void print_goal_with_assist();

private:
    int week_number;
    vector<Match*> matches;





    //need to be deleted
    // vector< pair<Player*,double> > scores;

    vector <Player* > All_playyers;





    vector<string> Red_cards;
    vector<string> Yellow_cards;
    vector<string> injured_players;

    vector <vector<pair<string,string>>> goal_with_assist;
    vector <pair<vector<pair<string,double>>,vector<pair<string,double>>>> players_of_team;




    vector< pair<Player*,double> > defenders_players;
    vector< pair<Player*,double> > midfielders_players;
    vector< pair<Player*,double> > forwards_players;
    vector< pair<Player*,double> > goalkeepers_players;


};