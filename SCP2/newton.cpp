#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include "fcn.hpp"
#include <fstream>

using namespace std;



double newton(Fcn& f, Fcn& df, double x, int maxit, double tol, bool show_iterates, ofstream& nout)
{

    for(int k = 0;k < maxit; k++)
    {
        double fx = f(x);
        double fp = df(x,0);
        double d = fx/fp;
        x = x - d;
        if(show_iterates)
        {
            nout << "Iteration: " << k + 1 << endl;
            nout << " Solution Guess: " << x;
            nout << " Solution Update/Error: " << abs(d);
            nout << " Residual: " << abs(fx) << endl;
            cout << "Iteration: " << k + 1 << endl;
            cout << " Solution Guess: " << x;
            cout << " Solution Update/Error: " << abs(d);
            cout << " Residual: " << abs(fx) << endl;

        }
        if(abs(d) < tol)
        {
            return x;
        }
    }
}
