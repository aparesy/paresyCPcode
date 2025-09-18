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


void djikstra(int src, vector<vii> &adj, vi &dist, vi &parent){
    dist[src]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(d>dist[u]) continue;
        for(auto [w,v]:adj[u]){
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                parent[v]=u;
                pq.push({dist[v],v});
            }
        }
    }
}

void solve(){
    //suurballe
    int v,e;
    cin>>v>>e;
    vector<vii> adj(2*v+1);
    rep(i,1,v+1){
        adj[i].push_back({0,v+i});
    }
    rep(i,0,e){
        int a,b,c; cin>>a>>b>>c;
        adj[a+v].push_back({c,b});
    }
    vi dist(2*v+1,INT_MAX);
    vi parent(2*v+1,-1);
    djikstra(1,adj,dist,parent);
    
    int cur=v;
    while(cur!=1){
        for (auto &[w,to]:adj[parent[cur]]){
            if(to==cur){
                w=-1;
                break;
            }
        }
        cur=parent[cur];
    }

    vector<vii> adj2(2*v+1);
    rep(i,1,2*v+1){
        for(auto [w,to]:adj[i]){
            if(w!=-1){
                adj2[i].push_back({w-dist[to]+dist[i],to});
            }
            else{
                adj2[to].push_back({0,i});
            
            }
        }
    }

    dist.assign(2*v+1,INT_MAX);
    vi parent2(2*v+1,-1);
    djikstra(1,adj2,dist,parent2);

    int cur=v;
    while (cur!=1){
        if (parent[parent2[cur]]==cur){
            parent2[cur]=parent[cur];
            parent[cur]=-1;
        }
        cur=parent2[cur];
    }

    ll tot=0;
    int cur2=v;
    while(cur2!=1){
        for(auto [w,to]:adj[parent2[cur2]]){
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}