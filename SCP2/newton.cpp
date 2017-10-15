#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include "fcn.hpp"

using namespace std;



double newton(Fcn& f, Fcn& df, double x, int maxit, double tol, bool show_iterates)
{
    for(int k = 0;k < maxit; k++)
    {
        double fx = f(x);
        double fp = df(x,0);
        double d = fx/fp;
        x = x - d;
        if(show_iterates)
        {
            cout << "Iteration: " << k + 1 << endl;
            cout << " Solution Guess: " << x;
            cout << " Solution: " << abs(x);
            cout << " Residual: " << abs(fx);
            cout << " Error: " << abs(d) << endl;

        }
        if(abs(d) < tol)
        {
            return x;
        }
    }
}
