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
 
 
#define int ll
 
const int MAXN = 2e6 + 10;
int n;

void solve(){
    vi p(n);
    vi c(n);
    forn(i,n){
        cin>>p[i];
    }
    forn(i,n){
        cin>>c[i];
    }
    int m;
    cin>>m;
    vi tp(m);
    vi tc(m);
    vi d(m);
    forn(i,m) cin>>tp[i];
    forn(i,m) cin>>tc[i];
    forn(i,m) cin>>d[i];
    vi res(m);
    forn(i,m){
        res[i] = tp[i]+tc[i]+2ll*d[i];
    }

    vector<pair<pii,pii>> tab;
    int mini=E18;
    forn(i,n){
        pair<pii,pii> tmp;
        tmp.first = {p[i], 0};
        tmp.second = {c[i], i}; // 0 means its news
        tab.push_back(tmp);
    }
    forn(i,m){
        pair<pii,pii> tmp;
        tmp.first = {tp[i], -1};
        tmp.second = {tc[i], i}; // 1 means its person
        tab.push_back(tmp);
    }
    sort(all(tab));
    for (auto [cordd, indd] : tab){
        pii cord = {cordd.first, indd.first};
        pii ind = {cordd.second, indd.second};
        if (ind.first==0){
            mini = min(mini, cord.second);
        }
        else{
            if (mini!=E18){
                int person = ind.second;
                if (mini<cord.second){
                    res[person] = min(res[person], 0ll);
                }
                else if (mini<=cord.second+d[person]){
                    res[person] = min(res[person], mini);
                }
                else{
                    res[person] = min(res[person], cord.second+d[person]);
                }
            }
        }
    }

    // forn(i,m){
    //     cout<<res[i]<<"\n";
    // } cout<<"\n";

    tab.clear();
    mini=E18;
    forn(i,n){
        pair<pii,pii> tmp;
        tmp.first = {c[i], 0};
        tmp.second = {p[i], i}; // 0 means its news
        tab.push_back(tmp);
    }
    forn(i,m){
        pair<pii,pii> tmp;
        tmp.first = {tc[i], -1};
        tmp.second = {tp[i], i}; // 1 means its person
        tab.push_back(tmp);
    }
    sort(all(tab));
    for (auto [cordd, indd] : tab){
        pii cord = {cordd.first, indd.first};
        pii ind = {cordd.second, indd.second};
        if (ind.first==0){
            mini = min(mini, cord.second);
        }
        else{
            if (mini!=E18){
                int person = ind.second;
                if (mini<cord.second){
                    res[person] = min(res[person], 0ll);
                }
                else if (mini<=cord.second+d[person]){
                    res[person] = min(res[person], mini);
                }
                else{
                    res[person] = min(res[person], cord.second+d[person]);
                }
            }
        }
    }

    // forn(i,m){
    //     cout<<res[i]<<"\n";
    // } cout<<"\n";

    tab.clear();
    mini=E18;
    int minF=1e16;
    forn(i,n){
        pair<pii,pii> tmp;
        tmp.first = {p[i], 0};
        tmp.second = {c[i], i}; // 0 means its news
        tab.push_back(tmp);
    }
    forn(i,m){
        pair<pii,pii> tmp;
        tmp.first = {tp[i]+d[i], -1};
        tmp.second = {tc[i]+d[i], i}; // 1 means its person
        tab.push_back(tmp);
    }
    sort(all(tab));
    for (auto [cordd, indd] : tab){
        pii cord = {cordd.first, indd.first};
        pii ind = {cordd.second, indd.second};
        if (ind.first==0){
            mini = min(mini, cord.first+cord.second);
            minF = min(minF, cord.first);
        }
        else{
            if (mini!=E18){
                int person = ind.second;
                res[person] = min(res[person], mini);
                res[person] = min(res[person], minF+cord.second);
            }
        }
    }

    tab.clear();
    mini=E18;
    minF=1e16;
    forn(i,n){
        pair<pii,pii> tmp;
        tmp.first = {c[i], 0};
        tmp.second = {p[i], i}; // 0 means its news
        tab.push_back(tmp);
    }
    forn(i,m){
        pair<pii,pii> tmp;
        tmp.first = {tc[i]+d[i], -1};
        tmp.second = {tp[i]+d[i], i}; // 1 means its person
        tab.push_back(tmp);
    }
    sort(all(tab));
    for (auto [cordd, indd] : tab){
        pii cord = {cordd.first, indd.first};
        pii ind = {cordd.second, indd.second};
        if (ind.first==0){
            mini = min(mini, cord.first+cord.second);
            minF = min(minF, cord.first);
        }
        else{
            if (mini!=E18){
                int person = ind.second;
                res[person] = min(res[person], mini);
                res[person] = min(res[person], minF+cord.second);
            }
        }
    }

    forn(i,m){
        cout<<res[i]<<"\n";
    }
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //int ttt; cin>>ttt;
    while (cin>>n) solve();
}