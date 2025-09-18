#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define rep(i,a,b) for(int i=a;i<b;i++)

void dfs(int s, vi& ordre, vector<bool>& vu, vvi& adj){
    for (auto t : adj[s]){
        if (!vu[t]){
            vu[t]=true;
            dfs(t, ordre, vu, adj);
        }
    }
    ordre.push_back(s);
}

void dfs2(int s, int totCC, vi& cc, vector<bool>& vu, vvi& adjRev){
    for (auto t : adjRev[s]){
        if (!vu[t]){
            vu[t]=true;
            cc[t]=totCC;
            dfs2(t,totCC,cc,vu,adjRev);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vi ordre;
    vector<bool> vu(n+1,false);
    rep(i,1,n+1){
        if (!vu[i]){
            vu[i]=true;
            dfs(i, ordre, vu, adj);
        }
    }

    vvi adjRev(n+1);
    rep(i,1,n+1) for (auto t : adj[i]) adjRev[t].push_back(i);

    int totCC=0;
    vu.assign(n+1,false);
    vi cc(n+1);
    rep(i,0,n){
        int s=ordre[n-1-i];
        if (!vu[s]){
            vu[s]=true;
            totCC++;
            cc[s]=totCC;
            dfs2(s, totCC, cc, vu, adjRev);
        }
    }

    // Build metagraph (adjMeta) for SCCs
    vector<vector<int>> adjMeta(totCC+1);
    vector<bool> hasOut(totCC+1, false), hasIn(totCC+1, false);
    rep(i,1,n+1){
        for (auto t : adj[i]){
            if (cc[t] != cc[i]){
                adjMeta[cc[i]].push_back(cc[t]);
            }
        }
    }
    // Remove duplicate edges in adjMeta
    for (int i = 1; i <= totCC; ++i) {
        sort(adjMeta[i].begin(), adjMeta[i].end());
        adjMeta[i].erase(unique(adjMeta[i].begin(), adjMeta[i].end()), adjMeta[i].end());
    }
    // Calculate sources and sinks in the metagraph
    for (int i = 1; i <= totCC; ++i) {
        for (int t : adjMeta[i]) {
            hasOut[i] = true;
            hasIn[t] = true;
        }
    }
    int sources = 0, sinks = 0;
    for (int i = 1; i <= totCC; ++i) {
        if (!hasIn[i]) sources++;
        if (!hasOut[i]) sinks++;
    }
    cout << (totCC == 1 ? 0 : max(sources, sinks)) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}