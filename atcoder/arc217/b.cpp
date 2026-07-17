#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>     
#include <ext/pb_ds/tree_policy.hpp>  

using namespace __gnu_pbds;

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
#define vvi vector<vector<int>>
#define vvii vector<vii>
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
 
using ordered_set=tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
 
#define int ll
 
const int MAXN = 2e6 + 10;
int n;

int sum_to(int x){
    return x*(x+1ll)/2;
}

void solve(){
    int k;
    cin>>k;
    vi a(k);
    forn(i,k) cin>>a[i];

    // Each number contributes for 1 + 2 + ... + rank(x) operations

    ordered_set st;
    int tot=0;
    int maxi=0;
    set<int> st;
    for (int i=0;i<k;i++){
        if (a[i]<maxi){
            tot+=sum_to(st.order_of_key(a[i])+1);
        }
        maxi=max(maxi,a[i]);
    }
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ttt; cin>>ttt;
    while (cin>>n) solve();
}