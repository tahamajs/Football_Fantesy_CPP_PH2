#pragma once 
#include <string>
#include <vector>
#include "../include/Player.hpp"


class MidfielderPlayer : public Player
{
public:

private:
    int goals = 0;
    int assists_goals = 0;
    int clean_sheet = 0;
};