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
    ll n,k;
    cin>>n>>k;
    vl tab(n);
    input(tab);
    // Is a given level x reachable ? You just need to complete to x

    ll l=0;
    ll r=1e13;
    while (r-l>1ll){
        ll m=(r+l)/2ll;
        ll tot=0;
        rep(i,0,n){
            tot+=max(0ll, m-tab[i]);
        }
        if (tot>k){
            r=m;
        }
        else l=m;
    }
    
    rep(i,0,n){
        if (tab[i]<l){
            k-=(l-tab[i]);
            tab[i]=l;
        }
    }
    ll extra=0;
    rep(i,0,n){
        if (tab[i]==l && k){
            k--;
            extra++;
        }
        else if (tab[i]>l){
            extra++;
        }
    }
    cout<<extra+n*l-(n-1ll)<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}