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

int fastpow(int a, int b){
    int res=1;
    while(b){
        if (b&1){
            res*=a;
        }
        a*=a;
        b>>=1;
    }
    return res;
}

vi list_divisors(int a){
    map<int,int> primes;
    for (int i=2;i*i<=a;i++){
        while (!(a%i)){
            a/=i;
            primes[i]++;
        }
    }
    if (a>1){
        primes[a]++;
    }
    vi res;
    res.push_back(1);
    for (auto [x,y] : primes){
        auto tmp=res;
        forn(i,y){
            for (auto xx : tmp){
                res.push_back(xx*fastpow(x,i+1));
            }
        }
    }
    return res;
}


void solve(){
    vi tab(n);
    forn(i,n) cin>>tab[i];
    // map<int,int> mp;
    // forn(i,n){
    //     for (auto x : list_divisors(tab[i])){
    //         mp[x]++;
    //     }
    // }
    // int x=1;
    // for (auto [a,b] : mp){
    //     if (b>=2){
    //         x=a;
    //     }
    // }
    // cout<<x<<"\n";
    int maxgcd=1;
    set<int> cur;
    forn(i,n){
        if (tab[i]>maxgcd){
            bool ok=true;
            vi toerase;
            for(auto x : cur){
                if (x <= maxgcd){
                    toerase.push_back(x);
                }
                else{
                    if(gcd(x,tab[i])>maxgcd){
                        maxgcd = gcd(x,tab[i]);
                    }
                    if (!(x%tab[i])){
                        ok=false;
                        break;
                    }
                    if (!(tab[i]%x)){
                        toerase.push_back(x);
                    }
                }
            }
            for (auto x:toerase) cur.erase(x); 
            if(ok)cur.insert(tab[i]);
        }
    }
    cout<<maxgcd<<"\n";
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