#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x

int r1,r2,r3;

struct uf{
    vi p;
    vi r;
    vi mini; vi maxi; vi sizeuf;
    void init(int n){
        p.resize(n);
        r.resize(n);
        score
        rep(i,0,n){
            p[i]=i;
            mini[i]=i;
            maxi[i]=i;
            sizeuf[i]=1;
        }
    }
    int get(int u){
        if (p[u]==u){
            r1=mini[u];
            r2=maxi[u];
            r3=sizeuf[u];
            return u;
        }
        else{
            int tmp=get(p[u]);
            p[u]=tmp;
            return tmp;
        }
    }
    void unionF(int u, int v){
        u=get(u);
        v=get(v);
        if (p[u]==p[v]) return;
        if (r[u]==r[v]) r[u]++;
        if (r[u]>r[v]){
            p[v]=u;
            mini[u]=min(mini[u],mini[v]);
            maxi[u]=max(maxi[u],maxi[v]);
            sizeuf[u]=sizeuf[u]+sizeuf[v];
        }
        else{
            p[u]=v;
            mini[v]=min(mini[u],mini[v]);
            maxi[v]=max(maxi[u],maxi[v]);
            sizeuf[v]=sizeuf[u]+sizeuf[v];
        }
    }
};

void solve(){
    int n,q;
    cin>>n>>q;
    uf tmp;
    tmp.init(n+1);
    rep(i,0,q){
        string s;
        cin>>s;
        int a,b;
        if (s[0]=='u'){
            cin>>a>>b; 
            tmp.unionF(a,b);
        }
        else{
            cin>>a; 
            tmp.get(a);
            cout<<r1<<" "<<r2<<" "<<r3<<"\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}