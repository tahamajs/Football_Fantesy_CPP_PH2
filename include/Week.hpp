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


using namespace std;

class Week
{
public:
    Week(int week_number  , vector< pair<Player*,double>> scores , vector<Match*> matches , vector<string> Red_cards , vector<string> Yellow_cards , vector<string> injured_players);
    void add_match(MainTeam* team1, MainTeam* team2 , int result1 , int result2);
    vector<Match*> get_matches(){return matches;}
    vector< pair<Player*,double> > get_scores(){return scores;}
    vector<string> get_Red_cards(){return Red_cards;}
    vector<string> get_Yellow_cards(){return Yellow_cards;}
    vector<string> get_injured_players(){return injured_players;}
    Player* find_player(string player_name);
    void update_players();
    // void print_week();
    vector< pair<Player*,double> > get_best_team_week();
    void update_type_players();
    void update_matchs();



    // need to be deleted
    void print_week();

private:
    int week_number;
    vector<Match*> matches;
    vector< pair<Player*,double> > scores;
    vector<string> Red_cards;
    vector<string> Yellow_cards;
    vector<string> injured_players;

    vector< pair<Player*,double> > defenders_players;
    vector< pair<Player*,double> > midfielders_players;
    vector< pair<Player*,double> > forwards_players;
    vector< pair<Player*,double> > goalkeepers_players;


};