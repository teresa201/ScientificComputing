#include <iostream>
#include <cmath>
#include <fstream>
#include "matrix.hpp"

using namespace std;

double factorial(int f)
{
    double res = 1;
    for(int k = f; f > 0; f--){
        res *= f;
    }
    return res;
}
int main()
{
    double bigV[26];
    double overF[26];
    double v0 = 1 - (1/ exp(1));
    bigV[0] = v0;
   // printf("%1s %11s %15s \n", "j","V(j)", "V(j)/j!");
   // printf("%-5d %-15f %-52f \n", 0,0,0);

    ofstream t1out("table1.txt", ios::out);
    if(!t1out){
       cout << "Unable to open file" << endl;
    }
    //print the first table of j, V(j), V(j)/j! for Vo = (1 - 1/e)
    for(int k = 1; k < 26; k++)
    {
        bigV[k] = 1 - k * bigV[k - 1];
       // vout << bigV[k] << endl;
        double overfactorial = bigV[k] / factorial(k);
        overF[k] = overfactorial;
        t1out << k << ' ' << bigV[k] << ' ' << overfactorial << endl;
       // printf("%-5d %-15f %-52f \n", k, bigV[k], overfactorial);
    }
    //vout.close();
    //overout.close();
    t1out.close();
   // cout << " " << endl;
   // cout << "Modified Formula error = .13" << endl;
   // cout << " " << endl;

    //print modifed formula error = .13
    double mbigV[25];
    double moverF[25];
    double error = .13;
    double mv0 = 1 - (1/ exp(1) + error);
    mbigV[0] = mv0;
    //printf("%1s %11s %30s \n", "j","V(j)", "V(j)/j!");
    //printf("%-5d %-30f %-52f \n", 0,0,0);

    //print the table of j, V(j), V(j)/j! for Vo = (1 - 1/e + error)ofstream t1out("table1.txt", ios::out);
    ofstream t2out("table2.txt", ios::out);
    if(!t2out){
       cout << "Unable to open file" << endl;
    }

    for(int k = 1; k < 26; k++)
    {
        mbigV[k] = 1 - k * mbigV[k - 1];
        double moverfactorial = mbigV[k] / factorial(k);
        moverF[k] = moverfactorial;
        t2out << k << ' ' << mbigV[k] << ' ' << moverfactorial << endl;
        //printf("%-5d %-30f %-52f \n", k, mbigV[k], moverfactorial);
    }
    t2out.close();
   // cout << " " << endl;
   // cout << "Modified Formula error = .0024" << endl;
    //cout << " " << endl;

    //print modifed formula error = .0024
    double m1bigV[25];
    double m1overF[25];
    double error1 = .0024;
    double m1v0 = 1 - (1/ exp(1) + error1);
    m1bigV[0] = m1v0;
    //printf("%1s %11s %30s \n", "j","V(j)", "V(j)/j!");
    //printf("%-5d %-30f %-52f \n", 0,0,0);

    ofstream t3out("table3.txt", ios::out);
    if(!t3out){
       cout << "Unable to open file" << endl;
    }
    //print the table of j, V(j), V(j)/j! for Vo = (1 - 1/e + error)
    for(int k = 1; k < 25; k++)
    {
        m1bigV[k] = 1 - k * m1bigV[k - 1];
        double m1overfactorial = m1bigV[k] / factorial(k);
        m1overF[k] = m1overfactorial;
        t3out << k << ' ' << m1bigV[k] << ' ' << m1overfactorial << endl;
        //printf("%-5d %-30f %-52f \n", k, m1bigV[k], m1overfactorial);
    }
    t3out.close();
   // cout << " " << endl;
   // cout << "Modified Formula error = .000035" << endl;
   // cout << " " << endl;

    //print modifed formula error = .000035
    double m2bigV[25];
    double m2overF[25];
    double error2 = .0024;
    double m2v0 = 1 - (1/ exp(1) + error2);
    m2bigV[0] = m2v0;
    //printf("%1s %11s %30s \n", "j","V(j)", "V(j)/j!");
    //printf("%-5d %-30f %-52f \n", 0,0,0);

    ofstream t4out("table4.txt", ios::out);
    if(!t4out){
       cout << "Unable to open file" << endl;
    }
    //print the table of j, V(j), V(j)/j! for Vo = (1 - 1/e + error)
    for(int k = 1; k < 25; k++)
    {
        m2bigV[k] = 1 - k * m2bigV[k - 1];
        double m2overfactorial = m2bigV[k] / factorial(k);
        m2overF[k] = m2overfactorial;
        t4out << k << ' ' << m2bigV[k] << ' ' << m2overfactorial << endl;
        //printf("%-5d %-30f %-52f \n", k, m2bigV[k], m2overfactorial);
    }
}
