#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        ll x,y,z;
        cin >>x>>y>>z;
        if (x>=z && x>=(y+((ll)1))/(ll)2 && (y%2==0 || z!=0)) cout << "Yes" ;else cout << "No";
        cout << endl;
    }
}