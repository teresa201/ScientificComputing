#include <iostream>
#include "fcn.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include "fcn.hpp"
#include <fstream>
#include <vector>

// function prototypes
double composite_Gauss2(Fcn& f, const double a,
            const double b, const int n);
using namespace std;
class fcn : public Fcn {
public:
  double operator()(double z) {   // function evaluation
    return (exp(-pow(z,2)));
  }
};

double erf(const double y,const int n){
   fcn f;
   double integral = composite_Gauss2(f, 0,
                y, n);
   double res = (2/sqrt(M_PI))*integral;
   return res;
}

double carbon(const double x, const double t){
    double c0 = .002;
    double cs = .07;
    double D = 1.75 * pow(10, -11);
    double n = 1000;
    double y = (x) / (sqrt(4 * D *t));
    double erfy = erf(y,n);
    return cs - (cs - c0)*erfy;
}
