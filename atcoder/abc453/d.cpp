#include <bits/stdc++.h>
using namespace std;
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast")//Comment optimisations for interactive problems (use endl)
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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
int h,w;

vvi adj;
map<pair<int,short>,bool> vu;

int make_v(int i, int j, int prevdir){
    return i*w+j+prevdir*h*w;
}

int c(int s, int b){
    if (b==0){
        return s-w;
    }
    if (b==1) return s-1;
    if (b==2) return s+w;
    return s+1;
}

void solve(){
    string ss;
    adj.clear();
    adj.resize(4*h*w);
    int start,end;
    forn(i,h){
        cin>>ss;
        forn(j,w){
            if (ss[j]=='S') start = make_v(i,j,0);
            forn(prevdir,4){
                forn(b,4){
                    if (!i && b==0){
                        continue;
                    }
                    if (!j && b==1){
                        continue;
                    }
                    if (i<h-1 && b==2){
                        continue;
                    }
                    if (j<w-1 && b==3){
                        continue;
                    }
                    if (ss[j]=='o' && prevdir==b){
                        adj[make_v(i,j,prevdir)].push_back(c(make_v(i,j,prevdir),b));
                    }
                    if (ss[j]=='x' && prevdir!=b){
                        adj[make_v(i,j,prevdir)].push_back(c(make_v(i,j,prevdir),b));
                    }
                    if (ss[j]=='.' || ss[j]=='S'){
                        adj[make_v(i,j,prevdir)].push_back(c(make_v(i,j,prevdir),b));
                    }
                }
            }
        }
    }
    vu.clear();
    char prev[h*w*4];
    prev[start]=-1;
    stack<int> st;
    while(!st.empty()){
        auto s = st.top();
        st.pop();
        if (s=end){
            int cur=s;
            vector<char> res;
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
    //int ttt; cin>>ttt;
    while (cin>>h>>w) solve();
}