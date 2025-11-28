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
int queries;

int query(int a, int b){
    queries++;
 //   if(queries>300 && queries>n/2+2) return -1; 
    cout<<"? "<<a+1<<" "<<b+1<<endl<<flush;
    int x;
    cin>>x;
    return x;
}

void solve(){
    cin>>n;
    int q;
    cin>>q;

    vector<pii> seg(q);
    rep(i,0,q){
        cin>>seg[i].first>>seg[i].second;
        seg[i].first--;
        seg[i].second--;
    }

    int pos0=query(0,n/2);
    if (pos0) pos0=0; else pos0=1;
    sort(all(seg), [](const pii a,const pii b){if (a.first==b.first) return a.second>b.second; return a.first<b.first;});
    int maxi=0;
    int lbound=-1;
    int rbound=-1;
    rep(i,0,q){
        auto [a,b]=seg[i];
        if (a==lbound) continue;
        if (b<=rbound) continue;
        if ((pos0 && b<=n/2) || (!pos0 && a>n/2)) continue;
        int x=query(a,b);
        maxi=max(maxi, x);
        rbound=max(rbound, b);
        lbound=a;
    }
    cout<<"! "<<maxi<<endl<<flush;
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