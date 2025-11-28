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
string s;
bool grid[MAXN];

int make_v(pii a){
    auto [i,j] = a;
    return 7*i+j;
}

vector<pii> dir;

int backtrack(int i, int j, int nb){
    if (i<0 || j<0 || i>6 || j>6) return 0;
    if (s[nb]!='?'){
        if (s[nb]=='U') return backtrack(i-1,j,nb+1);
        if (s[nb]=='D') return backtrack(i+1,j,nb+1);
        if (s[nb]=='L') return backtrack(i,j-1,nb+1);
        if (s[nb]=='R') return backtrack(i,j+1,nb+1);
    }
    bitset<4> ok=0;
    if (i!=0) ok[0]=true;
    if (i!=6) ok[1]=true;
    if (j!=0) ok[2]=true;
    if (j!=6) ok[3]=true;
    forn(i,4){
        pii som={dir[i].first+i, dir[i].second+j};
        if (ok[i] && grid[make_v(som)]) ok[i]=false;
    }
    if (ok[0]==1 && ok[1]==0 && ok[2]==1 && ok[3]==0) return 0;
    if (ok[0]==0 && ok[1]==1 && ok[2]==0 && ok[3]==1) return 0;
    int tot=0;
    forn(i,4){
        if (!ok[i]) continue;
        auto x=dir[i];
        pii som={x.first+i,x.second+j};
        if (nb==48){
            if (make_v(som)==42) return 1;
        }
        else{
            grid[make_v(som)]=true;
            tot+=backtrack(som.first,som.second,nb+1);
            grid[make_v(som)]=false;
        } 
    }
    var(tot);
    return tot;
}

void solve(){
    cin>>s;
    cout<<s.length()<<"\n";
    dir.push_back({-1,0});
    dir.push_back({1,0});
    dir.push_back({0,-1});
    dir.push_back({0,1});
    cout<<backtrack(0,0,0);
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin.tie(0);
    solve();
}