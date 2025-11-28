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
int n,q;

int tab[MAXN];

void solve(){
    cin>>n>>q;
    rep(i,0,n){
        cin>>tab[i];
    }
    set<int> free;
    set<int> isOneHere[30];
    rep(i,0,n){
        forn(j,30){
            if (tab[i]&(1ll<<j)){
                isOneHere[j].insert(i);
            }
        }
    }
    multiset<int> strongests;
    rep(i,0,n){
        strongests.insert(tab[i]);
    }
    rep(i,0,q){
        bool ok=true;
        free.clear();
        int c;
        cin>>c;
        int minCost=0;
        multiset<int> toReinsert;
        for (int j=29; j>=0 && ok; j--){
            if (c&(1ll<<j)){
                if (!free.size()){
                    if (isOneHere[j].size()){
                        auto it=isOneHere[j].begin();
                        it++;
                        while(it!=isOneHere[j].end()){
                            free.insert((*it));
                            if (free.size()>=29){
                                cout<<minCost<<"\n";
                                ok=false;
                                break; 
                            }
                            it++;
                        }
                    }
                    else{
                        if (strongests.size()){
                            auto x = (*strongests.rbegin());
                            strongests.erase((*strongests.find(x)));
                            toReinsert.insert(x);
                            minCost+=(1ll<<j)-x;
                        }
                        else{
                            minCost+=(1ll<<j);
                        }
                    }
                }
            }
            else{
                for (auto x:  isOneHere[j]){
                    free.insert(x);
                    if (free.size()>=29){
                        cout<<minCost<<"\n";
                        ok=false;
                        break;
                    }
                }
            }
        }
        for (auto x : toReinsert){
            strongests.insert(x);
        }
        if (ok){
            cout<<minCost<<"\n";
        }
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