/* Daniel R. Reynolds
   SMU Mathematics
   Math 3316
   31 October 2015 */

// Inclusions
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "fcn.hpp"

using namespace std;

// function prototypes
double composite_Gauss2(Fcn& f, const double a, 
			const double b, const int n);

// Integrand
class fcn : public Fcn {
public:
  double c, d;
  double operator()(double x) {   // function evaluation
    return (exp(c*x) + sin(d*x));
  }
  double antiderivative(double x) { // function evaluation
    return (exp(c*x)/c - cos(d*x)/d);
  }
};


// This routine tests the Gauss-2 method on a simple integral
/*int main(int argc, char* argv[]) {

  // limits of integration
  double a = -3.0;
  double b = 5.0;

  // integrand
  fcn f;
  f.c = 0.5;
  f.d = 25.0;

  // true integral value
  double Itrue = f.antiderivative(b) - f.antiderivative(a);
  printf("\n True Integral = %22.16e\n", Itrue);


  // test the Gauss-2 rule
  cout << "\n Gauss-2 approximation:\n";
  cout << "     n             R(f)            relerr    conv rate\n";
  cout << "  ---------------------------------------------------\n";
  vector<int> n = {20, 40, 80, 160, 320, 640, 1280, 2560, 5120, 10240};
  vector<double> errors(n.size());
  vector<double> hvals(n.size());

  // iterate over n values, computing approximations, error, convergence rate
  double Iapprox;
  for (int i=0; i<n.size(); i++) {

    printf("   %6i", n[i]);
    Iapprox = composite_Gauss2(f, a, b, n[i]);
    errors[i] = fabs(Itrue-Iapprox)/fabs(Itrue);
    hvals[i] = (b-a)/n[i];
    if (i == 0) 
      printf("  %22.16e  %7.1e     ----\n", Iapprox, errors[i]);
    else 
      printf("  %22.16e  %7.1e   %f\n", Iapprox, errors[i], 
	     (log(errors[i-1]) - log(errors[i]))/(log(hvals[i-1]) - log(hvals[i])));
    
  }
  cout << "  ---------------------------------------------------\n";

}*/


