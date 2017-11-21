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

 double* x1values = new double[20];
 x1values[0] = 1885;
 x1values[1] = 1895;
 x1values[2] = 1905;
 x1values[3] = 1915;
 x1values[4] = 1925;
 x1values[5] = 1935;
 x1values[6] = 1945;
 x1values[7] = 1955;
 x1values[8] = 1965;
 x1values[9] = 1975;
 x1values[10] = 1985;
 x1values[11] = 1995;


 Matrix x1(12,1,x1values);

 double* y1values = new double[12];
 y1values[0] = 56.7;
 y1values[1] = 56.72;
 y1values[2] = 56.87;
 y1values[3] = 56.89;
 y1values[4] = 57.01;
 y1values[5] = 57.21;
 y1values[6] = 57.28;
 y1values[7] = 57.18;
 y1values[8] = 57.12;
 y1values[9] = 57.22;
 y1values[10] = 57.65;
 y1values[11] = 57.89;

 Matrix y1(12,1,y1values);

 Matrix z1 = Linspace(1885,2015,200);

 ofstream eout("app1.txt", ios::out);
 if(!fout){
    cout << "Unable to open file" << endl;
 }
 for(int k = 0; k < 200; k++){
     double res = Lagrange(x1,y1,z1(k));
     eout << res << endl;
 }
}
