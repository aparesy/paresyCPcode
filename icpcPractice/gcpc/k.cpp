#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#ifdef DEBUG
#define var(x) cerr << #x << ": " << x << '\n';
#define range(a, b) cerr << #a << ", " << #b << ": " << for (auto _it = a; _it != b; ++_it) cerr << *_it << ' ' ; cerr << '\n';
#else 
#define var(x) 
#define range(a, b)
#define cerr if (false) cerr
#endif


#define vi vector<int>
#define pii pair<int, int>
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
#define T(x, i) get<i>(x)
#define rep(i,j,k) for (int i = j; i < k; i++)

const int MAXN = 1e6 + 10;
int n;


void solve() {
    int a,b;
    cin>>a>>b;
    if (a+b<3){
        cout<<"no\n";
        return;
    }
    if (a+b>n+1){
        cout<<"no\n";
        return;
    }
    int i=1;
    cout<<"yes\n";
    if (a==1){
        cout<<n<<" ";
        i=n-1;
        rep(j,0,b-2){
            cout<<i<<" ";
            i--;
        }
        rep(j,1,n-b+1) cout<<j<<" ";
        cout<<i<<"\n";
        return;
    }
    if (b==1){
        rep(j,n-a+1,n) cout<<j<<" ";
        rep(j, 1, n-a+1) cout<<j<<" ";
        cout<<n<<"\n";
        return;
    }
    rep(j,0,a-1){
        cout<<i<<" ";
        i++;
    }
    cout<<n<<" ";
    i=n-1;
    rep(j,0,b-2){
        cout<<i<<" ";
        i--;
    }
    rep(j,a,n-b+1) cout<<j<<" ";
    cout<<i<<"\n";
    return;
}

signed main() {
    // #ifdef DEBUG
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n) {
        solve();
    }
}