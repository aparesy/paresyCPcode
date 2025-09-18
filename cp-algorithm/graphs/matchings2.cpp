#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    ll m;
    cin>>m;
    int u,v;
    vector<pair<int, int>> edges;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        edges.push_back({u, v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> side(n+1, -1);
    bool is_bipartite = true;
    queue<int> q;
    for (int st = 1; st < n+1; ++st) {
        if (side[st] == -1) {
            q.push(st);
            side[st] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : adj[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    } else {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
    }
    if (is_bipartite) {
        cout << "YES\n";
        for (int i = 0; i <m; ++i) {
            cout << side[edges[i].first];
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }
}   