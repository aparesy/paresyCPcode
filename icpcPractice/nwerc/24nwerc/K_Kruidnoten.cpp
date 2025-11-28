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

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vii> adj(n);
    rep(i,0,m){
        int a,b,l;
        cin>>a>>b>>l;
        a--;b--;
        adj[a].push_back({b,l});
        adj[b].push_back({a,l});
    }

    vl dist1(n,-1);
    dist1[0]=0;
    priority_queue<pii, vii, greater<pii>> q;
    q.push({0,0});
    while (!q.empty()){
        auto [dist, s]=q.top();
        q.pop();
        for (auto [t,l] : adj[s]){
            if (dist1[t]==-1 || dist1[t]>dist+l){
                dist1[t]=dist+l;
                q.push({dist+l, t});
            }
        }
    }

    vl dist2(n,-1);
    dist2[n-1]=0;
    q.push({0,n-1});
    while (!q.empty()){
        auto [dist, s]=q.top();
        q.pop();
        for (auto [t,l] : adj[s]){
            if (dist2[t]==-1 || dist2[t]>dist+l){
                dist2[t]=dist+l;
                q.push({dist+l, t});
            }
        }
    }

    double curCoef=1.;
    double res=0.;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}