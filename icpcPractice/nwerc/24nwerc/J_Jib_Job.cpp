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
    int n=get();
    vector<pair<pair<ll,ll>,ll>> tab(n);
    rep(i,0,n){
        ll x,y,h;
        cin>>x>>y>>h;
        tab[i]={{x,y},h};
    }
    rep(i,0,n){
        ll longueur=tab[i].second;
        rep(j,0,n){
            if (tab[i].second<tab[j].second) longueur=min(longueur, (ll)hypot(tab[i].first.first-tab[j].first.first, tab[i].first.second-tab[j].first.second));
        }
        cout<<longueur<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}