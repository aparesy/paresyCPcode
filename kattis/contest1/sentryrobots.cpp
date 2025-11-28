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

struct point{
    int py; int px;
};

void solve(){
    int y,x;
    cin>>y>>x;
    int p;
    cin>>p;
    vector<point> points(p);
    rep(i,0,p){
        int a,b;
        cin>>a>>b;
        points[i]={a,b};
    }
    int w=get();
    vector<point> obstacle(w);
    rep(i,0,w){
        int a,b;
        cin>>a>>b;
        obstacle[i]={a,b};
    }
    // On construit un graphe bipartite de taille p+(nb de segments
    vector<vector<int>> grid(y,vi(x));
    rep(i,0,w){
        grid[obstacle[i].py][obstacle[i].px]=1;
    }
    int nbH=0;
    vector<vector<int>> adj;
    map<int,pair<int,int>>
    rep(i,0,y){
        nbH++;
        int j=0;
        while (j<x && grid[i][j]) j++;
        adj.push_back(vi());
        while(j<n){
            while (!grid[i][j])j++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}