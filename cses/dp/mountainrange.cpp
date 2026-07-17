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

const int E2 = 100, E3 = 1000, E4 = 10000, E5 = 100000, E6 = 1000000, E9 = 1e9;
const ll E18 = 1ll * E9 * E9;
const int FFT_MOD = 998244353;
const int SIMPLE_MOD = E9 + 7;
mt19937 rng(time(0));
 
 
#define int ll
 
const int MAXN = 2e6 + 10;
int n;

void solve(){
    vi tab(n);
    forn(i,n) cin>>tab[i];
    // ok from top to bottom
    set<pii, greater<pii>> st;
    forn(i,n){
        st.insert({tab[i], i});
    }
    set<pair<pii,pii>> seg;
    seg.insert({make_pair(0,n), make_pair(0,E18)}); //start, stop, size, height
    forn(i,n){
        auto [h, pos] = *st.begin();
        st.erase(*st.begin());
        // get the segment in which pos is contained
        auto it=seg.lower_bound({make_pair(pos,E18), make_pair(-E18, -E18)});
        it--;
        auto [bornes, autres] = *it;
        seg.erase(*it);
        auto [l,r] = bornes;
        auto [nb, h2] = autres;
        if (h2==h){
            seg.insert({make_pair(l,pos), make_pair(nb, h)}); 
            seg.insert({make_pair(pos,r), make_pair(nb, h)}); 
        }
        else{
            seg.insert({make_pair(l,pos), make_pair(nb+1, h)}); 
            seg.insert({make_pair(pos,r), make_pair(nb+1, h)}); 
        }
    }

    int maxi=0;
    for(auto [a,b] : seg){
        //cout<<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second<<"\n";
        maxi=max(maxi, b.first);
    }
    cout<<maxi<<"\n";
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