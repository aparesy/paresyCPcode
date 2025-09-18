#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

// void print_binary(int n, int base){
//     while(base){
//         base--;
//         cout << ((n>>base)&1);
//     }
// }

// void test1(){
//     print_binary(56, 8);
// }

// int gray(int n){
//     return n^(n>>1); 
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int gi,gj;
    int an=1<<n;
    int am=1<<m;
    for (int i=0; i!=an; i++){
        gi=i^(i>>1);
        for (int j=0; j!=am; j++){
            gj=j^(j>>1);
//            print_binary(gray(i) + gray(j)*(1<<n), n+m);
            cout << gi + gj*an << " ";
        }
        cout << "\n";
    }
}