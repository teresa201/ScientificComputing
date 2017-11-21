


// Inclusions
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include "matrix.hpp"
#include <fstream>

using namespace std;

// function prototypes
double Lagrange(Matrix& x, Matrix& y, double z);
inline double f(double x){
  return (1/(1 + x*x));
};

int main(){
// array of n values for testing
vector<size_t> nvals = {10, 20};

// loop over tests
for (size_t k=0; k<nvals.size(); k++) {

  // set n, output test information
  int n = nvals[k];
  cout << endl << "interpolants and errors using " << n+1 << " nodes:\n";


  // set arrays of nodes and data values
  double* xvalues = new double[n+1];
  for(int k = 0; k <= n; k++){
      xvalues[k] = 5 * cos(((2*k + 1)* M_PI)/(2*n + 2));
  }
  Matrix x(1, n+1, xvalues);
  //Matrix x = Linspace(-5.0, 5.0, n+1, 1);  // set column vector of nodes
  Matrix y(n+1);                          // initialize data
  for (int i=0; i<=n; i++)                // fill data
    y(i) = f(x(i));

  // set evaluation points z as 401 nodes

  Matrix z = Linspace(-5.0,5,401);
 /* double* zvalues = new double[n+1];
  for(int k = 0; k < n; k++){
      zvalues[k] = 5 * cos(((2*k + 1)* M_PI)/(2*n + 2));
  }
  Matrix z(1, n+1, zvalues);*/

  // evaluate the Lagrange polynomial at the 401 points z, storing in p
  Matrix p(401);
  for (int i=0; i<401; i++)
    p(i) = Lagrange(x, y, z(i));

  if(n == 10){
  ofstream fout("r1fofz.txt", ios::out);
  if(!fout){
     cout << "Unable to open file" << endl;
  }
  ofstream pout("r1pz.txt", ios::out);
  if(!pout){
     cout << "Unable to open file" << endl;
  }
  ofstream eout("r1err.txt", ios::out);
  if(!eout){
     cout << "Unable to open file" << endl;
  }
  // output errors at each point
  cout << "      z        f(z)               p(z)             err\n";
  for (int i=0; i<401; i++){
   // printf("   %6.3f   %16.13f   %16.13f   %7.2g\n",
  //     z(i), f(z(i)), p(i), fabs(f(z(i))-p(i)));
  fout << f(z(i)) << endl;
  pout << p(i) << endl;
  eout << fabs(f(z(i))-p(i)) << endl;
  }
  fout.close();
  pout.close();
  eout.close();
  }
  if(n == 20){
  ofstream f2out("r1fofz2.txt", ios::out);
  if(!f2out){
     cout << "Unable to open file" << endl;
  }
  ofstream p2out("r1pz2.txt", ios::out);
  if(!p2out){
     cout << "Unable to open file" << endl;
  }
  ofstream e2out("r1err2.txt", ios::out);
  if(!e2out){
     cout << "Unable to open file" << endl;
  }
  // output errors at each point
  cout << "      z        f(z)               p(z)             err\n";
  for (int i=0; i<401; i++){
   // printf("   %6.3f   %16.13f   %16.13f   %7.2g\n",
   //    z(i), f(z(i)), p(i), fabs(f(z(i))-p(i)));
  f2out << f(z(i)) << endl;
  p2out << p(i) << endl;
  e2out << fabs(f(z(i))-p(i)) << endl;
  }
  f2out.close();
  p2out.close();
  e2out.close();
  }
}
}

