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

void solve(){
    int m;
    cin>>m;
    vi tab(n);
    forn(i,n) cin>>tab[i];
    vi c(m), x(m);
    forn(i,m) cin>>c[i]>>x[i];
    int state=0;

    auto applyEndState0 = [&](int nbSwitches, int lastPos){
        if (nbSwitches){
            int lastMex=x[lastPos-1];
            forn(i,n){
                if (tab[i]){
                    if (nbSwitches%2){
                        tab[i]=0;
                    }
                    else{
                        if (lastMex==1){
                            tab[i]=2;
                        }
                        else{
                            tab[i]=1;
                        }
                    }
                }
                else{
                    if (nbSwitches%2){
                        if (lastMex==1){
                            tab[i]=2;
                        }
                        else{
                            tab[i]=1;
                        }
                    }
                }
            }
        }
    };

    int cumulGcd=-1;
    int flag=-1;

    forn(i,m){  
        if (c[i]==0){
            if (state){
                cout<<"YES\n";
                return;
            }
            state=1;
            applyEndState0(i, i);
            flag=i;
        }
        else if (c[i]==1){
            if (state!=0){
                cout<<"YES\n";
                return;
            }
        }
        else{
            if (state==0){
                applyEndState0(i,i);
            }
            state=2;
            if (cumulGcd==-1){
                cumulGcd=x[i];
            }
            else{
                cumulGcd = gcd(cumulGcd, x[i]);
            }
        }
    }

    auto isId = [](vi& tab){
        int x = tab[0];
        forn(i,n){
            if (tab[i]!=x){
                return false;
            }
        }
        return true;
    };

    auto applyGcd = [](vi& a, int x){
        forn(i,n) a[i] = gcd(a[i], x);
    };

    if (state==0){
        applyEndState0(m,m);
        if (isId(tab)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    else if (state==1){
        if (isId(tab)){
            cout<<"YES\n";
        }
        else{
            bool ok=true;
            forn(i,n) ok = (tab[i] && ok);
            if(ok){
                cout<<"YES\n";
                return;
            }
            applyGcd(tab, x[m-1]);
            cout<<(isId(tab)?"YES\n":"NO\n");
        }
    }
    else{
        if (flag==-1){
            applyGcd(tab, cumulGcd);
            cout<<(isId(tab)?"YES\n":"NO\n");
        }   
        else{
            vi tmp = tab;
            applyGcd(tmp, gcd(x[flag], cumulGcd));
            if (isId(tmp)) cout<<"YES\n";
            else{
                applyEndState0(1,flag+1);
                applyGcd(tab, cumulGcd);
                cout<<(isId(tab)?"YES\n":"NO\n");
            }
        }
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
    while (cin>>n) solve();
}