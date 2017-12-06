#include <iostream>
#include "fcn.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include "fcn.hpp"
#include <fstream>
#include <vector>
#include <math.h>
#include <cmath>
#include "matrix.hpp"
using namespace std;

double carbon(const double x, const double t);
double erf(const double y,const int n);

int main(){
   Matrix x = Linspace(0,3,200); //3 is in mm
   ofstream fout("t1.txt", ios::out);
   if(!fout){
      cout << "Unable to open file" << endl;
   }
   for(int k = 0; k < 200; k++){
       double t = 1.0;
       fout << carbon(x(k), t) << endl;
   }
   fout.close();
   ofstream gout("t2.txt", ios::out);
   if(!gout){
      cout << "Unable to open file" << endl;
   }
   for(int k = 0; k < 200; k++){
       double t = 2.0;
       gout << carbon(x(k), t) << endl;
   }
   gout.close();
   ofstream hout("t3.txt", ios::out);
   if(!hout){
      cout << "Unable to open file" << endl;
   }
   for(int k = 0; k < 200; k++){
       double t = 10.0;
       hout << carbon(x(k), t) << endl;
   }
   hout.close();
   ofstream iout("t4.txt", ios::out);
   if(!iout){
      cout << "Unable to open file" << endl;
   }
   for(int k = 0; k < 200; k++){
       double t = 40.0;
       iout << carbon(x(k), t) << endl;
   }
   iout.close();



}
