#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for (int i = 0; i < t; ++i) {
        cout<< "Scenario #" << i + 1 << ":\n";
        ll n;
        cin>>n;
        vector<vector<int>> adj(n+1);
        ll m;
        cin>>m;
        int u,v;
        for(int i=0; i<m; i++){
            cin>>u>>v;
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

        cout << (is_bipartite ? "No suspicious bugs found!" : "Suspicious bugs found!") << "\n";
    }
}

