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
int n;

pii tab[MAXN];

void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>tab[i].first;
        tab[i].second=i;
    }
    sort(tab, tab+n, [](const pii a, const pii b){if (a.first==b.first) return a.second>b.second; return a.first<b.first;});
    vi prefmax(n);
    prefmax[0]=1;
    vi hyperprefmax(n);
    hyperprefmax[0]=1;
    int curMax=1;
    rep(j,1,n){
        var(curMax);
        prefmax[j]=1;
        if (tab[j].first>tab[j-1].first) curMax=0;
        int l=-1;
        int r=j;
        while(r-l>1){
            int m=(r+l)/2;
            if ((tab[m].first<=tab[j].first-2 || tab[m].second>tab[j].second) && tab[m].first!=tab[j].first){
                l=m;
            }
            else r=m;
        } // minimal r that is "not okay"

        int l2=-1;
        int r2=j;
        while(r2-l2>1){
            int m=(r2+l2)/2;
            if (tab[m]==tab[j]) r2=m;
            else l2=m;
        }// minimal l2 that is equal to tab[j]
        var (r);
        if (r!=0) prefmax[j]=max(prefmax[j], hyperprefmax[r-1]+1);
        prefmax[j]=max(curMax+1, prefmax[j]);
        curMax=max(curMax, prefmax[j]);
        hyperprefmax[j]=max(hyperprefmax[j-1], prefmax[j]);
    }
    cout<<n-(*max_element(all(prefmax)))<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int _t;
    cin >> _t;
    rep(i,0,_t) {
        solve();
    }
}