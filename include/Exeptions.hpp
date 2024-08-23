#include <exception>

using namespace std;

class Not_Found : public exce   ption
{
public:
    const char *what() const noexcept override;
};

class Bad_request : public exception
{
public
    const char *what() const noexcept override;
};

class Permission_denied : public exception
{
public:
    const char *what() const noexcept override;
};

class Empty : public exception
{
public:
    const char *what() const noexcept override;
};

class Player_not_available : public exception
{
public:
    const char *what() const noexcept override;
};