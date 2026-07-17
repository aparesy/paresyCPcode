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

int boss[MAXN][20];

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

    forn(i,q){
        int x,k;
        cin>>x>>k;
        x--;
        int j=0;
        while(k&&x!=-1){
            if (k & 1){
                x=boss[x][j];
            }
            j++;
            k>>=1;
        }
        if (x==-1) cout<<-1<<"\n"; else
        cout<<x+1<<"\n";
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