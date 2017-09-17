#include <iostream>
#include "matrix.hpp"
#include "nest.h"
using namespace std;

int factorial(int f)
{
    int res = 1;
    for(int k = f; f > 0; f--){
        res *= f;
    }
    return res;
}
int main()
{
    //cout << "Hello World!" << endl;

    Nest n;
    double data[4] = {2,-6,2,1};
    Matrix a(1,4,data);
    double ans = n.nest(a, 3);
    cout << ans << endl;

    double data1[15] = {.1,2,.3,4,5,.6,7,8,9,10,11,12,13,14,15};
    Matrix b(1,15,data1);
    cout << n.nest(b, 8) << endl;
    Matrix z =Linspace(-1, 1, 1, 201);

   // cout << factorial(4);
    double data4[] = {1,1,1/(double)factorial(2),1/(double)(factorial(3)),1/(double)(factorial(4))};
    double data8[] = {1,1,1/(double)factorial(2),1/(double)(factorial(3)),1/(double)(factorial(4)),
                     1/(double)factorial(5),1/(double)(factorial(6)),1/(double)(factorial(7)),
                     1/(double)factorial(8)};
    double data12[] = {1,1,1/(double)factorial(2),1/(double)(factorial(3)),1/(double)(factorial(4)),
                     1/(double)factorial(5),1/(double)(factorial(6)),1/(double)(factorial(7)),
                     1/(double)factorial(8),1/(double)factorial(9),1/(double)(factorial(10)),
                      1/(double)(factorial(11)),1/(double)(factorial(12))};

    Matrix pp4(1,5, data4);
    Matrix pp8(1,9, data8);
    Matrix pp12(1,13, data12);
   // cout << pp4;
    vector<double> p4;
    vector<double> p8;
    vector<double> p12;

    for(int k = 0; k < 201; k++)
    {
        double ans = n.nest(pp4,z(0,k));
        p4.push_back(ans);
    }
    cout << p4 << endl;
    cout << "" << endl;
    cout << "" << endl;
    for(int k = 0; k < 201; k++)
    {
        double ans1 = n.nest(pp8,z(0,k));
        p8.push_back(ans1);
    }
    cout << p8 << endl;
    cout << "" << endl;
    cout << "" << endl;
    for(int k = 0; k < 201; k++)
    {
        double ans1 = n.nest(pp12,z(0,k));
        p12.push_back(ans1);
    }
    cout << p12 << endl;
    //m.Write();
    //cout << m;

}


