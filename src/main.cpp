#include "../include/System.hpp"
#include "../include/InputHandler.hpp"
#include <iostream>


int main()
{
    System system;
    // InputHandler input_handler;
    // input_handler.run();
    // system.print_players();

    system.login_admin("123456");
    system.open_transfare_window();
    system.pass_week();

    system.print_players();






    return 0;  
}