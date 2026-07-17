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
vi fact;

int fast_pow(int a,int b){
    int tot=1;
    while(b){
        if (b&1ll){
            tot*=a;
            tot%=SIMPLE_MOD;
        }
        a*=a;
        a%=SIMPLE_MOD;
        b>>=1ll;
    }
    return tot;
}

int modinv(int a){
    return fast_pow(a,SIMPLE_MOD-2ll);
}

int choose(int a, int b){
    return fact[b]*modinv(fact[a])%SIMPLE_MOD*modinv(fact[b-a])%SIMPLE_MOD;
}

void solve(){
//Its just Dn
    // By inclusion-exclusion principle, its sum (-1)^k*(k choose n)
    fact.resize(n+1);
    fact[0]=1;
    forn(i,n){
        fact[i+1]=fact[i]*(i+1ll);
        fact[i+1]%=SIMPLE_MOD;
    }

    int tot=0;
    forn(i,n+1){
        if (i%2) tot-=(choose(i,n)*fact[n-i])%SIMPLE_MOD;
        else tot+=(choose(i,n)*fact[n-i])%SIMPLE_MOD;
        if (tot<0) tot+=SIMPLE_MOD;
        if (tot>=SIMPLE_MOD) tot-=SIMPLE_MOD;
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
    while (cin>>n) solve();
}