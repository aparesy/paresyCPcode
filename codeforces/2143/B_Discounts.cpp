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
    int n,m;
    cin>>n>>m;
    vl tab(n);
    input(tab);
    vi voucher(m);
    input(voucher);
    sort(voucher.begin(),voucher.end());
    sort(tab.begin(),tab.end(), [](ll a, ll b){return a>b;});
    int i=0;
    int j=0;
    ll tot=0;
    while (j<m && voucher[j] <= n-i){
        rep(k,i,i+voucher[j]-1){
            tot+=tab[k];
        }
        i+=voucher[j];
        j++;
    }
    rep(k,i,n){
        tot+=tab[k];
    }
    cout<<tot<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}