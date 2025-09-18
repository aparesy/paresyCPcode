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
#define rep(i,a,b) for(int i=a;i<b;i++)

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    rep(i,0,n){
        rep(j,0,m){
            cin>>grid[i][j];
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}