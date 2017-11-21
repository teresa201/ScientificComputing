


// Inclusions
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "matrix.hpp"
#include <fstream>

using namespace std;

// function prototypes
double Lagrange(Matrix& x, Matrix& y, double z);
inline double f(double x){
  return (1/(1 + x*x));
};

double Newton_basis(Matrix& xnodes, int k, double x);

int main(){
// array of n values for testing
vector<size_t> nvals = {10, 20};

// loop over tests
for (size_t k=0; k<nvals.size(); k++) {

  // set n, output test information
  int n = nvals[k];
  cout << endl << "interpolants and errors using " << n+1 << " nodes:\n";

 // Matrix z = Linspace(-5.0,5,401);
  // set arrays of nodes and data values
  Matrix x = Linspace(-5.0, 5.0, n+1, 1);  // set column vector of nodes
  Matrix y(n+1);                          // initialize data
  for (int i=0; i<=n; i++)                // fill data
    y(i) = f(x(i));

  // set evaluation points z as 401 nodes
  //double dx = 1.0/n;                   // set node spacing
 // Matrix z = Linspace(dx/2.0, 1.0-dx/2.0, 401, 1);
  Matrix z = Linspace(-5.0,5,401);

  // evaluate the Lagrange polynomial at the 401 points z, storing in p
  Matrix p(401);
  for (int i=0; i<401; i++)
    p(i) = Lagrange(x, y, z(i));

  Matrix xnew = x.T();
  if(n == 10){
      double* mvalues = new double[401];
      for(int k = 0; k < 401; k++){
          mvalues[k] = Newton_basis(xnew,10,z(k));
      }
      Matrix m(1, 401, mvalues);

  ofstream mout("m.txt", ios::out);
  if(!mout){
     cout << "Unable to open file" << endl;
  }
  ofstream fout("rfofz.txt", ios::out);
  if(!fout){
     cout << "Unable to open file" << endl;
  }
  ofstream pout("rpz.txt", ios::out);
  if(!pout){
     cout << "Unable to open file" << endl;
  }
  ofstream eout("rerr.txt", ios::out);
  if(!eout){
     cout << "Unable to open file" << endl;
  }
  // output errors at each point
  cout << "      z        f(z)               p(z)             err\n";
  for (int i=0; i<401; i++){
    printf("   %6.3f   %16.13f   %16.13f   %7.2g\n",
       z(i), f(z(i)), p(i), fabs(f(z(i))-p(i)));
  fout << f(z(i)) << endl;
  pout << p(i) << endl;
  eout << fabs(f(z(i))-p(i)) << endl;
  mout << m(i) << endl;
  }
  fout.close();
  pout.close();
  eout.close();
  }
  if(n == 20){
  ofstream f2out("rfofz2.txt", ios::out);
  if(!f2out){
     cout << "Unable to open file" << endl;
  }
  ofstream p2out("rpz2.txt", ios::out);
  if(!p2out){
     cout << "Unable to open file" << endl;
  }
  ofstream e2out("rerr2.txt", ios::out);
  if(!e2out){
     cout << "Unable to open file" << endl;
  }
  // output errors at each point
  cout << "      z        f(z)               p(z)             err\n";
  for (int i=0; i<401; i++){
    printf("   %6.3f   %16.13f   %16.13f   %7.2g\n",
       z(i), f(z(i)), p(i), fabs(f(z(i))-p(i)));
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
