#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

ll exp_mod(ll x, ll y, ll mod){
    ll tmp=1;
    while (y){
        if (y&1){
            tmp=tmp*x%mod;
        }
        x=x*x%mod;
        y>>=1;
    }
    return tmp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    // Réponse : 2*3*4^{n-3}+(n-3)*9*4^{n-4}
    if (n==3) cout << 4*(n-1)*exp_mod(3,n-2,INT64_MAX-1);
    else cout << 6LL*exp_mod(4LL,n-2LL,INT64_MAX-1)+(n-3LL)*9LL*exp_mod(4,n-3,INT64_MAX-1LL);
}