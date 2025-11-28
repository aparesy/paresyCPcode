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

const int MAXN=100001;

struct node {
    int push = 0;
    int val = 0;
};
vl TAB;
node T[4 * MAXN];
 
void push(int v, int tl, int tr) {
    if (T[v].push == 0) return;
    T[v].val += T[v].push * (tr - tl + 1);
    if (tl != tr) {
        T[2*v].push += T[v].push;
        T[2*v+1].push += T[v].push;
    }
    T[v].push = 0;
}
 
void build(int v, int tl, int tr) {
    if (tl == tr) {
        T[v].val = TAB[tl];
        T[v].push = 0;
        return;
    }
    int tm = (tl + tr) / 2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    T[v].val = T[2*v].val +  T[2*v+1].val;
}
 
int get(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (l > tr || tl > r  || l > r) return 0;
    if (l <= tl && tr <= r) {
        return T[v].val;
    }
    int tm = (tl + tr) / 2;
    return
        get(2*v, tl, tm, l, r) + 
        get(2*v+1, tm+1, tr, l, r);
}
 
void set_(int v, int tl, int tr, int l, int r, int x) {
    push(v, tl, tr);
    if (l > tr || tl > r || l > r) return;
    if (l <= tl && tr <= r) {
        T[v].val = x;
        return;
    }
    int tm = (tl + tr) / 2;
    set_(2*v, tl, tm, l, r, x); 
    set_(2*v+1, tm+1, tr, l, r, x);
}
 
void add(int v, int tl, int tr, int l, int r, int x) {
    push(v, tl, tr);
    if (l > tr || tl > r  || l > r) return;
    if (l <= tl && tr <= r) {
        T[v].push += x;
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    add(2*v, tl, tm, l, r, x); 
    add(2*v+1, tm+1, tr, l, r, x);
}

void solve(){
    int n,m;
    cin>>n>>m;
    
    input(tab);
    rep(i,0,n){
        TAB[i]=tab[i];
    }
    rep(i,0,n){
        build(0,0,n);
    }
    rep(i,0,m){
        int c;
        ll l,r;
        cin>>c>>l>>r;
        if (c==1){
            set_(r,0,n,l,l+1)
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}