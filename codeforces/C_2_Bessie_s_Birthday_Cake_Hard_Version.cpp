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
    ll n,x,y;
    cin>>n>>x>>y;
    vl tab(x);
    input(tab);
    sort(all(tab));
    ll totCur=max(0ll,x-2ll);
    multiset<ll> trous;
    rep(i,0,x-1){
        trous.insert(tab[i+1]-tab[i]);
    }
    trous.insert(n+tab[0]-tab[x-1]);
    for (auto it = trous.begin(); it!=trous.end(); it++){
        ll tmp=(*it);
        if (tmp%2) continue;
        if (tmp==2) totCur++;
        else if (y>=tmp/2ll-1ll){
            y-=(tmp/2ll-1ll);
            totCur+=tmp/2ll;
        }
    }
    for (auto it = trous.begin(); it!=trous.end(); it++){
        ll tmp=(*it);
        if ((tmp%2ll)==0) continue;
        else if (y && y>=tmp/2ll){
            y-=(tmp/2ll );
            totCur+=tmp/2ll+1ll;
        }
    }
    cout<<totCur+y<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}