#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x

ll f(ll m, ll a, ll b, ll n){
    return (n-m)*a + b*(b+1)/2LL - (b-m)*(b-m+1)/2LL;
}

void solve(){
    ll n,a,b;
    cin>>n>>a>>b;
    ll l=0;
    ll r=n+1;
    while (r-l>2){
        ll m1=l+(r-l)/3LL;
        ll m2=r-(r-l)/3LL;
        if (f(m1,a,b,n) > f(m2,a,b,n)){
            r=m2;
        }
        else l=m1;
    }
    if (f(l,a,b,n)>f(l+1LL,a,b,n))
    cout<<f(l,a,b,n)<<"\n";
    else cout<<f(l+1LL,a,b,n)<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}