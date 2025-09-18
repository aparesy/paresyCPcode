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
    int n,l;
    cin>>n>>l;
    int m;
    cin>>m;
    vi tab(m);
    input(tab);
    sort(tab.begin(),tab.end());
    vi dp(n+1);
    rep(i,0,l){
        dp[i]=0;
    }
    rep(i,l,n+1){
        dp[i]=dp[i-l]+1;
        if (binary_search(tab.begin(),tab.end(), i-l+1)){
            dp[i]=dp[i-l]+2;
        }
        rep(j,1,l){
            dp[i]=max(dp[i],dp[i-j]);
        }
    }
    cout<<dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}