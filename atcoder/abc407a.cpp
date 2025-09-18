#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,y;
    cin >> x >> y;
    long double tot=0.;
    for (int i=1;i<7;i++){
        for (int j=1;j<7;j++){
            if (i+j<x && abs(i-j)<y)tot+=(long double)( 1.);
        }
    }
    cout<< std::setprecision(15) << (long double)(1.)-(long double)(tot)/(long double)36.;
}