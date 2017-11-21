#include <iostream>
#include <math.h>
#include <cmath>
#include "matrix.hpp"
#include <fstream>
using namespace std;
double Lagrange(Matrix& x, Matrix& y, double z);

int main(){
 double* xvalues = new double[12];
 xvalues[0] = 1885;
 xvalues[1] = 1895;
 xvalues[2] = 1905;
 xvalues[3] = 1915;
 xvalues[4] = 1925;
 xvalues[5] = 1935;
 xvalues[6] = 1945;
 xvalues[7] = 1955;
 xvalues[8] = 1965;
 xvalues[9] = 1975;
 xvalues[10] = 1985;
 xvalues[11] = 1995;

 Matrix x(12,1,xvalues);

 double* yvalues = new double[12];
 yvalues[0] = 56.7;
 yvalues[1] = 56.72;
 yvalues[2] = 56.87;
 yvalues[3] = 56.89;
 yvalues[4] = 57.01;
 yvalues[5] = 57.21;
 yvalues[6] = 57.28;
 yvalues[7] = 57.18;
 yvalues[8] = 57.12;
 yvalues[9] = 57.22;
 yvalues[10] = 57.65;
 yvalues[11] = 57.89;

 Matrix y(12,1,yvalues);

 Matrix z = Linspace(1885,1995,200);

 ofstream fout("app.txt", ios::out);
 if(!fout){
    cout << "Unable to open file" << endl;
 }
 for(int k = 0; k < 200; k++){
     double res = Lagrange(x,y,z(k));
     fout << res << endl;
 }
}
