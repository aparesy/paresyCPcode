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

// Comment unir un segment ? Création de chaines dans un dsu. Au plus un lien 

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
            p[b]=a;
        }
        else{
            p[a]=b;
        }

    }
};

struct uf2{
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
            getMax[a]=max(getMax[a],getMax[b]);
            p[b]=a;
        }
        else{
            getMax[b]=max(getMax[a],getMax[b]);
            p[a]=b;
        }

    }
};

void solve(){
    int n,q;
    cin>>n>>q;
    n++;
    uf dsu;
    uf2 dsuInterval;
    dsu.init(n);
    dsuInterval.init(n);
    getMax.resize(n);
    iota(getMax.begin(),getMax.end(),0);
    rep(i,0,q){
        int a,b,c;
        cin>>a>>b>>c;
        switch (a)
        {
        case 1:
            dsu.uni(c,b);
            break;
        
        case 2:
            if (c==b) break;
            swap(b,c);
            c=getMax[dsuInterval.get(c)];
            while(c<b){
                dsu.uni(c,c+1);
                dsuInterval.uni(c,c+1);
                c=getMax[dsuInterval.get(c)];
            }
            break;
        default:
            if (dsu.get(c)==dsu.get(b)) cout<<"YES\n";
            else cout<<"NO\n";
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}