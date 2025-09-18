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
    ll x;
    cin>>x;
    vector<pair<ll,ll>> tab(n);
    rep(i,0,n){
        ll y;
        cin>>y;
        tab[i]={y,i};
    }
    sort(tab.begin(),tab.end());
    int i1=0;
    int i2=n-1;
    while(i1<i2){
        while (tab[i1].first+tab[i2].first>x) i2--;
        if (i1<i2&&(tab[i1].first+tab[i2].first==x)){
            cout<<tab[i1].second+1<<" "<<tab[i2].second+1;
            return;
        }
        i1++;
    }
    cout<<"IMPOSSIBLE";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}