#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>
#define loop(n) for(int i=0;i<n;i++)

void dfs(vector<int>& vu, vector<vector<pair<int,int>>> adj, vector<int>& v, int s){
    for (auto vois : adj[s]){
        if (vu[vois.first]==-1){
            vu[vois.first]=0;
            dfs(vu,adj,v,vois.first);
            vu[s]+=(vois.second*abs(v[vois.first]))+vu[vois.first];
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for (auto& x : v)cin>>x;
    vector<vector<pair<int,int>>> adj(n);
    int u,y,w;
    for (int i=0;i<n-1;i++){
        cin>>u;
        cin>>y;
        cin>>w;
        u--;y--;
        adj[u].push_back({y,w});
        adj[y].push_back({u,w});
    }
    vector<int> vu(n,-1);
    vu[0]=0;
    dfs(vu,adj,v,0);
    for (auto x : vu) cout << x << " ";
}