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
    ll r,n;
    cin>>r>>n;
    vl tab(n);
    input(tab);
    ll lbound=0;
    ll rbound=r;
    rep(i,0,n){
        if (tab[i]>=0){
            lbound+=tab[i];
            rbound+=tab[i];
            rbound=min(r,rbound);
            lbound=min(rbound,lbound);
        }
        else{
            rbound+=tab[i];
            lbound+=tab[i];
            lbound=max(0ll,lbound);
            rbound=max(rbound,lbound);
        }
    }
    if (lbound!=rbound){
        cout<<"uncertain";
    }
    else{
        cout<<lbound;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}