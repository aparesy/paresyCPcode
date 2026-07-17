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
int a,n,d;
vi tab;

void just_below(int& mini){
    if (d<=1) return;
    int tot=0;
    forn(i,d-1){
        tot*=10ll;
        tot+=tab[n-1];
    }
    mini=min(mini,abs(a-tot));
}

void just_above(int& mini){
    int tot=0;
    forn(i,d+1){
        tot*=10ll;
        if (i==0 && min(tab[0],tab[n-1])==0) tot+=max(tab[0],tab[min(n-1,1ll)]);
        else tot+=tab[0];
    }
    mini=min(mini,abs(a-tot));
}

int nthdigit(int x, int b){
    while(b) x/=10ll;
    return (x%10ll);
}

int poww(int a, int b){
    int tot=1;
    while(b){
        if (b&1ll){
            tot*=a;
        }
        a*=a;
        b>>=1ll;
    }
    return tot;
}

void bt(int& mini, int digits, int x){
    if (digits==d){
        mini = min(mini, abs(a-x));
        return;
    }
    int xx = x + tab[0] * poww(10ll,d-digits-1ll);
    int xxx = x + tab[n-1] * poww(10ll,d-digits-1ll);
    if (xx>=xxx) swap(xx,xxx);
    if (xx>=a || xx==xxx){
        bt(mini,digits+1,xx);
    }
    else if (a-xxx>=poww(10ll,d-digits-1ll)){
        bt(mini,digits+1,xxx);
    }
    else{
        forn(j,n){
            bt(mini,digits+1,x+tab[j]*poww(10ll,d-digits-1ll)); 
        }
    }
}

void solve(){
    int aa=a;
    tab.clear();
    tab.resize(n);
    forn(i,n){
        cin>>tab[i];
    }
    d=0;
    while(aa){
        d++;
        aa/=10ll;
    }

    if (d==0){
        cout<<tab[0]<<"\n";
        return;
    }

    int mini=E18;
    just_below(mini);
    just_above(mini);
    bt(mini,0,0);
    cout<<mini<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ttt; cin>>ttt;
    while (cin>>a>>n) solve();
}