#include <bits/stdc++.h>
using namespace std;

int find_set(int v, vector<int>& parent) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}

void make_set(int v, vector<int>& parent, vector<int>& size) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b, vector<int>& parent, vector<int>& size) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

bool try_kuhn(int v, vector<vector<int>>& g, vector<int>& mt, vector<int>& used) {
    if (used[v])
        return false;
    used[v] = true;
    for (int to : g[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to], g, mt, used)) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> parent(n*m), size(n*m);
    for (int i = 0; i < n*m; ++i) {
        make_set(i, parent, size);
    }

    vector<vector<int>> grid(n,vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> adj(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j!=m-1){
                if (grid[i][j] == grid[i][j + 1]) {
                    union_sets(i * m + j, i * m + j + 1, parent, size);
                }
                else{
                    adj[i * m + j].push_back(i * m + j + 1);
                    adj[i * m + j + 1].push_back(i * m + j);
                }
            }
            if (i != n - 1) {
                if (grid[i][j] == grid[i + 1][j]) {
                    union_sets(i * m + j, (i + 1) * m + j, parent, size);
                }
                else{
                    adj[i * m + j].push_back((i + 1) * m + j);
                    adj[(i + 1) * m + j].push_back(i * m + j);
                }
            }
        }
    }

    vector<vector<int>> aretePrinc(n*m);
    for (int i = 0; i < n * m; ++i) {
        int root = find_set(i, parent);
        for (auto neighbor : adj[i]){
            aretePrinc[root].push_back(find_set(neighbor, parent));
            aretePrinc[find_set(neighbor, parent)].push_back(root);
        }
    }

    vector<int> matching(n * m, -1);
    vector<int> used(n * m, 0);
    for (int i = 0; i < n * m; ++i) {
        used.assign(n * m, 0);
        (try_kuhn(i, aretePrinc, matching, used));
    }
    int ans = 0;
    for (int i = 0; i < n * m; ++i) {
        if (matching[i] != -1) {
            ans++;
        }
    }
    cout<<ans/2<<"\n";
}