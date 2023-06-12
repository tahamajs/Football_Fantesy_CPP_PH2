#include "../include/InputHandler.hpp"
// Path: phase_1/src/InputHandler.cpp

InputHandler::InputHandler()
{
    system = new System();
}

void InputHandler::replaceUnderscoresWithSpaces(std::string &str)
{
    for (auto &c : str)
    {
        if (c == '_')
        {
            c = ' ';
        }
    }
}

void InputHandler::run()
{
    string command;
    string input_line;
    while (getline(cin, input_line))
    {
        try
        {
            command_line.clear();
            command_line.str(input_line);
            handle_command();
        }
        catch (const Bad_request &e)
        {
            cerr << e.what() << '\n';
        }
        catch (const Not_Found &e)
        {
            cerr << e.what() << '\n';
        }
        catch (const Permission_denied &e)
        {
            cerr << e.what() << '\n';
        }
        catch (const Empty &e)
        {
            cerr << e.what() << '\n';
        }
    }
}

bool InputHandler::check_reapeted_input_type(const vector<string> &inputs_type)
{
    int size_vec = inputs_type.size();
    for (int i = 0; i < size_vec - 1; i++)
    {
        for (int j = i + 1; j < size_vec; j++)
        {
            if (inputs_type[i] == inputs_type[j])
                return false;
        }
    }
    return true;
}

int InputHandler::count_of_input_word()
{
    string input_textline = command_line.str();
    istringstream input_text(input_textline);
    int count = 0;
    string word;

    while (input_text >> word)
    {
        count++;
    }

    return count;
}

bool InputHandler::cmnd_end_check()
{
    string end_input;
    command_line >> end_input;

    if (end_input.empty())
        return true;
    return false;
}

bool InputHandler::has_empty_field(const vector<string> &inputs, const vector<string> &needed_inputs)
{
    unordered_set<string> input_set(inputs.begin(), inputs.end());

    for (string s : needed_inputs)
    {
        if (input_set.find(s) == input_set.end())
            return true;
    }
    return false;
}

void InputHandler::print_successfull_massage()
{
    cout << SUCCESSFUL_MASSAGE << endl;
}

bool InputHandler::cmnd_dlmtr_check()
{
    string dlmtr;
    command_line >> dlmtr;
    if (dlmtr == "")
        return false;
    if (dlmtr != COMMAND_DELIMITER)
        throw Bad_request();
    return true;
}

void InputHandler::handle_command()
{
    string request;
    string command;
    command_line >> request;
    command_line >> command;

    if (request == REQUEST_GET)
    {
        auto it = GET_commands.find(command);
        if (it == GET_commands.end())
            throw Bad_request();
        (this->*(it->second))();
    }
    else if (request == REQUEST_POST)
    {
        auto it = POST_commands.find(command);
        if (it == POST_commands.end())
            throw Bad_request();
        (this->*(it->second))();
    }
    else if (request == REQUEST_PUT)
    {
    }
    else if (request == REQUEST_DELETE)
    {
    }
    else
    {
        throw Bad_request();
    }
}

void InputHandler::signup()
{
    string input;
    string username;
    string password;
    int count = count_of_input_word();

    // cout << count << endl;

    if (!cmnd_dlmtr_check())
        throw Bad_request();

    if (count != 7)
        throw Bad_request();
    command_line >> input;
    if (input != TEAM_NAME)
        throw Bad_request();
    command_line >> username;
    command_line >> input;
    if (input != PASSWORD)
        throw Bad_request();
    command_line >> password;

    //////////////////////////////////////////////  delete this part ///////////////////////////////////////////////////
    if (username == "" || password == "")
        throw Bad_request();
    //////////////////////////////////////////////  delete this part ///////////////////////////////////////////////////
    system->signup(username, password);
    print_successfull_massage();
}

void InputHandler::login()
{
    string input;
    string username;
    string password;

    int count = count_of_input_word();

    if (!cmnd_dlmtr_check())
        throw Bad_request();

    if (count != 7)
        throw Bad_request();
    command_line >> input;
    if (input != TEAM_NAME)
        throw Bad_request();

    command_line >> username;
    command_line >> input;

    if (input != PASSWORD)
        throw Bad_request();

    command_line >> password;

    //////////////////////////////////////////////  delete this part ///////////////////////////////////////////////////
    if (username == "" || password == "")
        throw Bad_request();
    //////////////////////////////////////////////  delete this part ///////////////////////////////////////////////////
    system->login(username, password);
    print_successfull_massage();
}

void InputHandler::logout()
{
    system->logout();
    print_successfull_massage();
}

void InputHandler::print_team_of_the_week()
{
    string input;
    int _week_number;

    if (!cmnd_dlmtr_check())
        throw Bad_request();

    int count = count_of_input_word();

    if (count == 3)
        system->print_team_of_week(EMPTY_NUMBER);
    else if (count == 5)
    {
        command_line >> input;
        if (input != WEEK_NUM)
            throw Bad_request();
        command_line >> _week_number;
        system->print_team_of_week(_week_number);
    }
    else
        throw Bad_request();

    print_successfull_massage();
}

void InputHandler::pass_week()
{
    int count = count_of_input_word();
    if (count != 2)
        throw Bad_request();
    system->pass_week();
    print_successfull_massage();
}

void InputHandler::buy_player()
{

    int count = count_of_input_word();
    string input;
    string player_name;

    if (!cmnd_dlmtr_check())
    {
        throw Bad_request();
    }

    command_line >> input;
    if (input != NAME)
        throw Bad_request();
    command_line >> std::ws;
    getline(command_line, player_name);
    system->buy_player(player_name);

    print_successfull_massage();
}

void InputHandler::sell_player()
{
    string input;
    string player_name;

    if (!cmnd_dlmtr_check())
        throw Bad_request();

    command_line >> input;
    if (input != NAME)
        throw Bad_request();

    command_line >> std::ws;
    getline(command_line, player_name);
    system->sell_player(player_name);

    print_successfull_massage();
}

void InputHandler::login_admin()
{
    int count = count_of_input_word();
    string input;
    string username;
    string password;

    if (!cmnd_dlmtr_check())
        throw Bad_request();

    if (count != 7)
    {
        throw Bad_request();
    }
    else
    {
        command_line >> input;
        if (input != USERNAME)
            throw Bad_request();
        command_line >> username;
        command_line >> input;
        if (input != PASSWORD)
            throw Bad_request();
        command_line >> password;

        if (username != DEFULT_ADMIN_USERNAME)
            throw Bad_request();

        system->login_admin(password);
        print_successfull_massage();
    }
}

void InputHandler::show_league_standings()
{
    system->print_league_standings();
}

void InputHandler::show_users_ranking()
{
    system->print_users_ranking();
}

void InputHandler::close_transfer_window()
{
    int count = count_of_input_word();
    if (count != 2)
        throw Bad_request();
    system->cloes_transfare_window();
    print_successfull_massage();
}

void InputHandler::show_fantasy_team()
{
    int count = count_of_input_word();
    string input;
    string team_name;

    if (!cmnd_dlmtr_check())
        throw Bad_request();

    if (count == 3)
        system->print_fantasy_team(EMPTY_STRING);
    else if (count == 5)
    {
        command_line >> input;
        if (input != FANTASY_TEAM)
            throw Bad_request();
        command_line >> team_name;
        system->print_fantasy_team(team_name);
    }
    else
        throw Bad_request();

    print_successfull_massage();
}

void InputHandler::open_transfer_window()
{
    int count = count_of_input_word();
    if (count != 2)
        throw Bad_request();
    system->open_transfare_window();
    print_successfull_massage();
}

void InputHandler::show_match_result()
{
    int count = count_of_input_word();
    string input;
    int week_number;

    if (!cmnd_dlmtr_check())
        throw Bad_request();

    if (count == 5)
    {
        command_line >> input;
        if (input != WEEK_NUM)
            throw Bad_request();
        command_line >> week_number;
        system->print_matches_result_league(week_number);
    }
    else
        throw Bad_request();
}

void InputHandler::show_players()
{
    int count = count_of_input_word();
    string input;
    string team_name;
    string role;
    if (!cmnd_dlmtr_check())
        throw Bad_request();

    if (count == 5)
    {
        command_line >> input;
        if (input != TEAM_NAME)
            throw Bad_request();
        command_line >> team_name;
        replaceUnderscoresWithSpaces(team_name);
        system->print_main_team_players(team_name, EMPTY_STRING, false);
        print_successfull_massage();
    }
    else if (count == 6)
    {
        command_line >> input;
        if (input != TEAM_NAME)
            throw Bad_request();
        command_line >> team_name;
        replaceUnderscoresWithSpaces(team_name);
        cout << team_name << endl;
        command_line >> input;
        if (input == RANK_INSTRUCTION)
        {
            system->print_main_team_players(team_name, EMPTY_STRING, true);
        }
        else
        {
            auto it = find(SUMMERIES_INSTRUCTIONS.begin(), SUMMERIES_INSTRUCTIONS.end(), input);
            if (it == SUMMERIES_INSTRUCTIONS.end())
                throw Bad_request();
            role = input;
            system->print_main_team_players(team_name, role, false);
        }
    }
    else if (count == 7)
    {
        command_line >> input;
        if (input != TEAM_NAME)
            throw Bad_request();
        command_line >> team_name;
        replaceUnderscoresWithSpaces(team_name);
        command_line >> input;

        auto it = find(SUMMERIES_INSTRUCTIONS.begin(), SUMMERIES_INSTRUCTIONS.end(), input);
        if (it == SUMMERIES_INSTRUCTIONS.end())
            throw Bad_request();
        role = input;
        command_line >> input;
        if (input != RANK_INSTRUCTION)
            throw Bad_request();

        system->print_main_team_players(team_name, role, true);
    }
    else
        throw Bad_request();
}

////////////////////////////////////  need to be check  /////////////////////////////////////////////
void InputHandler::set_captan()
{
    string input;
    string player_name;

    if (!cmnd_dlmtr_check())
        throw Bad_request();

    command_line >> input;
    if (input != NAME)
        throw Bad_request();

    command_line >> std::ws;
    getline(command_line, player_name);
    system->set_capitan(player_name);
    print_successfull_massage();
}

void InputHandler::show_budget()
{
    system->show_budget();
    // print_successfull_massage();
}
