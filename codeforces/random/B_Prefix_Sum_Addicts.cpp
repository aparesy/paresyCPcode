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
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    vl tab(k);
    input(tab);
    if (k==1){
        cout<<"Yes\n"; return;
    }
    ll curDif=tab[1]-tab[0];
    if ((n-k+1ll)*curDif<tab[0]){
        cout<<"No\n";
        return;
    }
    rep(i,0,k-1){
        if (tab[i+1]-tab[i]<curDif){
            cout<<"No\n";
            return;
        }
        else curDif=tab[i+1]-tab[i];
    }
    cout<<"Yes\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}