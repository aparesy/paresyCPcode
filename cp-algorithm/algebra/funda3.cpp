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
   int t;
   cin>>t;
   while(t--){
      ll n;
      cin>>n;
      ll k;
      cin>>k;
      
   }
}