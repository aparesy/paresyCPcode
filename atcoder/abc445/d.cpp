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
int h,w,n;

void solve(){
    multiset<pii> piecesH;
    multiset<pii> piecesV;
    map<pair<pii,int>, int> mp;
    forn(i,n){
        int a,b;
        cin>>a>>b;
        piecesH.insert({a,b});
        piecesV.insert({b,a});
        mp[{make_pair(a,b),i}]=i;
    }
    vii res(n);
    pii cur={0,0};
    forn(i,n){
        var(i);
        auto it = piecesH.lower_bound({h-cur.first,0});
        if (it!=piecesH.end() && (*it).first == h-cur.first){
            auto [a,b] = (*it);
            piecesH.erase(it);
            it = piecesV.lower_bound({b,a});
            piecesV.erase(it);
            auto it2 = mp.lower_bound({make_pair(a,b), 0});
            auto x = *it2;
            res[mp[x.first]] = {cur.first+1, cur.second+1};
            mp.erase(it2);
            cur.second+=b; 
        }
        else{
            var(cur.first)
            var(cur.second);
            it = piecesV.lower_bound({w-cur.second, 0});
            auto [b,a] = (*it);
            piecesV.erase(it);
            it = piecesH.find({a,b});
            piecesH.erase(it);
            auto it2 = mp.lower_bound({make_pair(a,b), 0});
            auto x = *it2;
            res[mp[x.first]] = {cur.first+1, cur.second+1};
            mp.erase(it2);
            cur.first+=a;
        }
    }

    for (auto x : res) cout<<x.first<<" "<<x.second<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin>>h>>w>>n) solve();
}