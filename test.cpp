#include <cmath>
#include <iostream>

using namespace std;

double sigmoid(double x) {
    return 10.0 / (1.0 + exp(-x / 6.0));
}


int main()
{

    double x = 4;
    cout << x << " " << sigmoid(x) << endl;

    return 0;
}