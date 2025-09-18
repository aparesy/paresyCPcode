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
    vector<pair<ll,ll>> tab(n);
    rep(i,0,n){
        ll a,b;
        cin>>a>>b;
        tab[i]={a,b};
    }
    sort(tab.begin(),tab.end(), [](auto& a, auto& b){if (a.second==b.second) return a.first<b.first; return a.second<b.second;});
    int tot=0;
    int i=0;
    int time=0;
    while (i<n){
        if (tab[i].first>=time){
            time=tab[i].second;
            tot++;
        }
        i++;
    }
    cout<<tot;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}