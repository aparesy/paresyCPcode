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
int n,k,x,a,b,c;

struct fake_queue{
    deque<pii> q;
    int time=0;
    int removed=0;
    void insert(int x){
        while(!q.empty() && q.front().first>x){
            q.pop_front();
        }
        q.push_front({x,time});
        time++;
    }
    int remove(){
        if (q.back().second==removed){
            q.pop_back();
        }
        removed++;
        return q.back().second;
    }
    int get_min(){
        return q.back().first;
    }
};

void solve(){
    fake_queue q;
    q.insert(x);
    forn(i,k-1){
        x=(a*x+b)%c;
        q.insert(x);
    }
    int res=q.get_min();
    forn(i,n-k){
        x=(a*x+b)%c;
        q.remove();
        q.insert(x);
        res^=(q.get_min());
    }
    cout<<res;
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin>>n>>k>>x>>a>>b>>c) solve();
}