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

ll invmod(ll x, ll m){
    if (x<=1) return x%m;
    return m - (long long)(m/x) * invmod(m % x,m) % m;
}

void solve(){
    ll n;
    cin>>n;
    vl tab(n);
    input(tab);
    ll mod=1e9+7LL; ll tot=0LL;
    ll somme=0LL;
    rep(i,0,n){
        somme+=tab[i];
        somme%=mod;
    }
    rep(i,0,n){
        ll tmp=((somme-tab[i])%mod)*(tab[i]%mod)%mod;
        tot+=tmp;
        tot%=mod;
    }
    ll div=n*(n-1LL); div%=mod;
    cout<<((tot*invmod(div,mod)%mod)+mod)%mod<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}