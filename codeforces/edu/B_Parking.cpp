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

// Même chose mais à la place de l'élt final on boucle

vi getMax;

struct uf{
    vi p; vi r;
    void init(int n){
        p.resize(n);
        iota(p.begin(), p.end(), 0); // initializes p[0]=0, p[1]=1, ..., p[n-1]=n-1
        r.resize(n);
    }
    int get(int a){
        return p[a] = (p[a]==a?a:get(p[a]));
    }
    void uni(int a, int b){
        a=get(a);
        b=get(b);
        if (r[a]==r[b]){
            r[a]++;
        }
        if (r[a]>r[b]){
            getMax[a]=getMax[b];
            p[b]=a;
        }
        else{
            p[a]=b;
            getMax[a]=getMax[b];
        }

    }
};

void solve(){
    int n,q;
    cin>>n;
    n++;
    uf dsu;
    getMax.resize(n);
    dsu.init(n);
    rep(i,0,n){
        getMax[i]=i;
    }
    rep(i,1,n){
        int k;
        cin>>k;
        int target=getMax[dsu.get(k)];
        cout<<target<<" ";
        dsu.uni(target, target==n-1?1:target+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}