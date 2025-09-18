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

void dfs(int s, vi& num, int& high, int& low, int n, vector<vector<pair<int,pair<ll,ll>>>>& adj, vb& vu){
    for (auto [t,poids] : adj[s]){
        if (!vu[t]){
            vu[t]=true;
            dfs(t,num,high,low,n,adj,vu);
            auto [p1,p2]=poids;
            if (s>t) swap(p1,p2);
            if (p1>p2){
                num[t]=low;
                low++;
            }
            else{
                num[t]=high;
                high--;
            }
        }
    }
}

void solve(){
    int n;
    cin>>n;
    vector<vector<pair<int,pair<ll,ll>>>> adj(n+1);
    int low=1;
    vb vu(n+1);
    int high=n;
    rep(i,0,n-1){
        int u,v;
        ll x,y;
        cin>>u>>v>>x>>y;
        adj[v].push_back({u,make_pair(x,y)});
        adj[u].push_back({v,make_pair(x,y)});
    }
    vi num(n+1);
    vu[1]=true;
    dfs(1,num,high,low,n,adj,vu);
    num[1]=low;
    rep(i,0,n) cout<<num[i+1]<<" ";
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}