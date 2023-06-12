#include "../include/User.hpp"
// Path: phase_1/src/User.cpp

User::User(string _name, string _password, FantasyTeam *_fantasy_team)
{
    this->user_name = _name;
    this->password = _password;
    this->fantasy_team = _fantasy_team;
}

bool User::check_password(string _password)
{
    return this->password == _password;
}
