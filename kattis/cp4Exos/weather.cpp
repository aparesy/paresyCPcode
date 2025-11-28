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

void solve(){
    vi fact(21);
    fact[0]=1;
    forn(i,20) fact[i+1]=fact[i]*(i+1);

    cin>>n;
    vector<double> probs;
    forn(i,4){
        double x;
        cin>>x;
        probs.push_back(x);
    }
    map<double, int> cnt;
    forn(i,n){
        forn(j,n-i+1){
            forn(k,n-j+1){
                if (i+j+k<=n){
                    int l=n-i-j-k;
                    double tmp=1;
                    vi coefs={i,j,k,l};
                    int tot=fact[n];
                    forn(m, 4){
                        tmp*=pow(probs[m], coefs[m]);
                        tot/=fact[coefs[m]];
                    }
                    cnt[tmp]+=tot;
                }
            }
        }
    }

    double totHeight=0;
    deque<pair<double,int>> q;
    for (auto x : cnt) q.push_back(x);
    while(q.size()){
        auto [d1, n1]=q.front();
        if (n1==0){
            q.pop_front();
            continue;
        }
        else if (n1==1){

        }
        else if (n1%2){
            
        }
        else{
            totHeight+=n1
        }
    }
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