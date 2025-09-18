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
    int n;
    cin>>n;
    ll mod=1e9+7LL; 
    vector<vector<char>> grid(n,vector<char>(n));
    rep(i,0,n){
        rep(j,0,n){
            cin>>grid[i][j];
        }
    }
    vector<vl> poss(n,vl(n));
    poss[0][0]=1;
    rep(i,0,n){
        rep(j,0,n){
            if (i){
                poss[i][j]+=poss[i-1][j];
            }
            if (j) poss[i][j]+=poss[i][j-1];
            poss[i][j]%=mod;
            if (grid[i][j]=='*') poss[i][j]=0;
        }
    }
    cout<<poss[n-1][n-1];
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}