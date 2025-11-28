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
#define rep(i,a,b) for (int i=a;i<b;i++)


const int MAXN = 1e6 + 10;
int n;


void solve() {
    string s="aaaaaaaB#1";
    rep(i,0,n){
        int j=0;
        while (s[j]=='z'){
            s[j]='a';
            s[j+1]='a';
            j+=2;
        }
        s[j]++;
        s[j+1]++;
        cout<<s<<"\n";
    }
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