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
    ll n,f,a,b;
    cin>>n>>f>>a>>b;
    vl tab(n);
    input(tab);
    if (tab[0]*a > b){
        f-=b;
    }
    else f-=tab[0]*a;
    rep(i,0,n-1){
        if((tab[i+1]-tab[i])*a>b){
            f-=b;
        }
        else f-=(tab[i+1]-tab[i])*a;
    }
    if (f>0) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}