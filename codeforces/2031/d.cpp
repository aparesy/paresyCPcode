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
 
const int MAXN = 2e6 + 10;
int n;

void solve(){
    vi tab(n);
    forn(i,n){
        cin>>tab[i];
    }
    vi prefmax(n);
    prefmax[0]=tab[0];
    forn(i,n-1){
        prefmax[i+1]=max(prefmax[i], tab[i+1]);
    }
    vi sufmin(n);
    sufmin[n-1]=tab[n-1];
    for (int i=n-2;i>=0;i--){
        sufmin[i]=min(sufmin[i+1], tab[i]);
    }
    vi res(n);
    stack<int> st;
    forn(i,n-1){
        st.push(i);
        if (prefmax[i]<=sufmin[i+1]){
            var(i);
            while(!st.empty()){
                auto s = st.top();
                st.pop();
                res[s]=prefmax[i];
            }
        }
    }
    st.push(n-1);
    while(!st.empty()){
        auto s = st.top();
        st.pop();
        res[s]=prefmax[n-1];
    }
    for (auto x : res){
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