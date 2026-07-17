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
 
 
 
const int MAXN = 2e6 + 10;
int n;

void solve(){
    vector<int> ost;
    map<int,int> mpright;
    set<int> mpleft;
    vector<pii> st;
    long long tot=0;
    forn(i,n){
        pii a;
        cin>>a.first>>a.second;
        if (!mpright[a.second]) ost.push_back(a.second);
        st.push_back(a);
        mpright[a.second]++;
    }
    sort(all(st));
    sort(all(ost));
    int i=0;
    while(i<n){
        int cur_x = (st[i]).first;
        while(i<n && (st[i]).first==cur_x){
            auto [a,b] = st[i];
            mpright[b]--;
            mpleft.insert(b);
            if (!mpright[b]){
                mpright.erase(b);
            }
            i++;
        }
        if (mpright.size()){
            int l=max((*mpright.begin()).first, (*mpleft.begin()));
            int r=min((*mpright.rbegin()).first, (*mpleft.rbegin()));
            if (r>l){
                tot+=lower_bound(all(ost), r)-lower_bound(all(ost), l);
            }
        }
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
    int ttt; cin>>ttt;
    while (cin>>n) solve();
}