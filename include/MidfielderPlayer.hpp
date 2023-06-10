#pragma once 
#include <string>
#include <vector>
#include "../include/Player.hpp"


class MidfielderPlayer : public Player
{
public:
    MidfielderPlayer(string name, double score , enum Player_type type) : Player(name, score, type){}
    ~MidfielderPlayer(){}

    void increase_goals(int _goals){ goals += _goals; }
    int get_goals(){ return goals; }
    void increase_assists_goals(int _assists_goals){ assists_goals += _assists_goals; }
    int get_assists_goals(){ return assists_goals; }
    void increase_clean_sheet(int _clean_sheet){ clean_sheet += _clean_sheet; }
    int get_clean_sheet(){ return clean_sheet; }

    void set_player_position(enum Midfielder_position _position){ position = _position; }
    enum Midfielder_position get_player_position(){ return position; }



private:
    int goals = 0;
    int assists_goals = 0;
    int clean_sheet = 0;
    enum Midfielder_position position ;
};