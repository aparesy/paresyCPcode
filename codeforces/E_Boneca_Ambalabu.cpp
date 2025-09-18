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
    int n;
    cin>>n;
    vl tab(n);
    input(tab);
    vi count(30);
    for (ll x : tab){
        rep(i,0,30){
            if (1&(x>>i)) count[i]++;
        }
    }
    ll maxi=0LL;
    ll cur;
    rep(i,0,n){
        cur=0;
        rep(j,0,30){
            if (1&(tab[i]>>j)){
                cur+=((ll)(n-count[j]))*(1LL<<j);
            }
            else cur+=((ll)count[j])*(1LL<<j);
        }
        if (maxi<cur)maxi=cur;
    }
    cout<<maxi<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    rep(i,0,t)
    solve();
}