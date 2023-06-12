#include "../include/Player.hpp"
// Path: phase_1/src/Player.cpp

Player::Player(string name, double score, enum Player_type type)
{
    this->name = name;
    this->score = score;
    this->type = type;
}

void Player::increase_count_of_yellow_card()
{
    count_of_yellow_card++;
    if (count_of_yellow_card > MAX_COUNT_OF_YELLOW_CARD)
    {
        last_week_red_card = 0;
    }
}

bool Player::get_can_be_sold(int week_number)
{
    if (last_week_red_card == week_number || count_of_yellow_card == MAX_COUNT_OF_YELLOW_CARD || ((week_number - last_week_injury) < 3 && (week_number - last_week_injury) >= 0))
    {
        return false;
    }
    return true;
}

void Player::update_can_be_sold(int week_number)
{
    if (last_week_red_card == week_number || count_of_yellow_card == MAX_COUNT_OF_YELLOW_CARD || ((week_number - last_week_injury) < 3 && (week_number - last_week_injury) >= 0))
    {
        can_be_sold = false;
        score = 0;
        return;
    }
    can_be_sold = true;
}

string Player::get_player_role()
{
    if (type == DEFENDER)
    {
        return SUMMERIES_DEFENDER_INSTRUCTION;
    }
    else if (type == GOALKEEPER)
    {
        return SUMMERIES_GOALKEEPER_INSTRUCTION;
    }
    else if (type == MIDFIELDER)
    {
        return SUMMERIES_MIDFIELDER_INSTRUCTION;
    }
    else if (type == FORWARD)
    {
        return SUMMERIES_FORWARD_INSTRUCTION;
    }
}

double Player::get_average_score()
{
    double sum = 0;
    if (scores_of_weeks.size() == 0)
    {
        return 0;
    }
    for (auto score : scores_of_weeks)
    {
        sum += score;
    }
    return sum / double(scores_of_weeks.size());
}