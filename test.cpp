#include <cmath>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double sigmoid(double x)
{
    return 10.0 / (1.0 + exp(-x / 6.0));
}

double inverse_double_sigmoid(double y)
{
    return -6.0 * log(10.0 / y - 1.0);
}

int main()
{

    double x = 11;

    // cout << x << " " << floor(sigmoid(x) * 10) / 10 << endl;
    // printf("%.1f ", sigmoid(x));
    cout << inverse_double_sigmoid(sigmoid(x)) << endl;

    return 0;
}