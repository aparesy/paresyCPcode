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
int n,k,p,m;

void solve(){
    vi a(n);
    forn(i,n){
        cin>>a[i];
    }
    priority_queue<int, vector<int>, greater<int>> hand;
    queue<int> deck;
    int fake_cost = a[p-1];
    forn(i,k){
        if (i!=p-1) hand.push(a[i]); else hand.push(-1);
    }
    for (int i=k;i<n;i++){
        if (i!=p-1) deck.push(a[i]); else deck.push(-1);
    }
    int tot=0;
    while(1){
        int x=hand.top();
        hand.pop();
        if (x==-1){
            if (fake_cost>m){
                cout<<tot<<"\n";
                return;
            }
            else{
                tot++;
                m-=fake_cost;
                deck.push(-1);
            }
        }
        else{
            if (x>m){
                cout<<tot<<"\n";
                return;
            }
            else{
                m-=x;
                deck.push(x);
            }
        }
        if (!deck.empty()){
            x=deck.front();
            deck.pop();
            hand.push(x);
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
    int t;
    cin>>t;
    while (cin>>n>>k>>p>>m) solve();
}