#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "../include/Player.hpp"

using namespace std;

const int ZERO = 0;

class MainTeam
{
public:
    MainTeam(string _name, vector<Player *> _players);
    string get_team_name() { return team_name; }
    void update_team_type_vectors();
    vector<Player *> get_players(bool rank);
    vector<Player *> get_goalkeeper_players(bool rank);
    vector<Player *> get_defender_players(bool rank);
    vector<Player *> get_midfielder_players(bool rank);
    vector<Player *> get_forward_players(bool rank);
    int get_score() { return score; }
    void increase_goal_for(int number) { goal_for += number; }
    void increase_goal_against(int number) { goal_against += number; }
    void increase_win_score() { score += WIN_SCORE; }
    void increase_draw_score() { score += DRAW_SCORE; }
    void increase_lose_score() { score += LOSE_SCORE; }
    int get_goal_difference() { return goal_for - goal_against; }
    int get_goal_for() { return goal_for; }
    int get_goal_against() { return goal_against; }

    // need to be deleted
    void print_team();

private:
    string team_name;
    int score = ZERO;
    int goal_for = ZERO;
    int goal_against = ZERO;

    vector<Player *> players;
    vector<Player *> goalkeeper_players;
    vector<Player *> defender_players;
    vector<Player *> midfielder_players;
    vector<Player *> forward_players;
};
