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
#define pii pair<double, double>
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
int n,m;
pii shad[MAXN];
pii lyd[MAXN];

pii pos(int i, double t, int j){
    pii pos;
    if (j==0){
        pos.first=shad[i].first+t/hypot(shad[i+1].first-shad[i].first, shad[i+1].second-shad[i].second)*(shad[i+1].first-shad[i].first);
        pos.second=shad[i].second+t/hypot(shad[i+1].first-shad[i].first, shad[i+1].second-shad[i].second)*(shad[i+1].second-shad[i].second);
    }
    else{
        pos.first=lyd[i].first+t/hypot(lyd[i+1].first-lyd[i].first, lyd[i+1].second-lyd[i].second)*(lyd[i+1].first-lyd[i].first);
        pos.second=lyd[i].second+t/hypot(lyd[i+1].first-lyd[i].first, lyd[i+1].second-lyd[i].second)*(lyd[i+1].second-lyd[i].second);
    }
    return pos;
}

double dist(pii a, pii b){
    return hypot(a.first-b.first, a.second-b.second);
}

double solve2(int& i, double& t1, int& j, double& t2){
    // s1 + t(s2-s1)
    // l1 + t(l2-l1)    
    pii cur1=pos(i, t1, 0);
    pii cur2=pos(j, t2, 1);
    double mini=dist(cur1, cur2);
    if (dist(lyd[j+1], lyd[j])-t2>dist(shad[i+1], shad[i])-t1){
        double t3=t2+dist(shad[i+1], shad[i])-t1;
        pii cur3=pos(j, t3, 1); //var(cur3.first) var(cur3.second);
        mini=min(mini, dist(cur3, shad[i+1]));
        t2=t3;
        t1=0;
        i++;
    }
    else{
        double t3=t1+dist(lyd[j+1], lyd[j])-t2;
        pii cur3=pos(i, t3, 0);
        mini=min(mini, dist(cur3, lyd[j+1]));
        t1=t3;
        t2=0;
        j++;
    }
    return mini;
}


void solve(){
    cin>>n;
    forn(i,n) cin>>shad[i].first>>shad[i].second;
    cin>>m;
    forn(i,m) cin>>lyd[i].first>>lyd[i].second;

    int i=0; int j=0; double t1=0; double t2=0;
    double mini=1e12;
    while(i<n-1 && j<m-1){ 
        mini=min(solve2(i,t1,j,t2), mini);
    }
    cout<<fixed<<setprecision(6)<<mini<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin.tie(0);
    solve();
}
