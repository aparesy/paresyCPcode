// Useful functions : nth_element, rotate, unique, merge, count, generate

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
using ll=long long;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x
#define all(x) x.begin(),x.end()

ll get(){
   ll x;
   cin>>x;
   return x;
}

int k;
ll inf=1e12;

struct streetGroup {
    vector<vl> adj;

    void init(ll x) {
        adj.resize(k);
        rep(i,0,k){
            adj[i].resize(k);
            rep(j,0,k){
                if (i!=j)adj[i][j] = x;
            }
        }
    }

    void addEdge(int a, int b, int t){ a%=k; b%=k; adj[a][b]=t; }
};

// helper to create an "identity" / neutral element
streetGroup make_unit() {
    streetGroup g;
    g.init(inf);
    return g;
}

struct Tree {
    using T = streetGroup;
    static T f(T a, T b) { T c=make_unit();
        rep(i,0,k) c.adj[i][i]=inf;
    rep(i,0,k){
        rep(j,0,k){
            rep(l,0,k){
                c.adj[i][j]=min(c.adj[i][j],a.adj[i][l]+b.adj[l][j]);
            }
        }
    } 
    return c;} // example associative function

    vector<T> s;
    int n;
    T unit;  // instance-level unit
    Tree(int n = 0) : n(n) {
        unit = make_unit();
        s.assign(2 * n, unit);
    }

    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }

    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit; 
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2){ra = f(ra, s[b++]);}
            if (e % 2){rb = f(s[--e], rb);}
        }
        return f(ra, rb);
    }
};

void solve(){
    int n,m,o;
    cin>>k>>n>>m>>o; n--;
    Tree tr(n/k);
    vector<streetGroup> tmp(n/k);
    rep(i,0,n/k){
        tmp[i].init(inf);
        rep(j,0,k){
            tmp[i].adj[j][j]=inf;
        }
    }
    rep(i,0,m){
        int a,b,t;
        cin>>a>>b>>t;
        tmp[a/k].addEdge(a,b,t);
    }
    rep(i,0,n/k){
        tr.update(i,tmp[i]);
    }
    rep(i,0,o){
        int l,r;
        cin>>l>>r;
        auto shortestTmp=tr.query(l/k,r/k);
        ll shortest=shortestTmp.adj[l%k][r%k];
        if (shortest>=inf){
            cout<<-1<<"\n";
        }
        else{
            cout<<shortest<<"\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}