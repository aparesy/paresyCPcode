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
 
#include <bits/extc++.h> // pbds
using namespace __gnu_pbds;
typedef tree<pii, null_type, less<pii>, rb_tree_tag,
tree_order_statistics_node_update> ost;
 
#define int ll
 
const int MAXN = 2e6 + 10;
int n;

ost t;

void solve(){
    t.clear();
    cin>>n;
    int tot=0;
    int tot2=0;
    vector<int> tab;
    rep(i,0,n){
        int tmp;
        cin>>tmp;
        t.insert({tmp,i});
        int l=t.size();
        if (l%2){
            tot+=(*t.find_by_order(l/2)).first;
        }
        else{
            tot+=((*t.find_by_order((l-1)/2)).first+(*t.find_by_order(l/2)).first)/2ll;
        }
    }

    cout<<tot<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin.tie(0);
    int _t;
    cin >> _t;
    rep(i,0,_t) {
        solve();
    }
}