#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll unsigned long long
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define rep(i,a,b) for(int i=a;i<b;i++)

pair<ll,ll> fib (ll n, ll mod) {
    if (n == 0LL)
        return {0LL, 1LL};

    pair<ll,ll> p = fib(n >> 1LL,mod);
    ll c = (p.first * (2LL * p.second%mod - p.first+mod)%mod)%mod;
    ll d = (p.first * p.first %mod+ p.second * p.second%mod)%mod;
    if (n & 1LL)
        return {d, (c + d)%mod};
    else
        return {c, d};
}

void solve(){
    ll n;
    cin>>n;
    ll mod= 1000000007LL;
    cout<<fib(n,mod).first<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}