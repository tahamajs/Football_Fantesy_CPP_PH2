#pragma once 
#include <string>
#include <vector>
#include "../include/Player.hpp"


class GoalkeeperPlayer : public Player
{
public:
    void increase_clean_sheet(int _clean_sheet){ clean_sheet += _clean_sheet; }
    int get_clean_sheet(){ return clean_sheet; }




    void increase_goals(int _goals){ }
    void increase_assists_goals(int _assists_goals){ }


    
private:
    int clean_sheet = 0;
    
};