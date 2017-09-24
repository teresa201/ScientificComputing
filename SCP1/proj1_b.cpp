#include <iostream>
#include <cmath>
#include <fstream>
#include "matrix.hpp"

using namespace std;

int main(){
    cout << "Hello" << endl;
    double r[52];
    double bigR[52];
    int n[52];
    double h[52];
    for(int k = 0; k < 52; k++)
    {
        n[k] = k+1;
    }
    for(int k =0; k < 52; k++)
    {
        h[k] = pow(2,-(k+1));

    }

    //calculate R and write to a file
    double fprimex = .5;
    double fdprimex = -.25;
    double fofx = log(2);
    double eplison = pow(2, -52);
    double c1 = abs(fdprimex/ (2 * fprimex));
    double c2 = abs(fofx * eplison / fprimex);
    ofstream Rout("R.txt", ios::out);
    if(!Rout){
       cout << "Unable to open file" << endl;
    }
    for(int k = 0; k < 52; k++)
    {
         double R = c1 * h[k] + c2 * (1/h[k]);
         bigR[k] = R;
         Rout << bigR[k] <<endl;
    }
    Rout.close();

    //calculate r and write to file

    double symbol[52];
    ofstream rout("r.txt", ios::out);
    if(!rout){
       cout << "Unable to open file" << endl;
    }
    for(int k = 0; k < 52; k++)
    {
         double fdist = (log(2 + h[k]) - fofx) / h[k];
         symbol[k] = fdist;
         double rval = abs((fprimex - fdist )/ fprimex);
         r[k] = rval;
         rout << r[k] <<endl;
    }
    rout.close();

    //write n to a file
    ofstream nout("n.txt", ios::out);
    if(!nout){
       cout << "Unable to open file" << endl;
    }
    for(int k = 0; k < 52; k++)
    {
        nout << n[k] << endl;
    }
    nout.close();

    //write h to a file
    ofstream hout("h.txt", ios::out);
    if(!hout){
       cout << "Unable to open file" << endl;
    }
    for(int k = 0; k < 52; k++)
    {
        hout << h[k] << endl;
    }
    hout.close();
}
