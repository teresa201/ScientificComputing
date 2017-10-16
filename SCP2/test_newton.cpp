// Inclusions
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "fcn.hpp"
#include <fstream>
using namespace std;

// Newton solver prototype
double newton(Fcn& f, Fcn& df, double x, int maxit, double tol, bool show_iterates, ofstream& nout);


class fcn : public Fcn {
public:
  double operator()(double x) {   // function evaluation
      return (pow(x,2) * (x - 3) * (x + 2));
  }
  double operator()(double x, int y) {   // function evaluation
       return ((4*pow(x,3)) - (3*pow(x,2)) - (12*x));
  }
  double operator()(double w, double e, double t){};
  double operator()(double w, double e, int y){};
};

int main(int argc, char* argv[]) {

  // set the init values

  // create the function object
    ofstream nout("n.txt", ios::out);
    if(!nout){
       cout << "Unable to open file" << endl;
    }
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

          nout << "Starting X: " << x0 << " Tolerance: " << tol << endl;
          double sol = newton(f,df,x0,maxit,tol,show_iterates, nout);
          nout << "Approximate root: " << setprecision(16) << sol << endl;
          nout << " " << endl;
      }
  }


}
