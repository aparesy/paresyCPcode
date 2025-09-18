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

void solve(){
    ll n;
    cin>>n;
    vl dp(max(n+1LL,10LL));
    dp[0]=0;dp[1]=1;dp[2]=2;dp[3]=4;dp[4]=8;dp[5]=16;dp[6]=32;
    rep(i,7,n+1){
        dp[i]=(dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6])%((ll)1e9+7LL);
    }
    cout<<dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}