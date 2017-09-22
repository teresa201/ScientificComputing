#include <iostream>
#include <cmath>
#include <fstream>
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
/*int main()
{
    Nest n;
    double data[4] = {2,-6,2,-1};
    Matrix a(1,4,data);
    double ans = n.nest(a, 3);
    cout << ans << endl;

    double dataw[4] = {6,-3,2,1};
    Matrix aw(1,4,dataw);
    double answ = n.nest(aw, 4);
    cout << answ << endl;

    double data1[15] = {.1,2,.3,4,5,.6,7,8,9,10,11,12,13,14,15};
    Matrix b(1,15,data1);
    cout << n.nest(b, 8) << endl;

    //create z and write to a file
    Matrix z =Linspace(-1, 1, 1, 201);
    ofstream zout("z.txt", ios::out);
    if(!zout){
       cout << "Unable to open file" << endl;
    }
    for(int k = 0; k < 201; k++)
    {
        zout << z[k] << endl;
    }
    zout.close();


    //coefficent matrices for taylor series of e^x
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

    vector<double> p4;
    vector<double> p8;
    vector<double> p12;
    vector<double> f;
    vector<double> err4;
    vector<double> err8;
    vector<double> err12;

    //calc p4 and write to a file
    ofstream p4out("p4.txt", ios::out);
    if(!p4out){
       cout << "Unable to open file" << endl;
    }
    for(int k = 0; k < 201; k++)
    {
        double ans = n.nest(pp4,z(0,k));
        p4.push_back(ans);
        p4out << p4[k] << endl;
    }
    p4out.close();

    //calc p8 and write to file
    ofstream p8out("p8.txt", ios::out);
    if(!p8out){
       cout << "Unable to open file" << endl;
    }
    for(int k = 0; k < 201; k++)
    {
        double ans1 = n.nest(pp8,z(0,k));
        p8.push_back(ans1);
        p8out << p8[k] << endl;
    }
    p8out.close();

    //calc p12 and write to file
    ofstream p12out("p12.txt", ios::out);
    if(!p12out){
       cout << "Unable to open file" << endl;
    }
    for(int k = 0; k < 201; k++)
    {
        double ans1 = n.nest(pp12,z(0,k));
        p12.push_back(ans1);
        p12out << p12[k] << endl;
    }
    p12out.close();

    //calc f and write to file
    ofstream fout("f.txt", ios::out);
    if(!fout){
       cout << "Unable to open file" << endl;
    }

    for(int k = 0; k < 201; k++)
    {
        double ans2 = exp(z(0,k));
        f.push_back(ans2);
        fout << f[k] << endl;
    }
    fout.close();


    //calc err4 and write to file
    ofstream e4out("err4.txt", ios::out);
    if(!e4out){
       cout << "Unable to open file" << endl;
    }

    for(int k = 0; k < 201; k++)
    {
        double ans2 = abs(f[k] - p4[k]) ;
        err4.push_back(ans2);
        e4out << err4[k] << endl;
    }
    e4out.close();

    //calc err8 and write to file
    ofstream e8out("err8.txt", ios::out);
    if(!e8out){
       cout << "Unable to open file" << endl;
    }
    for(int k = 0; k < 201; k++)
    {
        double ans2 = abs(f[k] - p8[k]) ;
        err8.push_back(ans2);
        e8out << err8[k] << endl;
    }
    e8out.close();


    //calc err12 and write to file
    ofstream e12out("err12.txt", ios::out);
    if(!e12out){
       cout << "Unable to open file" << endl;
    }
    for(int k = 0; k < 201; k++)
    {
        double ans2 = abs(f[k] - p12[k]) ;
        err12.push_back(ans2);
        e12out << err12[k] << endl;
    }
    e12out.close();


}*/


