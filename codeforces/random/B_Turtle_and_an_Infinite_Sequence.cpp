// Useful functions : nth_element, rotate, unique, merge, count, generate

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
using ll=long long;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x
#define all(x) x.begin(),x.end()

ll get(){
   ll x;
   cin>>x;
   return x;
}

bool reachable(ll i, ll n, ll m){
    // Find out if in the range (n-m, n+m) included the bit is activated
    ll lbound=max(0ll, n-m);
    ll span=m+n-lbound+1ll;
    if (span > (1ll<<i)) return true;
    if ((lbound>>i)&1ll) return true;
    if (((n+m)>>i)&1ll) return true;
    return false;
}

void solve(){
    ll n,m;
    cin>>n>>m;  
    // foreach bit find if it is reachable, there are like 32 bits

    ll res=0;
    rep(i,0,32){
        if (reachable(i,n,m)) res|=(1ll<<((ll)i));
    }
    cout<<res<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}