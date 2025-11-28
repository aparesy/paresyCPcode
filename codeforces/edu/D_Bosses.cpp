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

vi r;

struct uf{
    vi p;
    void init(int n){
        p.resize(n);
        iota(p.begin(), p.end(), 0); // initializes p[0]=0, p[1]=1, ..., p[n-1]=n-1
        r.resize(n);
    }
    int get(int a){
        return p[a] = (p[a]==a?a:get(p[a]));
    }
    void uni(int a, int b){
        // b devient boss de a
        a=get(a);
        b=get(b);
        if (r[a]==r[b]){
            r[b]++;
        }
        p[a]=b;

    }
};

void solve(){
    int n,m;
    cin>>n>>m;
    n++;
    uf dsu;
    dsu.init(n);
    rep(i,0,m){
        int a;
        cin>>a;
        if (a==1){
            int x,y;
            cin>>x>>y;
            dsu.uni(x,y);
        }
        else{
            int x;
            cin>>x;
            cout<<r[dsu.get(x)]-r[x]<<"\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}