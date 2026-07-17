#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>

int main(){
    ll MOD = (ll)(pow(10,9))+7LL;

    int n,m;
    cin>>n>>m;
    vl a(n);
    vl l(m);
    vl r(m);
    vl k(m);
    for (auto& x : a) cin>>x;
    unordered_map<int, vi> commence;
    unordered_map<int,vi> finit;
    for (int i=0;i<m;i++){
        ll a,b,c; cin>>a>>b>>c;
        l[i]=a;r[i]=b;k[i]=c;
        commence[l[i]-1].push_back(i);
        finit[r[i]].push_back(i);
    }
    ll cumsum=0;
    for (int i=0;i<n;i++){
        ll res = a[i]+cumsum;
        res%=MOD;
        for (ll x : commence[i]){
            res+=1;
        }
        res+=cumsum;
        for (ll x : finit[i]){
            res-=binom((r[i]-l[i]+1LL), k[i]);
        }
        
    }
}