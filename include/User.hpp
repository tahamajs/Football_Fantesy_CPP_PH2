#pragma once 
#include <string>
#include "../include/FantasyTeam.hpp"

using namespace std;

class User
{
public:
    User(string Team_name, string password , FantasyTeam* fantasy_team);
    string get_user_name(){return user_name;}
    string get_password(){return password;}
    FantasyTeam* get_fantasy_team(){return fantasy_team;}
    bool check_password(string _password);
    
private:
    string user_name;
    string password;
    FantasyTeam* fantasy_team;
}; 