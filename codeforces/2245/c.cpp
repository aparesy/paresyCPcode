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
    int k;
    cin>>k;
    int lg = log2(k);
    int lgn = log2(n);

    if (n==1){
        if (k==1){
            cout<<"YES\n";
            cout<<"0\n";
            return;
        }
        else{
            cout<<"NO\n";
            return;
        }
    }

    else if ((lg>lgn) || (n==(1<<lgn) && (k<(1<<lgn)))){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    vi ok(n,0);
    stack<int> st;
    for(int i=lgn;i>=0;i--){
        if ((n & (1<<i)) ^ (k & (1<<i))){
            st.push((1<<i));
            ok[1<<i]=true;
        }
    }
    st.push(0);
    ok[0]=true;
    forn(i,n) if (!ok[i]){
        cout<<i<<" ";
    }
    while(!st.empty()){
        auto x = st.top();
        st.pop();
        cout<<x<<" ";
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
    int ttt; cin>>ttt;
    while (cin>>n) solve();
}