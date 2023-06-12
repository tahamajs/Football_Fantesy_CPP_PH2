#include "../include/Exeptions.hpp"
// Path: phase_1/src/Exceptions.hpp

const char *Not_Found::what() const noexcept
{
    return "Not Found";
}

const char *Bad_request::what() const noexcept
{
    return "Bad Request";
}

const char *Permission_denied::what() const noexcept
{
    return "Permission Denied";
}

const char *Empty::what() const noexcept
{
    return "Empty";
}

const char *Player_not_available::what() const noexcept
{
    return "This player is not available for next week";
}