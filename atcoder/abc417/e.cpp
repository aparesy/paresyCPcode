#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

bool dfs(vector<vector<int>>& adj, vector<int>& path, vector<bool>& vu, int x, int y){
    if (x==y) return true;
    for (int s : adj[x]){
        if (!vu[s]){
            vu[s]=true;
            if (dfs(adj, path, vu, s, y)){
                path.push_back(s);
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll m;
        cin>>m;
        int x,y;
        cin>>x>>y;
        int u,v;
        vector<vector<int>> adj(n+1);
        for (int i=0;i<m;i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i=0;i<n+1;i++){
            sort(adj[i].begin(), adj[i].end());
        }
        vector<int> path;
        vector<bool> vu(n+1,false);
        vu[x]=true;
        dfs(adj, path, vu, x, y);
        path.push_back(x);
        for (int i=path.size()-1;i>=0;i--) cout<<path[i]<<" ";
        cout<<endl;
    }
}