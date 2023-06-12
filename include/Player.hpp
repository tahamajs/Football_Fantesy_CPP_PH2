#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string>
#include "Consts.hpp"
using namespace std;

const int DEFULT_LAST_WEEK = -10;
const int MAX_COUNT_OF_YELLOW_CARD = 3;

class Player
{
public:
    Player(string name, double score, enum Player_type type);
    virtual ~Player(){};

    double get_score() { return score; }
    const string &get_name() { return name; }
    enum Player_type get_type() { return type; }
    bool get_can_be_sold(int week_number);
    void set_score(double _score) { score = _score; }
    void set_last_week_red_card(int _last_week_red_card) { last_week_red_card = _last_week_red_card; }
    void set_last_week_injury(int _last_week_injury) { last_week_injury = _last_week_injury; }
    void increase_count_of_yellow_card();
    void update_can_be_sold(int week_number);
    string get_player_role();
    void increase_score(double score)
    {
        scores_of_weeks.push_back(score);
        count_of_week_played++;
    }
    double get_average_score();
    int get_player_price() { return player_price; }
    void set_player_price(int _player_price) { player_price = _player_price; }

    void virtual increase_goals(int _goals) = 0;
    void virtual increase_assists_goals(int _assists_goals) = 0;
    void virtual increase_clean_sheet(int _clean_sheet) = 0;

private:
    string name;
    double score = 0;
    int player_price = DEFULT_PLAYER_PRICE;
    enum Player_type type;
    bool can_be_sold = true;
    int last_week_red_card = DEFULT_LAST_WEEK;
    int count_of_yellow_card = 0;
    int last_week_injury = DEFULT_LAST_WEEK;
    int count_of_week_played = 0;
    vector<double> scores_of_weeks;
};
