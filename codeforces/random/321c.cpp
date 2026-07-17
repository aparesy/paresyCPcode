#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
 
#ifdef DEBUG
 
#define var(x) cerr << #x << ": " << x << '\n';
#define range(a, b) cerr << #a << ", " << #b << ": "; for (auto _it = a; _it != b; ++_it) cerr << *_it << ' '; cerr << '\n';
#else
#define var(x)
#define range(a, b)
#define cerr if (false) cerr
#endif
 
#define vi vector<int>
#define vii vector<pii>
#define forn(i, n) for (int i = 0; i < n; i++) 
#define F first
#define S second
#define T(x, i) get<i>(x)
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define rep(i,a,b) for (int i = a; i < b; i++)
#define sz(v) int(v.size())

const int E2 = 100, E3 = 1000, E4 = 10000, E5 = 100000, E6 = 1000000, E9 = 1000000000;
const ll E18 = 1ll * E9 * E9;
const int FFT_MOD = 998244353;
const int SIMPLE_MOD = E9 + 7;
mt19937 rng(time(0));
 
 
#define int ll
 
const int MAXN = 2e6 + 10;
int n;


vector<vector<int>> adj;

vector<bool> is_removed;

vector<int> subtree_size;
vector<char> r;

/** DFS to calculate the size of the subtree rooted at `node` */

int get_subtree_size(int node, int parent = -1) {

	subtree_size[node] = 1;

	for (int child : adj[node]) {

		if (child == parent || is_removed[child]) { continue; }

		subtree_size[node] += get_subtree_size(child, node);

	}

	return subtree_size[node];

}


/**

 * Returns a centroid (a tree may have two centroids) of the subtree

 * containing node `node` after node removals

 * @param node current node

 * @param tree_size size of current subtree after node removals

 * @param parent parent of u

 * @return first centroid found

 */

int get_centroid(int node, int tree_size, int parent = -1) {

	for (int child : adj[node]) {

		if (child == parent || is_removed[child]) { continue; }

		if (subtree_size[child] * 2 > tree_size) {

			return get_centroid(child, tree_size, node);

		}

	}

	return node;

}


/** Build up the centroid decomposition recursively */

void build_centroid_decomp(int node = 0, int depth=0) {

	int centroid = get_centroid(node, get_subtree_size(node));


	r[centroid] = 'A'+depth;


	is_removed[centroid] = true;


	for (int child : adj[centroid]) {

		if (is_removed[child]) { continue; }

		build_centroid_decomp(child, depth+1);

	}

}

map<pii,int> mp;

int dfs(vector<vi>& adj, int s, int p){
    int tot=1;
    for (auto x : adj[s]){
        if (x!=p){
            int y=dfs(adj,x,s);
            mp[{s,x}]=y;
            tot+=y;
        }
    }
    return tot;
}

void solve(){
    adj.resize(n);
    r.resize(n);
    is_removed.resize(n);
    subtree_size.resize(n);
    forn(i,n-1){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    build_centroid_decomp(0,0);
    forn(i,n){
        cout<<r[i]<<" ";
    }
    cout<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin>>n) solve();
}