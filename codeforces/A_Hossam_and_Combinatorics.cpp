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
    ll n;
    cin>>n;
    vi tab(n);
    input(tab);
    sort(tab.begin(),tab.end());
    if (tab[0]==tab.back()){
        cout<<n*(n-1LL)<<"\n";
    }
    else{
        ll i=0;
        while (tab[i]== tab[0]){
            i++;
        }
        ll j=n-1;
        while(tab[j]==tab.back())j--;
        cout<<i*(n-j-1LL)*2LL<<"\n";
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