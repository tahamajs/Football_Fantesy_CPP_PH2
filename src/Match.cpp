#include "../include/Match.hpp"

Match::Match(MainTeam* team1, MainTeam* team2 , int result1 , int result2)
{
    this->teams.first = team1;
    this->teams.second = team2;
    this->result.first = result1;
    this->result.second = result2;
}

void Match::print_match()
{
    cout << this->teams.first->get_team_name() << " " << this->result.first << " - " << this->result.second << " " << this->teams.second->get_team_name() << endl;
}

void Match::update_match()
{
    this->teams.first->increase_goal_for(this->result.first);
    this->teams.first->increase_goal_against(this->result.second);
    this->teams.second->increase_goal_for(this->result.second);
    this->teams.second->increase_goal_against(this->result.first);
    if(this->result.first > this->result.second)
    {
        this->teams.first->increase_win_score();
        this->teams.second->increase_lose_score();
    }
    else if(this->result.first < this->result.second)
    {
        this->teams.first->increase_lose_score();
        this->teams.second->increase_win_score();
    }
    else
    {
        this->teams.first->increase_draw_score();
        this->teams.second->increase_draw_score();
    }
}