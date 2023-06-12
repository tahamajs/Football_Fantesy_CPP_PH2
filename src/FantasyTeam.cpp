#include "../include/FantasyTeam.hpp"
// Path: phase_1/src/FantasyTeam.cpp

FantasyTeam::FantasyTeam(string _name)
{
    this->team_name = _name;
}

void FantasyTeam::add_player(Player *player, Teansfare_window_status tws, int week_number)
{
    if (tws == CLOSED)
    {
        throw Permission_denied();
    }
    if(is_full_yet)
    {
        if ( add_count_week[week_number] >= MAX_BUY_IN_WEEK)
        {
            throw Permission_denied();
        }
    }
    
    if (!player->get_can_be_sold(week_number))
    {
        throw Player_not_available();
    }

    if(!check_price(player))
    {
        throw Bad_request();
    }

    if (player->get_type() == FORWARD && tws == OPEN)
    {
        if (Forward_player == NULL)
        {
            Forward_player = player;
            add_count_week[week_number]++;
            number_of_player++;
            price -= player->get_player_price();
        }
        else
        {
            throw Bad_request();
        }
    }
    else if (player->get_type() == MIDFIELDER && tws == OPEN)
    {
        if (Midfielder_player == NULL)
        {
            Midfielder_player = player;
            add_count_week[week_number]++;
            number_of_player++;
            price -= player->get_player_price();
        }
        else
        {
            throw Bad_request();
        }
    }
    else if (player->get_type() == DEFENDER && tws == OPEN)
    {
        if (Defender_1_player == NULL)
        {
            Defender_1_player = player;
            add_count_week[week_number]++;
            number_of_player++;
            price -= player->get_player_price();
        }
        else if (Defender_2_player == NULL)
        {
            Defender_2_player = player;
            add_count_week[week_number]++;
            number_of_player++;
            price -= player->get_player_price();
        }
        else
        {
            throw Bad_request();
        }
    }
    else if (player->get_type() == GOALKEEPER && tws == OPEN)
    {
        if (Goalkeeper_player == NULL)
        {
            Goalkeeper_player = player;
            add_count_week[week_number]++;
            number_of_player++;
            price -= player->get_player_price();
        }
        else
        {
            throw Bad_request();
        }
    }
}

void FantasyTeam::sell_player(string player_name, Teansfare_window_status tws, int week_number)
{
    if (tws == CLOSED)
    {
        throw Permission_denied();
    }
    if(is_full_yet)
    {
        if ( sell_count_week[week_number] >= MAX_SELL_IN_WEEK)
        {
            throw Permission_denied();
        }
    }

    if (Forward_player != NULL && Forward_player->get_name() == player_name)
    {
        Forward_player = NULL;
        sell_count_week[week_number]++;
        number_of_player--;
    }
    else if (Midfielder_player != NULL && Midfielder_player->get_name() == player_name)
    {
        Midfielder_player = NULL;
        sell_count_week[week_number]++;
        number_of_player--;
    }
    else if (Defender_1_player != NULL && Defender_1_player->get_name() == player_name)
    {
        Defender_1_player = NULL;
        sell_count_week[week_number]++;
        number_of_player--;
    }
    else if (Defender_2_player != NULL && Defender_2_player->get_name() == player_name)
    {
        Defender_2_player = NULL;
        sell_count_week[week_number]++;
        number_of_player--;
    }
    else if (Goalkeeper_player != NULL && Goalkeeper_player->get_name() == player_name)
    {
        Goalkeeper_player = NULL;
        sell_count_week[week_number]++;
        number_of_player--;
    }
    else
    {
        //
        throw Not_Found();
    }
}

void FantasyTeam::update_score()
{
    if(number_of_player != 5)
    {
        return;
    }

    // score = 0;
    if (!is_full_yet && number_of_player == 5)
    {
        is_full_yet = true;
    }


    if (Forward_player != NULL)
    {
        score += Forward_player->get_score();
    }
    if (Midfielder_player != NULL)
    {
        score += Midfielder_player->get_score();
    }
    if (Defender_1_player != NULL)
    {
        score += Defender_1_player->get_score();
    }
    if (Defender_2_player != NULL)
    {
        score += Defender_2_player->get_score();
    }
    if (Goalkeeper_player != NULL)
    {
        score += Goalkeeper_player->get_score();
    }
    if(Captain_player != NULL)
    {
        score += Captain_player->get_score();
    }
}

vector<Player *> FantasyTeam::get_fantasy_team_players()
{
    vector<Player *> fantasy_team_players;

    fantasy_team_players.push_back(Goalkeeper_player);

    //need to check correctness
    if(Defender_1_player->get_name() < Defender_2_player->get_name())
    {
        fantasy_team_players.push_back(Defender_1_player);
        fantasy_team_players.push_back(Defender_2_player);
    }
    else
    {
        fantasy_team_players.push_back(Defender_2_player);
        fantasy_team_players.push_back(Defender_1_player);
    }

    fantasy_team_players.push_back(Midfielder_player);
    fantasy_team_players.push_back(Forward_player);




    return fantasy_team_players;
}

bool FantasyTeam::is_in_team(Player *player)
{
    if (Forward_player != NULL && Forward_player->get_name() == player->get_name())
    {
        return true;
    }
    else if (Midfielder_player != NULL && Midfielder_player->get_name() == player->get_name())
    {
        return true;
    }
    else if (Defender_1_player != NULL && Defender_1_player->get_name() == player->get_name())
    {
        return true;
    }
    else if (Defender_2_player != NULL && Defender_2_player->get_name() == player->get_name())
    {
        return true;
    }
    else if (Goalkeeper_player != NULL && Goalkeeper_player->get_name() == player->get_name())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void FantasyTeam::set_capitan(Player *player)
{
    if (is_in_team(player))
    {
        Captain_player = player;
    }
    else
    {
        throw Not_Found();
    }
}

bool FantasyTeam::check_price(Player *player)
{
    if (player->get_player_price() <= price)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool FantasyTeam::is_capitan(Player *player)
{
    if (Captain_player != NULL && Captain_player->get_name() == player->get_name())
    {
        return true;
    }
    else
    {
        return false;
    }
}