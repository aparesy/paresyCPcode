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
vi primes;

void crible(int K){
    int a=sqrt(K);
    vi tab(a);
    tab[0]=1;
    tab[1]=1;
    primes.push_back(2);
    for (int i=3;i<a;i+=2){
        if (!tab[i]){
            primes.push_back(i);
            for (int j=i*i;j<a;j+=2ll*i){
                tab[j]=1;
            }
        }
    }
}

map<int,int> dec(int x){
    map<int,int> res;
    for (auto p : primes){
        while(!(x%p)){
            x/=p;
            res[p]++;
        }
        if (x==1) return res;
        if (p*p>x){
            res[x]++;
            return res;
        }
    }
    if (x!=1) res[x]++;
    return res;
}

int powmod(int a, int b){
    int cur=1;
    while(b){
        if (b&1){
            cur*=a;
            cur%=FFT_MOD;
        }
        a*=a;
        a%=FFT_MOD;
        b>>=1;
    }
    return cur;
}

void solve(){
    vi tab(n);
    forn(i,n) cin>>tab[i];
    vector<map<int,int>> pref(n+1);
    vector<map<int,int>> suf(n+1);

    forn(i,n){
        auto mp = dec(tab[i]);
        map<int,int> res=pref[i];
        for (auto [a,b] : mp){
            res[a]=max(b, res[a]);
        }
        pref[i+1]=res;
    }

    forn(i,n){
        auto mp = dec(tab[n-1-i]);
        map<int,int> res=suf[i];
        for (auto [a,b] : mp){
            res[a]=max(b, res[a]);
        }
        suf[i+1]=res;
    }

    forn(i,n){
        auto mp = pref[i];
        for (auto [a,b] : suf[n-i-1]){
            mp[a]=max(mp[a], b);
        }
        int res=1;
        for (auto [a,b] : mp){
            res*=powmod(a,b);
            res%=FFT_MOD;
        }
        cout<<res<<" ";
    }
    cout<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a=sqrt(20000000);
    crible(2e7);
    int t;
    cin>>t;
    while (cin>>n) solve();
    //for(auto x: primes) cout<<x<<"\n";
   // cout<<clock();
}