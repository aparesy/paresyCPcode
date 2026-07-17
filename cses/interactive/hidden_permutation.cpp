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
    vi res;
    res.push_back(1);
    for (int i=2;i<=n;i++){
        int l=0;
        int r=res.size()+1;
        while(r-l>1){
            int m=(r+l)/2;
            cout<<"? "<<i<<" "<<res[m-1]<<endl;
            string s;
            cin>>s;
            if (s[0]=='Y'){
                r=m;
            }
            else{
                l=m;
            }
        }
        res.insert(res.begin() + l, i);
    }
    vi res2(n);
    forn(i,n){
        res2[res[i]-1]=i+1;
    }
    cout<<"! ";
    for (auto x : res2) cout<<x<<" ";
    cout<<endl;
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    cin>>n; 
    solve();
}