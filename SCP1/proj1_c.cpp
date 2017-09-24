#include <iostream>
#include <cmath>
#include <fstream>
#include "matrix.hpp"

using namespace std;

int factorial(int f);
/*{
    int res = 1;
    for(int k = f; f > 0; f--){
        res *= f;
    }
    return res;
}*/
/*int main()
{
    double bigV[25];
    double overF[25];
    double v0 = 1 - (1/ exp(1));
    bigV[0] = v0;
    printf("%1s %14s %12s \n", "j","V(j)", "V(j)/j!");
    //cout << "j " << "  V(j) " << "      V(j)/j!" << endl;
    for(int k = 1; k < 25; k++)
    {
        bigV[k] = 1 - k * bigV[k - 1];
        double overfactorial = bigV[k] / factorial(k);
        overF[k] = overfactorial;
        printf("%-5d %-15f %-52f \n", k, bigV[k], overfactorial);
        //cout << k << "   " << bigV[k] << "    " << overfactorial << endl;
    }
}*/
