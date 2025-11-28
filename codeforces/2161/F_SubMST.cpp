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
#define sz(tab) tab.size()

ll get(){
   ll x;
   cin>>x;
   return x;
}



ll mod=1e9+7ll;

vl dist[5001];

void dfs(int s, vb& vu, vvi& adj){
    vu[s]=true;
    dist[s][s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for (auto t : adj[v]){
            if (!vu[t]){
                dist[s][t]=dist[s][v]+1;
                q.push(t);
                vu[t]=true;
            }
        }
    }
}


ll pow2[5001];

void solve(){
    ll n=get();
    rep(i,0,n){
        dist[i].clear();
        dist[i].resize(n);
    } // 0 indexed
    vvi adj(n);
    rep(i,0,n-1){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    rep(i,0,n){
        vb vu(n);
        dfs(i,vu, adj);
    }
    vl occDist(n);
    ll tot=0;

    rep(i,0,n){
        rep(j,i+1,n){
            // Nombre de sommets dont au moins une des distances est supérieure ou égale 

        }
    }
    rep(i,0,n){
        occDist[i]/=2ll;
    }
    // Distance max : n-1

    ll curPow2=1;
    for (ll distCur=n-1ll; distCur>=1; distCur--){
        tot+=curPow2*occDist[distCur]*distCur;
        tot%=mod;
        curPow2*=2ll;
        curPow2%=mod;
    }
    cout<<tot<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pow2[0]=1;
    rep(i,1,5001){
        pow2[i]=2ll*pow2[i-1];
        pow2[i]%=mod;
    }
    int t; cin>>t; rep(i,0,t)
    solve();
}