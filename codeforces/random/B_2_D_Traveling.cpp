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
    ll n,k,a,b;
    cin>>n>>k>>a>>b; a--;b--;
    vector<pair<ll,ll>> cities(n);
    rep(i,0,n){
        cin>>cities[i].first>>cities[i].second;
    }
    ll minA=1e15;
    ll minB=1e15;
    rep(i,0,k){
        minA=min(minA, abs(cities[a].first-cities[i].first) + abs(cities[a].second-cities[i].second));
        minB=min(minB, abs(cities[b].first-cities[i].first) + abs(cities[b].second-cities[i].second));
    }

    cout<<min(minA+minB, abs(cities[a].first-cities[b].first)+abs(cities[a].second-cities[b].second))<<"\n"
    ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}