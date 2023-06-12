#include <cmath>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double sigmoid(double x) {
    return 10.0 / (1.0 + exp(-x / 6.0));
}


int main()
{

    double x = 13;
    cout << x << " " << floor(sigmoid(x)*10)/10 << endl;
    printf("%.1f " ,sigmoid(x) );

    return 0;
}