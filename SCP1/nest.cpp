
#include "nest.h"
#include <iostream>

using namespace std;

double Nest::nest(Matrix& c, double x)
{
    //c.Write();
    double result = c(0,c.Size() - 1);
    for(int k = c.Size() - 2; k >= 0; k--){
        result = c(0,k) + result * x;
    }
    return result;


    //int r = c.Rows();
    //cout << "Rows" << c.Rows();
    //cout << "Cols" << c.Columns();
}

