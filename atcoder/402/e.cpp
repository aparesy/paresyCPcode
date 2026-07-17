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

double evaluate_perm(vi& perm, int x, vector<tuple<int,int,int>>& prob){
    int cost=0;
    int cur_i=0;
    double tot=0;
    while(cur_i<n && cost+T(prob[perm[cur_i]], 1) <= x){
        cost+=T(prob[perm[cur_i]], 1);
        tot+=((double)(T(prob[perm[cur_i]], 0))*(double)(T(prob[perm[cur_i]], 2)))/100.;
        cur_i++;
    }
    return tot;
}

void solve(){
    int x;
    cin>>x;
    vector<tuple<int,int,int>> prob(n);
    forn(i,n){
        int a,b,c;
        cin>>a>>b>>c;
        prob[i] = {a,b,c};
    }
    vi perm(n);
    double maxi=0;
    iota(all(perm), 0LL);
    do{
        maxi=max(maxi, evaluate_perm(perm,x,prob));
    }
    while(next_permutation(all(perm)));
    cout<<maxi;
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin>>n) solve();
}