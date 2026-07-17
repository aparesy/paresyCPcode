#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define vi vector<int>
#define forn(i,n) for (int i=0;i<n;i++)
int modint=1e9+7ll;
signed main(){
    int n;
    cin>>n;
    vi h(n);
    forn(i,n) cin>>h[i];
    set<pair<int,int>> st;
    forn(i,n) st.insert({h[i],i});
    int m;
    cin>>m;
    vector<vi> adj(n);
    forn(i,m){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int s,t;
    cin>>s>>t;
    s--; t--;
    vi dp(n);
    dp[s]=1;
    for (auto [hauteur,sommet] : st){
        for (auto voisin : adj[sommet]){
            if (h[voisin]>h[sommet]){
                dp[voisin]+=dp[sommet];
                dp[voisin]%=modint;
            }
        }
    }
    // forn(i,n) cout<<dp[i]<<" ";
    // cout<<"\n";
    cout<<dp[t]<<"\n";
}