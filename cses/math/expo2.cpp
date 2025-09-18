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

ll expo(ll a, ll b,ll mod){
        ll cur=1LL;
        while (b){
        if (b&1LL){
            cur*=a;
            cur%=mod;
        }
        a*=a;
        a%=mod;
        b>>=1LL;
    }
        return cur;
}

void solve(){
    ll a,b,c;
    cin>>a>>b>>c;
    ll mod=1e9+7LL;
    cout<<expo(a,expo(b,c,mod-1LL),mod)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}