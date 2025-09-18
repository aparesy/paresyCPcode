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
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x


void solve(){
    int n;
    cin>>n;
    vl tab(n);
    input(tab);
    ll minDif=INT_MAX;
    for (ll i=0;i<(1LL<<n);i++){
        ll tot=0;
        rep(j,0,n){
            if (i&(1LL<<j)){
                tot+=tab[j];
            }
            else tot-=tab[j];
        }
        if (abs(tot)<minDif)minDif=abs(tot);
    }
    cout<<minDif;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}