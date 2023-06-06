#include "../include/Admin.hpp"

Admin::Admin(enum Teansfare_window_status *_transfer_window_status)
{
    this->transfer_window_status = _transfer_window_status;
}

bool Admin::check_password(string _password)
{
    return this->password == _password;
}

void Admin::set_password(string _password)
{
    this->password = _password;
}

void Admin::set_transfer_window_status(enum Teansfare_window_status _transfer_window_status)
{
    *(this->transfer_window_status) = _transfer_window_status;
}

