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

bool dp[1000001];

ll NMAX=1000001;

void buildAux(ll k, ll cur, ll leaves){
    if (cur>=NMAX) return;
    dp[cur]=true;
   // cout<<cur+k*leaves<<"COMES FROM "<<k<<" "<<cur<<" "<<leaves<<endl;
    buildAux(k, cur+k*leaves, k*leaves); 
    // cout<<cur+k+k*k+k*leaves<<"COMES FROM "<<k<<" "<<cur<<" "<<leaves<<endl;
    // buildAux(k, cur+k+k*k+leaves*k, k*k+leaves*k); 
}

void build(){
    fill(dp,dp+NMAX, false);
    rep(k,2,1001){
        buildAux(k,1ll+k+k*k, k*k);
    }
}

bool solve(){
    int n;
    cin>>n;
    if (n<3) return false;
    if (dp[n]) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    build();
//    rep(i,0,100) cout<<dp[i]<<" ";
    int t; cin>>t; rep(i,0,t)
    if (solve()) cout<<"YES\n"; else cout<<"NO\n";
}