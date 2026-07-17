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
 
 
 
const int MAXN = 2e6 + 10;
int n;

int boss[MAXN][20];
int h[MAXN];

void dfs(int s, vector<vi>& revadj){
    for (auto t : revadj[s]){   
        h[t]=h[s]+1;
        dfs(t,revadj);
    }
}

int lift(int x, int height){
    if (height>=h[x]) return x;
    int target=h[x]-height;
    int nb=0;
    while(target){
        if (x<=0) return 0;
        if (target & 1){
            x = boss[x][nb];
        }
        nb++;
        target>>=1;
    }
    return x;
}

void solve(){
    int q;
    cin>>q;
    forn(i,n-1){
        cin>>boss[i+1][0];
        boss[i+1][0]--;
    }
    boss[0][0]=-1;
    for (int k=1;k<20;k++){
        forn(i,n){
            boss[i][k] = ((boss[i][k-1]==-1)?-1:boss[boss[i][k-1]][k-1]);
        }
    }
    vector<vector<int>> revadj(n);
    forn(i,n-1){
        revadj[boss[i+1][0]].push_back(i+1);
    }
    h[0]=0;
    dfs(0,revadj);

    forn(i,q){
        int a,b;
        cin>>a>>b;
        a--; b--;
        if (h[a]>h[b]){
            a=lift(a,h[b]);
        }
        else{
            b=lift(b,h[a]);
        }
        int l=0;
        int r=h[a]+1;
        while(r-l>1){
            int m=(r+l)/2;
            if (lift(a, m)==lift(b,m)){
                l=m;
            }
            else r=m;
        }
        cout<<lift(a,l)+1<<"\n";
    }
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