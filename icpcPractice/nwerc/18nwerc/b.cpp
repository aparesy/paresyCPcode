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
    ll n=get();
    vector<pair<ll,vector<int>>> meetings(n);
    rep(i,0,n){
        cin>>meetings[i].first;
        int m=get();
        rep(i,0,m){
            ll dep=get();
            meetings[i].second.push_back(dep-1);
        }
    }
    vvi adj(n);
    rep(i,0,n){
        for(auto x : meetings[i].second){
            adj[x].push_back(i);
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}