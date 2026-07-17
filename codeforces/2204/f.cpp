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

int inv(int a) {
  return a <= 1 ? a : FFT_MOD - (long long)(FFT_MOD/a) * inv(FFT_MOD % a) % FFT_MOD;
}


int compute_frac(int x, int y){
    int w=inv(y);
    return (x*w)%FFT_MOD;
}

void solve(){
    int qq;
    cin >> qq;

    vi tab(n);
    forn(i,n) cin >> tab[i];

    int tot = 0;
    forn(i,n){
        tot += compute_frac(1, tab[i]);
        if (tot >= FFT_MOD) tot -= FFT_MOD;
    }

    priority_queue<pii, vector<pii>, greater<pii>> q;
    forn(i,n) q.push({tab[i], i});

    vector<pii> frac(n);
    forn(i,n) frac[i] = {1, tab[i]};

    int k = 0;

    forn(i,qq){
        int k2;
        cin >> k2;

        int delta = k2 - k;

        while(delta > 0){
            auto [a,b] = q.top();
            q.pop();

            int cur = min(delta, a - 1);

            // remove old contribution
            tot = (tot - compute_frac(frac[b].first, frac[b].second) + FFT_MOD) % FFT_MOD;

            frac[b].second -= cur;

            if(frac[b].second == 0) frac[b].second = 1;

            // add new contribution
            tot = (tot + compute_frac(frac[b].first, frac[b].second)) % FFT_MOD;

            q.push({a - cur, b});
            delta -= cur;
        }

        cout << tot << "\n";
        k = k2;
    }
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin>>n) solve();
}