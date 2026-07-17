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
    int k;
    cin>>k;
    vi tab(n);
    forn(i,n) cin>>tab[i];
    vi spec(k);
    vector<pair<bool,bool>> ok(n);
    forn(i,k){
        cin>>spec[i];
        spec[i]--;
        ok[spec[i]].first=ok[spec[i]].second=true;
    }
    bool change=false;
    forn(i,n){
        if (ok[i].first){
            if (!change){
                ok[i].first=false;
            }
            else{
                change=false;
            }
        }
        if (i<n-1 && tab[i]!=tab[i+1]){
            change=true;
        }
    }
    change=false;
    for(int i=n-1;i>=0;i--){
        if (ok[i].second){
            if (!change){
                ok[i].second=false;
            }
            else{
                change=false;
            }
        }
        if (i>0 && tab[i]!=tab[i-1]){
            change=true;
        }
    }
    vi pref(n);
    for (int i=1;i<n;i++){
        pref[i]+=pref[i-1];
        if (tab[i-1]!=tab[i]){
            pref[i]++;
        }
        if (i<n-1 && ok[i].second){
            pref[i+1]--;
        }
        var(i);
        var(pref[i]);
    }
    vi suf(n);
    for (int i=n-2;i>=0;i--){
        suf[i]+=suf[i+1];
        if (tab[i]!=tab[i+1]){
            suf[i]++;
        }
        if (i>0 && ok[i].first) suf[i-1]--;
    }
    int mini=2*n+10;
    for (int i=0;i<k;i++){
        mini=min(mini, max(pref[spec[i]], suf[spec[i]]));
    }
    cout<<mini<<"\n";
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