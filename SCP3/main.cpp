#include <iostream>
#include "matrix.hpp"
#include <cmath>
#include <fstream>
using namespace std;



double Newton_basis(Matrix& xnodes, int k, double x){
    double result = 1;
    for(int i = 0; i < k+1; i++){
        result *= (x - xnodes(0,i));
    }
    return result;
}

double Newton_nestedform(Matrix& a, Matrix&xnodes, double x){
    double result = a(0,a.Size() - 1); //get largest coefficent
    for(int k = a.Size() - 2; k >= 0; k--){
        result = a(0,k) + (x-xnodes(0,k))*result;
    }
    return result;
}

Matrix Newton_coefficents(Matrix& xnodes, Matrix& ynodes){
   // double avalues[xnodes.] = ynodes(0,0); // to start a0 = y0
   // Matrix abegin(1,1,astart);
    int x = xnodes.Size();
    double* avalues = new double[x];
    avalues[0] = ynodes(0,0); //a0 = y0
    //Matrix abegin(1,xnodes.Size(),avalues);


    //need to find 0 - k coefficents(if size is 4, k is 3)
    for(int k = 0; k < xnodes.Size()-1; k++ ){
        Matrix pass(1,k+1,avalues);
        double numerator = ynodes(0,k+1) - Newton_nestedform(pass,xnodes,xnodes(0,k+1));
        double denom = Newton_basis(xnodes,k,xnodes(0,k+1));
        double a = numerator/denom;
        avalues[k+1] = a;
    }
    Matrix abegin(1,xnodes.Size(),avalues);
    return abegin;
}

int main()
{
    cout << "Hello World!" << endl;
    
   //test Newton Basis, answer should be 24
    double data[4] = {1,2,3,4};
    Matrix m(1,4,data);
    cout << Newton_basis(m,3,5) << endl;

    //test newton nested form ans should be 82
    double coeff[24] = {2,2,2,2};
    Matrix n(1,4,coeff);
    cout << Newton_nestedform(n,m,5) << endl;

    double x[3] = {1,3,2};
    Matrix xv(1,3,x);

    double y[3] = {2,5,7};
    Matrix yv(1,3,y);
    cout << Newton_coefficents(xv,yv) << endl;

    double x1[5] = {-2,-1,0,1,2};
    Matrix xv1(1,5,x1);

    double y1[5] = {-4.7,-6.6,7.9,15.4,66.9};
    Matrix yv1(1,5,y1);
    cout << Newton_coefficents(xv1,yv1) << endl;

    ofstream zout("z.txt", ios::out);
    if(!zout){
       cout << "Unable to open file" << endl;
    }
    Matrix t = Linspace(-3,3,201);
    for(int k = 0; k < 201; k++)
    {
        double x = t(k,0);
        double result = 3.1 * pow(x,4) + 2.3 * pow(x,3) - 6.6 * pow(x,2) + 8.7 * x + 7.9;
        zout << result << endl;
    }
    zout.close();

    ofstream tout("t.txt", ios::out);
    if(!tout){
       cout << "Unable to open file" << endl;
    }
    Matrix t1 = Linspace(-3,3,201);
    for(int k = 0; k < 201; k++)
    {
        double x = t1(k,0);
        double result = -4.7 + (-1.9)*(x+2) + 8.2*(x+2)*(x+1) + (-3.9)*(x+2)*(x+1)*(x) + 3.1*(x+2)*(x+1)*(x)*(x-1);
        tout << result << endl;
    }
    tout.close();



}

