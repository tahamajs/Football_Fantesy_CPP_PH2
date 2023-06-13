#include "../include/MainTeam.hpp"

bool cmp_player_rank(Player *player1, Player *player2)
{
    if (player1->get_average_score() == player2->get_average_score())
        return player1->get_name() < player2->get_name();
    return player1->get_average_score() > player2->get_average_score();
}

bool cmp_player_name(Player *player1, Player *player2)
{
    return player1->get_name() < player2->get_name();
}

MainTeam::MainTeam(string _name, vector<Player *> _players)
{
    this->team_name = _name;
    this->players = _players;
    update_team_type_vectors();
}

void MainTeam::update_team_type_vectors()
{
    for (auto player : this->players)
    {
        if (player->get_type() == GOALKEEPER)
            this->goalkeeper_players.push_back(player);
        else if (player->get_type() == DEFENDER)
            this->defender_players.push_back(player);
        else if (player->get_type() == MIDFIELDER)
            this->midfielder_players.push_back(player);
        else if (player->get_type() == FORWARD)
            this->forward_players.push_back(player);
    }
}

vector<Player *> MainTeam::get_players(bool rank)
{
    if (rank)
        sort(this->players.begin(), this->players.end(), cmp_player_rank);
    else
        sort(this->players.begin(), this->players.end(), cmp_player_name);
    return this->players;
}

vector<Player *> MainTeam::get_goalkeeper_players(bool rank)
{
    if (rank)
        sort(this->goalkeeper_players.begin(), this->goalkeeper_players.end(), cmp_player_rank);
    else
        sort(this->goalkeeper_players.begin(), this->goalkeeper_players.end(), cmp_player_name);
    return this->goalkeeper_players;
}

vector<Player *> MainTeam::get_defender_players(bool rank)
{
    if (rank)
        sort(this->defender_players.begin(), this->defender_players.end(), cmp_player_rank);
    else
        sort(this->defender_players.begin(), this->defender_players.end(), cmp_player_name);
    return this->defender_players;
}

vector<Player *> MainTeam::get_midfielder_players(bool rank)
{
    if (rank)
        sort(this->midfielder_players.begin(), this->midfielder_players.end(), cmp_player_rank);
    else
        sort(this->midfielder_players.begin(), this->midfielder_players.end(), cmp_player_name);
    return this->midfielder_players;
}

vector<Player *> MainTeam::get_forward_players(bool rank)
{
    if (rank)
        sort(this->forward_players.begin(), this->forward_players.end(), cmp_player_rank);
    else
        sort(this->forward_players.begin(), this->forward_players.end(), cmp_player_name);
    return this->forward_players;
}

// need to be deleted
void MainTeam::print_team()
{
    cout << this->team_name << endl;
    for (auto player : this->players)
        cout << player->get_name() << " " << player->get_score() << endl;
    cout << endl;
}
