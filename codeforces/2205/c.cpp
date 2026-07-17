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

void solve(){
    vector<vi> blogs(n);
    forn(i,n){
        int l;
        cin>>l;
        blogs[i].resize(l);
        forn(j,l){
            cin>>blogs[i][j];
        }
        reverse(all(blogs[i]));
    }

    map<int,int> vu;
    set<int> cd;
    forn(i,n) cd.insert(i);
    auto cmp  = [](vector<int>& b1, vector<int>& b2){
        forn(j,min(sz(b1), sz(b2))){
            if (b1[j]<b2[j]){
                return true;
            }
            if (b2[j]<b1[j]){
                return false;
            }
        }
        if (b1.size() < b2.size()) return true;
        return false;
    };
    forn(i,n){
        int bestCandidate=*cd.begin();
        for (auto idx : cd){
            vector<int> q1;
            vector<int> q2;
            set<int> st;
            for (auto y : blogs[idx]){
                if (!vu[y] && !st.count(y)){
                    q1.push_back(y);
                    st.insert(y);
                }
            }
            st.clear();
            for (auto y : blogs[bestCandidate]){
                if (!vu[y] && !st.count(y)){
                    q2.push_back(y);
                    st.insert(y);
                }
            }
            blogs[idx]=q1;
            blogs[bestCandidate]=q2;
            if (cmp(q1, q2)) bestCandidate=idx;
        }

        cd.erase(bestCandidate);
        for (auto k  : blogs[bestCandidate]){
            if (!vu[k]){
                vu[k]=true;
                cout<<k<<" ";
            }
        }
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
    int t;
    cin>>t;
    while (cin>>n) solve();
}