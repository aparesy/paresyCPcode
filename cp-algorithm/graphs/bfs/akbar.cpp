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



void solve(){
    int n,r,m;
    cin>>n>>r>>m;n++;
    vector<vector<int>> adj(n, vi(n)); 
    rep(i,0,r){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
            vector<bool> used(n);
        vector<int> d(n), p(n);
    rep(i,0,m){
        int s,strength;
        cin>>s>>strength;
    

        queue<int> q;


        q.push(s);
        used[s] = true;
        p[s] = -1;
        while (!q.empty() && d[p[q.front()]] <= strength) {
            int v = q.front();
            q.pop();
            for (int u : adj[v]) {
                if (!used[u]) {
                    used[u] = true;
                    q.push(u);
                    d[u] = d[v] + 1;
                    p[u] = v;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}