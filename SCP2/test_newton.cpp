// Inclusions
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "fcn.hpp"

using namespace std;

// Newton solver prototype
double newton(Fcn& f, Fcn& df, double x, int maxit, double tol, bool show_iterates);


class fcn : public Fcn {
public:
  double operator()(double x) {   // function evaluation
      return (pow(x,2) * (x - 3) * (x + 2));
  }
  double operator()(double x, int y) {   // function evaluation
       return ((4*pow(x,3)) - (3*pow(x,2)) - (12*x));
  }
};

int main(int argc, char* argv[]) {

  // set the init values

  // create the function object
  fcn f;
  fcn df;
  int a [3] = {-3, 1,2};
  double b[3] = {pow(10,-1), pow(10,-5), pow(10,-9)};
  for(int k = 0; k < 3; k++)
  {
      double x0 = a[k];
      for(int j = 0; j < 3;j++)
      {
          double tol = b[j];
          int maxit = 50;
          bool show_iterates = true;

          // call bisection to compute the root, and output result to screen
          cout << "X: " << x0 << " Tol: " << tol << endl;
          double sol = newton(f,df,x0,maxit,tol,show_iterates);
          cout << "Approximate root: " << setprecision(16) << sol << endl;
          cout << " " << endl;
      }
  }


}
