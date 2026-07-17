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
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x
#define all(x) x.begin(),x.end()

ll get(){
   ll x;
   cin>>x;
   return x;
}

ll ans[256][256];

void computeAns(){
    ans[0][0]=0;
    rep(i,0,8){
        rep(j,(1ll<<i),(1ll<<(i+1ll))){
            rep(k,(1ll<<i),(1ll<<(i+1ll))){
                ans[j][k]=ans[j-(1ll<<i)][k-(1ll<<i)]+(1ll<<(2ll*i))+(1ll<<(2ll*i+1ll));
                ans[j-(1ll<<i)][k]=ans[j-(1ll<<i)][k-(1ll<<i)]+(1ll<<(2ll*i+1ll));
                ans[j][k-(1ll<<i)]=ans[j-(1ll<<i)][k-(1ll<<i)]+(1ll<<(2ll*i));
            }
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    cout<<n*m<<"\n";
    rep(i,0,n){
        rep(j,0,m){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    computeAns();
    int t; cin>>t; rep(i,0,t)
    solve();
}   