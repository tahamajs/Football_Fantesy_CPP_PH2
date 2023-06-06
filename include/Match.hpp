#pragma once 
#include <string>
#include <vector>
#include <sstream>
#include <string>
#include "Consts.hpp"
#include "../include/MainTeam.hpp"

using namespace std;

class Match
{
public:
    Match(MainTeam* team1, MainTeam* team2 , int result1 , int result2);
    pair<MainTeam* , MainTeam*> get_teams(){return teams;}
    pair<int,int> get_result(){return result;}
    MainTeam* get_team1(){return teams.first;}
    MainTeam* get_team2(){return teams.second;}
    int get_result1(){return result.first;}
    int get_result2(){return result.second;}
    void print_match();
    void update_match();
    
private:
    pair<MainTeam* , MainTeam*> teams;
    pair<int,int> result;
};