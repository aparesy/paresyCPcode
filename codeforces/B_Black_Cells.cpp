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
    sort(tab.begin(),tab.end());
    ll l=0;
    ll r=tab[n-1]-tab[0]+1LL;
    while (r-l>1LL){
        ll k=(r+l)/2LL;
        int tot=0;
        rep(i,0,n-1){
            if (i==n-2 && tab[i+1]-tab[i]>k) tot+=2;
            if (tab[i+1]-tab[i]<=k){
                if (i==n-3) tot++;
                i++;
            }
            else tot++;
        }
        if (tot>1){
            l=k;
        }
        else r=k;
    }
    cout<<r<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}