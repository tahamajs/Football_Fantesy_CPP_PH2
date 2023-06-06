#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string>
#include "Consts.hpp"

using namespace std;

const string Main_Password = "123456";


class Admin
{
public:
    Admin(enum Teansfare_window_status *_transfer_window_status);
    bool check_password(string _password);
    void set_password(string _password);
    void set_transfer_window_status(enum Teansfare_window_status _transfer_window_status);
    
private:
    string password = Main_Password;
    enum Teansfare_window_status *transfer_window_status;
};