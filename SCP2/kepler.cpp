#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include "fcn.hpp"

using namespace std;

double kepler(){




}

class fcn : public Fcn {
public:
  virtual double operator()(double w, double e, double t){   // function evaluation
      return (e*sin(w) - w -t);
  }
  virtual double operator()(double w, double e, int y){
      return (e*cos(w) - 1);
  }
};

double newton(Fcn& f, Fcn& df, double x, int maxit, double tol,
              bool show_iterates, double e, double t)
{
    for(int k = 0;k < maxit; k++)
    {
        double fx = f(x,e,t);
        double fp = df(x,e,0);
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
int main(int argc, char* argv[]) {

    fcn kf;
    fcn dkf;
    double a = 2.0;
    double b = 1.25;
    double epislon = sqrt(1 - (pow(b,2)/pow(a,2)));


}
