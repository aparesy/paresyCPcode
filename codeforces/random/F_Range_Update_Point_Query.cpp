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

void reduire(ll& x){
    ll y=0;
    while(x){
        y+=x%10LL;
        x/=10LL;
    }
    x=y;
}

struct node{
    ll val;
    bool done;
};

struct segtree{  // Directly indicate whether the subtree is done 
    vector<node> tab;
    int n;
    void init(vl& tab2){
        n=tab2.size();
        tab.resize(4*n);
    }
    void build(vl& tab2, int v, int tl, int tr){
        if (tl==tr){
            tab[v].val=tab2[tl];
        }
        else{
            int tm=(tl+tr)/2;
            build(tab2,v*2,tl,tm);
            build(tab2,v*2+1,tm+1,tr);
        }
    }
    ll get(int i, int tl, int tr, int v){
        if (tl==tr){
            return tab[v].val;
        }
        // How to go down in the correct node ?
        int tm=(tl+tr)/2;
        if (i<=tm){
            return get(i,tl,tm,v*2);
        }
        else return get(i,tm+1,tr,v*2+1);
    }
    void update(int l, int r, int tl, int tr, int v){
        if (tab[v].done==true) return;
        if (tl==tr){
            reduire(tab[v].val);
            if (0<=tab[v].val && tab[v].val<10) tab[v].done=true;
        }
        else{
            int tm=(tl+tr)/2;
            // On traite tl tm si l est suffisamment à gauche
            if (l<=tm){
                update(l,r,tl,tm,v*2);
            }
            if (r>=tm+1){
                update(l,r,tm+1,tr,v*2+1);
            }
            if (tab[v*2].done && tab[v*2+1].done) tab[v].done=true;
        }
    }
};

ll get(){
   ll x;
   cin>>x;
   return x;
}

void solve(){
    int n,q;
    cin>>n>>q;
    vl tab(n);
    input(tab);
    // Lets say each elt takes at most 10 queries
    // Though if we do naive, TLE because process whole segment
    // segtree allows segment processing in logn to only access concerned elts, + you can make an exact tree to determine which segments to access
    segtree seg;
    seg.init(tab);
    seg.build(tab,1,0,n-1);
    rep(i,0,q){
        int w;
        cin>>w;
        if (w==1){
            int x,y;
            cin>>x>>y;
            x--;y--;
            seg.update(x,y,0,n-1,1);
        }
        else{
            int x;
            cin>>x;
            cout<<seg.get(x-1,0,n-1,1)<<"\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=get();
    rep(i,0,t)
    solve();
}