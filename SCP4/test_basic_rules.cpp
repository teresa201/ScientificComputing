#include <iostream>
#include "fcn.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include "fcn.hpp"
#include <fstream>
#include <vector>
/*using namespace std;
class fcn : public Fcn {
public:*/
 /*double operator()(double x) {   // function evaluation
      return (6 * pow(x,2) - 4 * x + 1);
  }*/
 /* double operator()(double x) {   // function evaluation
    return (exp(x)*sin(M_PI*x));
  }
  double antiderivative(double x) { // function evaluation
    //return (M_PI* (exp(1) - ((1)/ exp(1))))/(1 + M_PI * M_PI);
      return -(exp(x)*(M_PI * cos(M_PI*x) - sin(M_PI*x)))/(1 + M_PI * M_PI);
  }
};

double composite_trapezodial(Fcn& f, const double a,
                             const double b, const int n){
    double h = (b - a)/n;
    double sum = (f(a) + f(b))/2;
    for (int k = 1; k < n; k++){
        double x = a + k * h;
        sum = sum + f(x);
    }
    sum = h * sum;
    return sum;
}

double composite_Simpson(Fcn& f, const double a,
                             const double b, const int n){
    double h = (b - a)/n;
    double x0 = f(a) + f(b);
    double x1 = 0;
    double x2 = 0;
    for(int k = 1; k < n; k++){
        double x = a + k * h;
        if(k % 2 == 0){
            x2 = x2 + f(x);
        }
        else{
            x1 = x1 + f(x);
        }
    }
    double xi = (h * (x0 + 2 * x2 + 4 * x1))/3;
    return xi;

}*/

/*int main()
{
    fcn f;
    double actual = 15;
    double result = composite_trapezodial(f,-1,2,10);
    cout << "Composite Trapezodial:" << result << endl;
    cout << "Error:" << abs(actual - result) << endl;
    double result1 = composite_Simpson(f,-1,2,10);
    cout << "Composite Simpson:" << result1 << endl;
    cout << "Error:" << abs(actual - result1) << endl;
*/


    // limits of integration
 /*   double a = -1.0;
    double b = 1.0;

    // integrand
    fcn f1;
    //f.c = 0.5;
   // f.d = 25.0;

    // true integral value
    double Itrue = f1.antiderivative(b) - f1.antiderivative(a);
   // cout << exp(1) << endl;
    printf("\n True Integral = %22.16e\n", Itrue);
   // cout << (M_PI* (exp(1) - ((1)/ exp(1))))/(1 + M_PI * M_PI) << endl;


    // test the Simpson rule
    cout << "\n Simpson approximation:\n";
    cout << "     n             R(f)            relerr    conv rate\n";
    cout << "  ---------------------------------------------------\n";
    vector<int> n = {20, 40, 80, 160, 320, 640};
    vector<double> errors(n.size());
    vector<double> hvals(n.size());

    // iterate over n values, computing approximations, error, convergence rate
    double Iapprox;
    for (int i=0; i<n.size(); i++) {

      printf("   %6i", n[i]);
      Iapprox = composite_Simpson(f1, a, b, n[i]);
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

