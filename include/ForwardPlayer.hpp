#pragma once
#include <string>
#include <vector>
#include "../include/Player.hpp"

class ForwardPlayer : public Player
{
public:
    ForwardPlayer(string name, double score, enum Player_type type) : Player(name, score, type) {}
    ~ForwardPlayer() {}

    void increase_goals(int _goals) { goals += _goals; }
    int get_goals() { return goals; }
    void increase_assists_goals(int _assists_goals) { assists_goals += _assists_goals; }
    int get_assists_goals() { return assists_goals; }
    void increase_clean_sheet(int _clean_sheet) {}
    void set_player_position(enum Forward_position _position) { position = _position; }
    enum Forward_position get_player_position() { return position; }

private:
    int goals = DEFULT_GOAL;
    int assists_goals = DEFULT_GOAL;
    
    enum Forward_position position;





};