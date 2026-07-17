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
    int m,q;
    cin>>m>>q;
    map<int,int> ver;
    map<int,int> hor;
    set<int> stver;
    set<int> sthor;
    stver.insert(0); stver.insert(m);
    sthor.insert(0); sthor.insert(n);
    ver[m]=1;
    hor[n]=1;
    int prev=0;
    forn(i,q){
        int op,k;
        cin>>op>>k;
        if (op==1){
            if (sthor.count(k)){
                cout<<prev<<"\n";
                continue;
            }
            sthor.insert(k);
            auto it = sthor.upper_bound(k);
            int justAbove = *it;
            it--;it--;
            int justBelow = *it;
            int dist = justAbove-justBelow;
            hor[dist]--;
            if (hor[dist]==0) hor.erase(dist);
            hor[justAbove-k]++;
            hor[k-justBelow]++;
            prev = (*hor.rbegin()).first * (*ver.rbegin()).first;
            cout<<prev<<"\n";
        }
        if (op==2){
            if (stver.count(k)){
                cout<<prev<<"\n";
                continue;
            }
            stver.insert(k);
            auto it = stver.upper_bound(k);
            int justAbove = *it;
            it--;it--;
            int justBelow = *it;
            int dist = justAbove-justBelow;
            ver[dist]--;
            if (ver[dist]==0) ver.erase(dist);
            ver[justAbove-k]++;
            ver[k-justBelow]++;
            prev = (*ver.rbegin()).first * (*hor.rbegin()).first;
            cout<<prev<<"\n";
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
    //int ttt; cin>>ttt;
    while (cin>>n) solve();
}