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

void solve(ll x){
    x*=1e7;
    int n;
    cin>>n;
    unordered_map<ll,int> mp;
    ll maxi=-1;
    rep(i,0,n){
        ll a; cin>>a;
        if (mp.find(x-a)!=mp.end()){
            maxi=max(maxi,max(a,x-a));
        }
        mp[a]=1;
    }
    if (maxi==-1) cout<<"danger\n";
    else cout<<"yes "<<x-maxi<<" "<<maxi<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll x;
    for (unsigned int x; cin >> x;) {
        solve(x);
    }
}