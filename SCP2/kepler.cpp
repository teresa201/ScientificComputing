#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "fcn.hpp"
#include "matrix.hpp"

using namespace std;

double kepler(){

}

class fcn : public Fcn {
public:
 double operator()(double w, double e, double t){   // function evaluation
      return (e*sin(w) - w -t);
  }
  double operator()(double w, double e, int y){
      return (e*cos(w) - 1);
  }
  virtual double operator()(double x){}
  virtual double operator()(double x, int y){}

};

double newton(Fcn& f, Fcn& df, double x, int maxit, double tol,
              bool show_iterates, double e, double t)
{
    for(int k = 0;k < maxit; k++)
    {
        double fx = f(x,e,t);
        double fp = df(x,e,0);
        double d = fx/fp;
        x = x - d;
        if(show_iterates)
        {
            cout << "Iteration: " << k + 1 << endl;
            cout << " Solution Guess: " << x;
            cout << " Solution: " << abs(x);
            cout << " Residual: " << abs(fx);
            cout << " Error: " << abs(d) << endl;

        }
        if(abs(d) < tol)
        {
            return x;
        }
    }
}
int main(int argc, char* argv[]) {

    double a = 2.0;
    double b = 1.25;
    double epislon = sqrt(1 - (pow(b,2)/pow(a,2)));
    Matrix t = Linspace(0,10,10001);
    vector<double> time;
    for(int k = 0; k < t.Rows(); k++)
    {
        time.push_back(t(k,0));
    }
    fcn kf;
    fcn dkf;
    double w = 0;
    int maxit = 6;
    double tol = pow(10 , -5);
    bool show_iterates = false;
    vector<double> wsolutions;

    //uses Newtons method to compute W for each t
    for(int k = 0; k < time.size(); k++)
    {
       double sol = newton(kf,dkf,w,maxit,tol,show_iterates,epislon,time[k]);
       wsolutions.push_back(sol);
       w = sol;
    }

    double xt[10001];
    double yt[10001];
    for(int k = 0; k < time.size(); k++)
    {
        w = wsolutions[k];
        double rw = (a*b)/(sqrt(pow(b*cos(w),2) +pow(a*sin(w),2)));
        double xVal = rw * cos(w);
        double yVal = rw * sin(w);
        xt[k] = xVal;
        yt[k] = yVal;
    }

    Matrix xxt(1,10001,xt);
    Matrix yyt(1,10001,yt);
    ofstream xout("x.txt", ios::out);
    if(!xout){
       cout << "Unable to open file" << endl;
    }
    for(int k = 0; k < 10001; k++)
    {
        xout << xxt(0,k) << endl;
    }


    ofstream yout("y.txt", ios::out);
    if(!yout){
       cout << "Unable to open file" << endl;
    }
    for(int k = 0; k < 10001; k++)
    {
        yout << yyt(0,k) << endl;
    }


    ofstream tout("t.txt", ios::out);
    if(!tout){
       cout << "Unable to open file" << endl;
    }
    for(int k = 0; k < 10001; k++)
    {
       tout << t(k,0) << endl;
    }
    xout.close();
    yout.close();
    tout.close();







}
