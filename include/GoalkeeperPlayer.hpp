#pragma once
#include <string>
#include <vector>
#include "../include/Player.hpp"

class GoalkeeperPlayer : public Player
{
public:
    GoalkeeperPlayer(string name, double score, enum Player_type type) : Player(name, score, type) {}
    ~GoalkeeperPlayer() {}

    void increase_clean_sheet(int _clean_sheet) { clean_sheet += _clean_sheet; }
    int get_clean_sheet() { return clean_sheet; }
    void increase_goals(int _goals) {}
    void increase_assists_goals(int _assists_goals) {}

private:
    int clean_sheet = DEFULT_GOAL;
};