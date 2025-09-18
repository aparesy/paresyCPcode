#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

int main(){
    ll n;
    ll m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n);
    ll a,b,w;
    for (int i=0;i<m;i++){
        cin>>a>>b>>w; a--;b--;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }
    vector<vector<ll>> fw(n,vector<ll>(n,LLONG_MAX));
}