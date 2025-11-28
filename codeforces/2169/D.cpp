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
int x,y,k;
void solve(){
    cin>>x>>y>>k;
    int l=0;
    int r=1e13;
    while(r-l>1){
        int m=(r+l)/2ll;
        int m2=m;
        // Est ce que m peut etre la solution
        bool ok=true;
        bool ok2=true;
        int mecsretires=0;
        for (int i=0; i<x && ok;){
            if (y>m2) break;
            if ((m2%y)==0) ok2=false;
            int etapesRestantes=x-i;
            int ecart=(m2%y)+1;
            int etapes=min(etapesRestantes, (int) sqrt(y/2-1));
            etapes=max(etapes,1ll);
            mecsretires=(m2-1ll)/y*etapes; 
            m2-=mecsretires;
            i+=etapes;
            if (m2<=0) ok=false;
        }
        if (!ok || m2<k) l=m;
        else if (m2>k) r=m;
        else if (!ok2){
            l=m;
        }
        else{
            if (m>1e12){
                cout<<-1<<"\n";
                return;
            }
            cout<<m<<"\n";
            return;
        }
    }
    if (r<=1e12){
        cout<<r<<"\n";
    }
    else cout<<-1<<"\n";
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