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
int h,w;

void solve(){
    vvi tab(h, vi(w));
    forn(i,h){
        string s;
        cin>>s;
        forn(j,w){
            if(s[j]=='.'){
                tab[i][j] = 1;
            }
            else{
                tab[i][j]=0;
            }
        }
    }
    int tot=0;
    forn(i1,h){
        forn(j1,w){
            for (int i2=i1;i2<h;i2++){
                for (int j2=j1;j2<w;j2++){
                    bool ok=true;
                    for (int i=i1;i<=i2;i++){
                        for (int j=j1;j<=j2;j++){
                      //      cout<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<" "<<i<<" "<<j<<"\n";
                            if (tab[i][j] != tab[i1+i2-i][j1+j2-j]){
                                ok=false;
                            }
                        }
                    }
                    if (ok){
                        tot++;
                    }
                }
            }
        }
    }
    cout<<tot<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //int ttt; cin>>ttt;
    while (cin>>h>>w) solve();
}