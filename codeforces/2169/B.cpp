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
char et='*';
char left='<';
char right='>';

void solve(){
    string s;
    cin>>s;
    char a=s[0];
    int state=0;
    n=s.length();
    pii middle;
    if (s[0]=='>'){
        middle.second=-1;
        middle.first=2;
    }
    if (n==1){
        cout<<1<<"\n";
        return;
    }
    rep(i,0,n){
        if (state==0){
            if (s[i]=='*'){
                middle.first=1;
                middle.second=i;
                state=1;
            }
            else if (s[i]=='>'){
                middle.second=i;
                state=2;
            }
        }
        else if (state==1){
            if (s[i]!='>'){
                cout<<-1<<"\n";
                return;
            }
            else state=2;
        }
        else{
            if (s[i]!='>'){
                cout<<-1<<"\n";
                return;
            }
        }
    }
    if (middle.first==2){
        cout<<n<<"\n";
    }
    else if (middle.first==0){
        cout<<max(middle.second, n-middle.second)<<"\n";
    }
    else{
        cout<<max(middle.second+1, n-middle.second)<<"\n";
    }
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin.tie(0);
    int _t;
    cin >> _t;
    rep(i,0,_t) {
        solve();
    }
}