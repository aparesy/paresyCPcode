#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

// #ifdef DEBUG
// #define var(x) cerr << #x << ": " << x << '\n';
// #define range(a, b) cerr << #a << ", " << #b << ": "; for (auto _it = a; _it != b; ++_it) cerr << *_it << ' ' ; cerr << '\n';
// #else 
#define var(x) 
#define range(a, b)
#define cerr if (false) cerr
// #endif


#define vi vector<int>
#define pii pair<int, int>
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
#define T(x, i) get<i>(x)
#define rep(i,j,k) for (ll i = j; i < k; i++)
#define sz(tab) tab.size()
#define vl vector<ll>
const int MAXN = 1e6 + 10;


void simulate(vl& tab, ll i){
    int n=tab.size();
    if (i==-1){
        int j=0;
        ll points=1;
        while(j<n){
            if (tab[j]==0){
                points--;
                tab[j]++;
                if (points==0)return;
                j++;
            }
            else{
                points--;
                tab[j]++;
                if (points==0){
                    points=tab[j];
                    tab[j]=0;
                }
                j++;
            }
        }
    }
    else{
        rep(j,0,2*i+1){
            if (j%2==0){
                tab[j]=1;
            }
            else{
                tab[j]+=((1ll<<(i-j/2ll))-1ll);
            }
        }
    }
}


void solve() {
    int n;
    cin>>n;
    ll t;
    cin>>t;
    vector<ll> tab(n);
    rep(i,0,n){
        cin>>tab[i];
    }
    ll cleared=0;
    ll prevCleared=0;
    while (t>0){
        ll i=cleared;
        while (2*i<n && tab[2*i]==0 && (1ll<<(i+1ll))-1ll<=t){
            i++;
        }
        i--;
        simulate(tab, i);
        if (i==-1){
            t--;
            cleared=prevCleared;
        }
        else{
            t-=(1ll<<(i+1ll))-1ll;
            prevCleared=max(i,prevCleared);
            cleared=0;
        }
    }
    rep(i,0,n) cout<<tab[i]<<" ";
}

signed main() {
    // #ifdef DEBUG
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    auto start_time = std::chrono::high_resolution_clock::now();
    solve();
    auto end_time = std::chrono::high_resolution_clock::now();

    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
//    std::cout << "Elapsed: " << ms << " ms\n";
}