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

void solveRec(ll h, ll d, unordered_map<ll,unordered_map<ll,ll>>& dp){
    // Never called with h=0
    if (dp[h][d]) return;
    if (h==0) return;
    if (d==0){
        dp[h][d]=0;
        return;
    }
    ll step=1;
    ll mini=9999999999LL;
    while (d-step>=0 && step*(step+1LL)/2LL<h){
        solveRec(h-step*(step+1LL)/2LL+1,d-step,dp);
        mini=min(mini,dp[h-step*(step+1LL)/2LL+1][d-step]+step+1);
        step++;
    }
    // solveRec(h,d-1,dp);
    // mini=min(mini,dp[h][d-1]+2);
    dp[h][d]=mini;
}

void solve(){
    ll h,d;
    cin>>h>>d;
    unordered_map<ll,unordered_map<ll,ll>> dp;
    ll tot=2LL*d;
    int step=2;
    ll liaisons = d;
    while(h){
        if (liaisons/step )
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    rep(i,0,n)
    solve();
}