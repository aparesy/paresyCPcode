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

int res(int a, int aa, int p, int turn){
    if (turn==p){
        //cout<<a<<" "<<aa<<" "<<p<<"\n";
        return max(a,aa) - (p?aa:a);
    }
    else{
        return min(a,aa) - (p?aa:a) ;
    }
}
int t[4*MAXN];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return E18;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(sum(v*2, tl, tm, l, min(r, tm))
           , sum(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

int tab[MAXN];

void solve(){
    int q;
    cin>>q;
    int a=E18;
    int aa=E18;
    forn(i,n){
        cin>>tab[i];
    }
    build(tab, 1, 0, n-1);
    int part=0;
    forn(i,(n+1)/2){
        part+=tab[i];
        a=min(tab[i],a);
    }
    int part2=0;
    for (int i=(n+1)/2;i<n;i++){
        part2+=tab[i];
        aa=min(tab[i],aa);
    }
    int turn=0;
    if ((n%2)){
        turn=1;
    }
    cout<<part+res(a,aa,0,turn)<<" "<<part2+res(a,aa,1,turn)<<"\n";
    forn(i,q){
        int j;
        cin>>j;
        j--;
        int x;
        cin>>x;
        if (j>=(n+1)/2){
            part2-=tab[j];
            part2+=x;
            tab[j]=x;
            update(1,0,n-1,j,x);
            aa=sum(1,0,n-1,(n+1)/2,n-1);
        }
        else{
            part-=tab[j];
            part+=x;
            tab[j]=x;
            update(1,0,n-1,j,x);
            a=sum(1,0,n-1,0,(n+1)/2-1);
        }
        //cout<<"aaa"<<a<<" "<<aa<<"\n";
        cout<<part+res(a,aa,0,turn)<<" "<<part2+res(a,aa,1,turn)<<"\n";
    }
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while (cin>>n) solve();
}