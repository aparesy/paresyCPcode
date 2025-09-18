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

void dfs(vector<vii>& adj2, int s, vi& cost, vb& vu, ll& tot){
    for (auto t : adj2[s]){
        if (cost[t.first]<cost[s] && cost[t.first]!=-1 && cost[s]!=-1 && t.second==cost[s]-cost[t.first]){
            tot+=t.second;
            if (!vu[t.first]){
                vu[t.first]=true;
                dfs(adj2,t.first,cost,vu,tot);
            }
        }
    }
}

void solve(){
    int t,p;
    cin>>t>>p;
    vi cost(t,-1);
    vector<vii> adj(t);
    vector<vii> adj2(t);
    rep(i,0,p){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0,0});
    while (!q.empty() && (cost[t-1]==-1 || (cost[t-1]>=(q.top()).first))){
        auto [poidsS,s]=q.top();
        q.pop();
        if (cost[s]==-1){
            cost[s]=poidsS;
            for (auto [t,poids] : adj[s]){
                if (cost[t]==-1 || (cost[t]>=cost[s]+poids)){
//                    cost[t]=cost[s]+poids;
                    q.push({cost[s]+poids,t});
                    adj2[t].push_back({s,poids});
                    adj2[s].push_back({t,poids});
                }
            }
        }
    }

    vb vu(t,false); vu[t-1]=true;
    ll tot=0LL;
    dfs(adj2,t-1,cost,vu,tot);
    cout<<tot*2LL;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}