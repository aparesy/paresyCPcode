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
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x

void solve(){
    ll a,b;
    cin>>a>>b;
    vl res(b+1);
    rep(i,0,b+1){
        res[i]=i;
    }

    ll cur=b+1; // éléments à traiter
    a=0;
    while (cur>0){
        ll k=log2(cur);
        rep(i,a,a+(1LL<<k)){
            res[i]=(1LL<<k)-(i-a)-1LL;
        }
        rep(i,a+(1<<k),b+1){
            res[2LL*(a+(1LL<<k))-i-1LL]+=(1LL<<k);
        }

        a+=(1LL<<k);


        cur-=(1LL<<k);
    }
    ll tot=0;
    rep(i,0,b+1LL){
        tot+=(i|res[i]);
    }
    cout<<tot<<"\n";
    rep(i,0,b+1){
        cout<<res[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    rep(i,0,n)
    solve();
}