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
int n,q2;
string s;

int evaluate(string& s2){
    int tot=0;
    forn(i,n-1){
        if (s2[i]=='X'){
            tot+=10ll;
        }
        else if (s2[i]=='V'){
            tot+=5ll;
        }
        else if (s2[i]=='I'){
            if (s2[i+1]!='I') tot--;
            else tot++;
        }
    }

    int i=n-1;
    if (s2[i]=='X'){
        tot+=10ll;
    }
    else if (s2[i]=='V'){
        tot+=5ll;
    }
    else if (s2[i]=='I'){
        tot++;
    }

    return tot;
}

void solve(){
    cin>>n>>q2;
    cin>>s;
    int nbQ=0;
    forn(i,n) if (s[i]=='?') nbQ++;
    forn(i,q2){
        int cx,cv,ci;
        cin>>cx>>cv>>ci;
        if (cx+cv+ci>nbQ) cx-=min(cx, max(0ll,cx+cv+ci-nbQ));
        if (cx+cv+ci>nbQ) cv-=min(cv, max(0ll,cx+cv+ci-nbQ)); // reduced to the necessary
        if (cx+cv+ci>nbQ) ci-=min(ci, max(0ll,cx+cv+ci-nbQ));
        int placed_x=0;
        int placed_v=0;
        int placed_i=0;
        var(cx) var(cv) var(ci);
        queue<pii> q; // 1 : important to place a 1 
        string t=s;

        forn(j,n-2){
            if (t[j]=='?' && t[j+1]!='?'){
                int a=1;
                if (t[j+1]=='I') a=0;
                q.push({j,a});
            }
        }
        if (t[n-1]=='?') q.push({n-1,0});

        while(!q.empty()){
            auto [pos, a]=q.front();
            q.pop();
            if (a==1){
                if (placed_i<ci){
                    placed_i++;
                    t[pos]='I';
                }
                else if (placed_v<cv){
                    placed_v++;
                    t[pos]='V';
                }
                else {
                    placed_x++;
                    t[pos]='X';
                }
            }
            else{
                if (placed_x<cx){
                    placed_x++;
                    t[pos]='X';
                }
                else if (placed_v<cv){
                    placed_v++;
                    t[pos]='V';
                }
                else {
                    placed_i++;
                    t[pos]='I';
                }
            }
            if (pos){
                if (t[pos-1]=='?'){
                    int a2=1;
                    if (t[pos]=='I') a2=0;
                    q.push({pos-1,a2});
                }
            }
        }
        int x=evaluate(t); 
        cout<<x<<"\n";
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