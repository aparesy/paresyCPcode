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
int n;
int q;

struct dsu{
    vi p;
    vi r;
    vi blue;
    vi red;
    vi taille;
    bitset<MAXN> tree;
    void init(){
        p.resize(n);
        rep(i,0,n){p[i]=i;}
        r.resize(n);
        blue.resize(n);
        red.resize(n);
        taille.resize(n);
        forn(i,n) taille[i]=1;
        forn(i,n) tree[i]=true;
    }
    int find(int a){
        if (p[a]==a) return a;
        return p[a]=find(p[a]);
    }
    void _union(int a, int b, int& maxBlue, int& maxRed, int& nbComposantes){
        a=find(a);
        b=find(b);
        if (a==b){
            if (tree[a]){
                tree[a]=false;
                maxBlue+=min(blue[a], max(0ll,blue[a]+red[a]-(taille[a]-1)));
                maxRed+=min(red[a], max(0ll,blue[a]+red[a]-(taille[a]-1)));
            }
            return;
        } 
        nbComposantes--; 
        if (r[a]<r[b]) swap(a,b);
        if (r[a]==r[b]) r[a]++;
        p[b]=a;
        blue[a]+=blue[b];
        red[a]+=red[b];
        taille[a]+=taille[b];
    }
};

void solve(){
    cin>>n>>q;
    int maxBlue=0;
    int maxRed=0;
    int nbComposantes=n;
    dsu uf;
    uf.init();
    forn(i,q){
        int c,u,v;
        cin>>c>>u>>v;
        u--; v--;
        int a=uf.find(u);
        int b=uf.find(v);
        if (c==1){
            uf.blue[a]++;
            if (a==b){
                maxBlue++;
                if (uf.blue[a]<=uf.taille[a]-1){
                    maxRed++;
                }
            }
        }
        else{
            uf.red[a]++;
            if (a==b){
                maxRed++;
                if (uf.red[a]<=uf.taille[a]-1){
                    maxBlue++;
                }
            }
        }
        uf._union(a,b,maxBlue,maxRed,nbComposantes);
        cout<<min(max(0ll, (i+1-(n-nbComposantes))/2*2), min(maxBlue,maxRed)*2)<<"\n";
    }
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