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

void matpow(vvi& adj, int k){
    vvi cum = adj;
    vvi res(n,vi(n, 2ll*E9));
    while(k){
        if (k&1){
            vvi tmp=res;
            forn(i,n){
                forn(j,n){
                    res[i][j]=2ll*E9;
                    forn(k,n){
                        res[i][j]=min(res[i][j], tmp[i][k]+cum[k][j]);
                    }
                }
            }
        }
        cum=adj;
        forn(i,n){
            forn(j,n){
                adj[i][j]=2ll*E9;
                forn(k,n){
                    adj[i][j]=min(adj[i][j], cum[i][k]+cum[k][j]);
                }
            }
        }
        cum=adj;
        k>>=1ll;
    }
    adj=res;
}

void solve(){
    int m;
    cin>>m;
    int k;
    cin>>k;
    vvi mat(n, vi(n, 2ll*E9));
    forn(i,n) mat[i][i]=0;
    forn(i,m){
        int a,b;
        cin>>a>>b;
        a--;b--;
        int c;
        cin>>c;
        mat[a][b]=min(mat[a][b], c);
    }
    matpow(mat,k);
    if (mat[0][n-1]<2ll*E9) cout<<mat[0][n-1];
    else cout<<-1<<"\n";
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