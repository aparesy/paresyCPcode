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
    int n,q;
    cin>>n>>q;
    vl tab(n);
    input(tab);


    // nv départ
    vl countBits(52);
    ll curOr=0;
    rep(i,0,n){
        rep(j,0,52)
        if (tab[i]&(1LL<<j)) countBits[j]++;
        curOr|=tab[i];
    }
    int totBits=0;
    rep(i,0,52) if (countBits[i]) totBits++;
    vector<pair<ll,int>> cheapest(52);
    vl needed(52);
    int i=0;
    while (i<totBits){
        needed[i]=0;
        i++;
    }
    while(i<52){
        ll j=0;
        while ((1LL<<j)&curOr) j++;
        int i2=0;
        ll mini=(1LL<<52LL);
        rep(k,0,n){
            ll reste=(1LL<<j)-(tab[k]&((1LL<<(j+1LL))-1LL));
            if (reste<mini){
                mini=reste;
                i2=k;
            }
        }
        needed[i]=(i==0?0:needed[i-1])+mini;
        for (ll k=0;k<j;k++){
            if (tab[i2]&(1LL<<k)){
                countBits[k]--;
                if (countBits[k]==0){
                    countBits[k]++;
                    needed[i]+=1LL<<k;
                }
            }
        }
        countBits[j]++;
        curOr|=(1LL<<j);
        totBits++;
        i++;
    }


    rep(i,0,q){
        ll b;
        cin>>b;
        int k=0;
        while (needed[k]<=b)i++;
        cout<<k-1LL;
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