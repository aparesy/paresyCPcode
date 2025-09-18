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
    vvi grid(n,vi(n,-1));
    vii moves{{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
    queue<pii> q;
    q.push({0,0});
    grid[0][0]=0;
    while (!q.empty()){
        pii cur=q.front();
        q.pop();
        for (auto move : moves){
            if (0<=cur.F+move.F && cur.F+move.F<n && 0<=cur.S+move.S && cur.S+move.S<n && grid[cur.F+move.F][cur.S+move.S]==-1){
                grid[cur.F+move.F][cur.S+move.S]=grid[cur.F][cur.S]+1;
                q.push({cur.F+move.F,cur.S+move.S});
            }
        }
    }
    rep(i,0,n){
        rep(j,0,n){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}