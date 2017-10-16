#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include "fcn.hpp"
#include <fstream>

using namespace std;



double newton(Fcn& f, Fcn& df, double x, int maxit, double tol, bool show_iterates, ofstream& nout)
{
    //ofstream nout("n.txt", ios::out);
    //if(!nout){
    //   cout << "Unable to open file" << endl;
   // }
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
           // nout << " Error: " << abs(d) << endl;

        }
        if(abs(d) < tol)
        {
            return x;
        }
    }
   // nout.close();
}
