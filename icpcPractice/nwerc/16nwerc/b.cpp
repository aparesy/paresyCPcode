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

void dfs(int s, vi& dfsorder, vb& vu, vvi& adj){
    for (auto t : adj[s]){
        if (!vu[t]){
            vu[t]=true;
            dfs(t,dfsorder,vu,adj);
        }
    }
    dfsorder.push_back(s);
}

void buildScc(int s, vvi& adjRev, vb& vu, vi& sccId, int tot, vvi& scc){
    for (auto t : adjRev[s]){
        if (!vu[t]){
            vu[t]=true;
            sccId[t]=tot;
            scc[tot].push_back(t);
            buildScc(t,adjRev,vu,sccId,tot,scc);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vvi adj(n+1);
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    //Default algorithm (without loops) : find the longest path in a dag via dp i think (yes dp) : go through the nodes in topo order.
    // Here : cycles of length at least 4. We don't really want to take cycles in most cases though. Impossibility of topological order ?
    // Mybe regroup nodes that form a cycle. Then its scc search and dp on the sccs. The dp is a bit hard though


    vi dfsorder(n);
    vb vu(n+1);
    rep(i,1,n+1){
        if (!vu[i]){
            vu[i]=true;
            dfs(i,dfsorder,vu,adj);
        }
    }
    reverse(dfsorder.begin(), dfsorder.end());

    vvi adjRev(n+1);
    rep(i,0,n+1){
        for (auto s : adj[i]){
            adjRev[s].push_back(i);
        }
    }

    vu.assign(n+1,false);
    int tot=0;
    vi sccId(n+1);
    vvi scc;
    for (auto s : dfsorder){
        if (!vu[s]){
            vu[s]=true;
            sccId[s]=tot;
            scc.push_back({s});
            buildScc(s,adjRev,vu,sccId,tot,scc);
            tot++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}