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
int n,a,b,x,y;

void solve(){
    x = abs(x);
    y = abs(y);
    int target=min(x,y);
    int tot = target*2ll*min(a,b);
    int reste = max(x,y) - target;
    int dir = (max(x,y)==x)?0:1;
    var(tot);
    if (dir==0){
        if (min(a,b)*3ll>=max(a,b)){
            cout<<tot+a*((reste+1ll)/2ll)+b*(reste/2ll)<<"\n";
        }
        else{
            if (min(a,b)==a){
                cout<<tot+(reste/2ll)*3ll*a+((reste+1ll)/2ll)*a<<"\n";
            }
            else{
                cout<<tot+(reste/2ll)*b+((reste+1ll)/2ll)*3ll*b<<"\n";
            }
        }
    }
    else{
        if (min(a,b)*3ll>=max(a,b)){
            cout<<tot+b*((reste+1ll)/2ll)+a*(reste/2ll)<<"\n";
        }
        else{
            if (min(a,b)==b){
                cout<<tot+(reste/2ll)*3ll*b+((reste+1ll)/2ll)*b<<"\n";
            }
            else{
                cout<<tot+(reste/2ll)*a+((reste+1ll)/2ll)*3ll*a<<"\n";
            }
        }
    }
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ttt; cin>>ttt;
    while (cin>>a>>b>>x>>y) solve();
}