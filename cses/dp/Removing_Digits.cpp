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

vi digits(int n){
    vi tmp;
    while(n>0){
        tmp.push_back(n%10);
        n/=10;
    }
    return tmp;
}

void solve(){
    int n;
    cin>>n; 
    vi dp(n+1);
    dp[0]=0;
    rep(i,0,n){
        dp[i+1]=9999999;
        for (auto s : digits(i+1)){
            dp[i+1]=min(dp[i+1],1+dp[i+1-s]);
        }
    }
    cout<<dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}