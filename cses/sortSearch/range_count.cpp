#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
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

vector<tuple<int,int,int>> ranges;
int res1[MAXN];
int res2[MAXN];


typedef tree<
    pii,
    null_type,
    less<pii>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;

// res1 : same, rank query
// res2 : its really just querying the rank of -(current closing bracket) with increasing opening

void solve(){
    ranges.resize(n);
    forn(i,n){
        cin>>T(ranges[i], 0);
        cin>>T(ranges[i], 1);
        T(ranges[i], 2)=i;
        res1[i]=res2[i]=0;
    }
    sort(all(ranges), [](const tuple<int,int,int>& a, const tuple<int,int,int>& b){
        if (T(a,0)==T(b,0)) return T(a,1)>T(b,1); else return a<b;
    });
    ordered_set st;
    for (int i=0;i<n;i++){
        var(T(ranges[i], 2))
        res2[T(ranges[i], 2)] = st.order_of_key({-T(ranges[i], 1), E18});
        st.insert({-T(ranges[i], 1), i});
    }
    st.clear();
    for (int i=n-1;i>=0;i--){
        res1[T(ranges[i], 2)] = st.order_of_key({T(ranges[i], 1), E18});
        st.insert({T(ranges[i], 1), i});
    }
    forn(i,n){
        cout<<res1[i]<<" ";
    }
    cout<<"\n";
    forn(i,n){
        cout<<res2[i]<<" ";
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