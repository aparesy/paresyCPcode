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
 
 
 
const int MAXN = 2e6 + 10;
int r,g,b;

void solve(){
    vector<char> res;
    int k=0;
    while(r+g+b>0){
        vector<pii> poss;
        if (r>0 && (k<=0 || res[k-1]!='r') && (k<=2 || res[k-3]!='r')){
            poss.push_back({r, 'r'});
        }
        if (g>0 && (k<=0 || res[k-1]!='g') && (k<=2 || res[k-3]!='g')){
            poss.push_back({g, 'g'});
        }
        if (b>0 && (k<=0 || res[k-1]!='b') && (k<=2 || res[k-3]!='b')){
            poss.push_back({b, 'b'});
        }
        if (sz(poss)==0) break;
        if (sz(poss)==1){
            res.push_back(poss[0].second);
            k++;
            if (poss[0].second=='r'){
                r--;
            }
            else if (poss[0].second=='g'){
                g--;
            }
            else if (poss[0].second=='b'){
                b--;
            }
            continue;
        }
        sort(all(poss), greater<pii>());
        if (poss[0].first==poss[1].first){
            if (k>=2 && res[k-2]==poss[1].second){
                res.push_back(poss[1].second);
                if (poss[1].second=='r'){
                    r--;
                }
                else if (poss[1].second=='g'){
                    g--;
                }
                else if (poss[1].second=='b'){
                    b--;
                }
            }
            else{
                res.push_back(poss[0].second);
                if (poss[0].second=='r'){
                    r--;
                }
                else if (poss[0].second=='g'){
                    g--;
                }
                else if (poss[0].second=='b'){
                    b--;
                }
            }
            k++;
        }
        else{
            res.push_back(poss[0].second);
            k++;
            if (poss[0].second=='r'){
                r--;
            }
            else if (poss[0].second=='g'){
                g--;
            }
            else if (poss[0].second=='b'){
                b--;
            }
            continue;  
        }
    }
    for (auto x : res){
        cout<<(char)(x+'A'-'a');
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
    while (cin>>r>>g>>b) solve();
}