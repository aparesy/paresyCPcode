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
    ll x;
    int n;
    cin>>x>>n;
    vl tab(n);
    input(tab);
    priority_queue<pair<ll,pii>, vector<pair<ll,pii>>> q;
    q.push({x,make_pair(0,x)});
    rep(i,0,n){
        auto [a,[b,c]]=q.top();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}