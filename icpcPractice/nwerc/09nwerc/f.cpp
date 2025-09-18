#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define rep(i,a,b) for(int i=a;i<b;i++)

ll dfs(int s,vector<vii>& adj, vector<ll>& poids_arbre, vector<bool>& vu, vi& poids_sommet){
    for (auto tpoids : adj[s]){
        if (!vu[tpoids.first]){
            vu[tpoids.first]=true;
            poids_arbre[s] += dfs(tpoids.first,adj,poids_arbre,vu,poids_sommet);
        }
    }
    poids_arbre[s]+=(ll)poids_sommet[s];
    return poids_arbre[s];
}

void solve(){
    int n;
    cin>>n;
    vector<vii> adj(n+1); // Liste d'adjacence avec pour chaque sommet s, l'arete {t, poids} (oui t est un très mauvais nom)
    rep(i,0,n-1){
        int s,t,poids;
        cin>>s>>t>>poids;
        adj[s].push_back({t,poids});
        adj[t].push_back({s,poids});
    }
    int m;
    cin>>m;
    vector<int> poids_sommet(n+1,0);
    rep(i,0,m){
        int s,f;
        cin>>s>>f;
        poids_sommet[s]=f;
    }

    vector<ll> poids_arbre(n+1,0);
    vector<bool> vu(n+1,false);
    vu[1]=true;
    poids_arbre[1]=dfs(1,adj,poids_arbre,vu,poids_sommet);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}