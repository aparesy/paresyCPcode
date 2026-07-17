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
 
 
#define int ll
 
const int MAXN = 2e6 + 10;
int n,k;
 
vector<pii> ra;
 
void solve(){
    forn(i,n){
        int a,b;
        cin>>a>>b;
        ra.push_back({b,a});
    }
    int tot=0;
    sort(all(ra));
    set<pii> next_start;
    forn(i,n){
        auto [b,a] = ra[i];
        if (next_start.size()==k && a<(*next_start.begin()).first) continue;
        else{
            if(!next_start.empty() && a>=(*next_start.begin()).first){
                auto it = next_start.lower_bound({a,E18});
                it--;
                next_start.erase(*it);
            }
            //  cout<<a<<" "<<b<<"\n";
            next_start.insert({b,i});
            tot++;
        }
    }
    cout<<tot;
}
 
signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin.tie(0);
    while(cin>>n>>k) solve();
}