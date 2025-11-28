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
#define M_PI 3.14159265358979323846

ll get(){
   ll x;
   cin>>x;
   return x;
}


void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<double,double>>> adj(n+1,vector<pair<double,double>>(m));
    vector<vector<pair<double,double>>> adj2(n,vector<pair<double,double>>(m+1));
    vector<string> grid(n);
    input(grid);
    rep(i,0,n){ 
        rep(j,0,m){
            if (j!=m-1) adj[i][j].first=1;
            adj[i][j].second=1;
            if (grid[i][j]=='O') adj[i][j].second=M_PI/4.;

            if (i!=n-1) adj2[i][j].second=1.;
            adj2[i][j].first=1.;
            if (grid[i][j]=='O') adj2[i][j].first=M_PI/4.;
        }
    }

    rep(j,0,m-1){
        adj[n][j].first=1.; //bottom row
    }

    rep(i,0,n-1){
        adj2[i][m].second=1.;
    }

    rep(i,0,n){
        adj[i][m-1].second=1.;
        if (grid[i][m-1]=='O') adj[i][m-1].second=M_PI/4.;
    }

    rep(j,0,m){
        adj2[n-1][j].first=1.;
        if (grid[n-1][j]=='O') adj2[n-1][j].first=M_PI/4.;
    }
    // = 0 if theres no neighbor

    vector<vb> vu(n+1,vb(m));
    vector<vb> vu2(n,vb(m+1));
    priority_queue<pair<pair<double,int>, pair<int,int>>, vector<pair<pair<double,int>, pair<int,int>>>, greater<pair<pair<double,int>, pair<int,int>>>> q;

    q.push({make_pair(0.5,1), make_pair(0,0)});
    q.push({make_pair(0.5,2), make_pair(0,0)});
    while (!q.empty()){
        auto [config, coord] = q.top();
        q.pop();
        auto [dist, indGrid] = config;
        auto [x,y] = coord;
        if (indGrid==1){
            if (vu[x][y]) continue;
            else vu[x][y]=true;
        }
        else{
            if (vu2[x][y]) continue;
            else vu2[x][y]=true;
        } 
        if (indGrid==1 && x==n && y==m-1){
            cout<<fixed<<setprecision(8)<<(dist+0.5)*10.;
            return;
        }
        if (indGrid==2 && x==n-1 && y==m){
            cout<<fixed<<setprecision(8)<<(dist+0.5)*10.;
            return;            
        }

        if (indGrid==1){
            if (adj[x][y].first && !vu[x][y+1]){
                q.push({make_pair(dist+adj[x][y].first, 1), make_pair(x,y+1)});
            }
            if (adj[x][y].second && !vu2[x][y+1]){
                q.push({make_pair(dist+adj[x][y].second, 2), make_pair(x,y+1)});
            }
        }
        else{
            if (adj2[x][y].first && !vu[x+1][y]){
                q.push({make_pair(dist+adj2[x][y].first, 1), make_pair(x+1,y)});
            }
            if (adj2[x][y].second && !vu2[x+1][y]){
                q.push({make_pair(dist+adj2[x][y].second, 2), make_pair(x+1,y)});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}