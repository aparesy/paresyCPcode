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

int tab1[MAXN];
int tab2[MAXN];
pii prefMin[MAXN];
pii prefMax[MAXN];


int cheminHaut(int l, int r){
    // find the largest index that is ok
    int a=0;
    int b=n;
    while(b-a>1){
        int m=(b+a)/2;
        if (prefMin[m].first>=l){
            a=m;
        }
        else b=m;
    } // a is the index
    int c=0;
    int d=n;
    while(d-c>1){
        int m=(c+d)/2; var(m); var(prefMax[m].first)
        if (prefMax[m].first<=r){
            c=m;
        }
        else d=m;
    } // a is the index
    return min(a,c)+1;
}

int cheminBas(int l, int r){
    // find the largest index that is ok
    int a=0;
    int b=n;
    while(b-a>1){
        int m=(b+a)/2;
        if (prefMin[m].second>=l){
            a=m;
        }
        else b=m;
    } // a is the index
    int c=0;
    int d=n;
    while(d-c>1){
        int m=(c+d)/2;
        if (prefMax[m].second<=r){
            c=m;
        }
        else d=m;
    } // a is the index
    return min(a,c)+1;
}

void solve(){
    cin>>n;
    rep(i,0,n) cin>>tab1[i];
    rep(i,0,n){
        cin>>tab2[i];
    }
    reverse(tab2, tab2+n);
    prefMin[0]={tab1[0], tab2[0]};
    prefMax[0]={tab1[0], tab2[0]};
    rep(i,1,n){
        prefMin[i].first=min(tab1[i], prefMin[i-1].first);
        prefMin[i].second=min(tab2[i], prefMin[i-1].second);
        prefMax[i].first=max(tab1[i], prefMax[i-1].first);
        prefMax[i].second=max(tab2[i], prefMax[i-1].second);
    }
    int l=1ll;
    int r=1ll;
    int tot=0;
    var(cheminHaut(l,r));
    while (r<=2*n && cheminHaut(l,r)+cheminBas(l,r)<=n) r++;
    tot+=(2*n-r+1);
    while(l<2*n){
        var(tot)
        l++;
        while (r<=2*n && cheminHaut(l,r)+cheminBas(l,r)<=n) r++;
        tot+=(2*n-r+1);
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