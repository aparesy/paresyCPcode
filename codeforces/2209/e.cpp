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

int mod_kmp(string& s){
    int m=s.length();
    int tot=1;
    vi br(m);
    vi dp(m,1);
    vi pbr(m);
    for(int i=1;i<m;i++){
        // br[i] : longueur du + grand bord de s[0..i]
        int j=br[i-1];
        while(j && s[i]!=s[j]){
            j=br[j-1];
        }
        if (s[i]==s[j]){
            j++;
        }
        br[i]=j;
        // pbr[i] : longueur du plus petit bord de s[0..i] ou 0
        if (br[i]){
            if (pbr[br[i]-1]){
                pbr[i]=pbr[br[i]-1];
            }
            else{
                pbr[i]=br[i];
            }
            dp[i]=1+dp[i-pbr[i]];
        }
        tot+=dp[i];
        var(br[i]);
        var(pbr[i]);
        var(dp[i]);
    }
    return tot;
}
 
const int MAXN = 2e6 + 10;
int n,q;
string s;

void solve(){
    cin>>s;
    forn(i,q){
        int l,r;
        cin>>l>>r;
        string t=string(s.substr(l-1,r-l+1));
        cout<<mod_kmp(t)<<"\n";
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
    while (cin>>n>>q) solve();
}