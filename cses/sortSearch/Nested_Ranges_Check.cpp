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
    vector<pair<pii,int>> tab(n);
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        tab[i]={make_pair(x,y),i};
    }
    vi ok(n);
    sort(tab.begin(),tab.end(),[](pair<pii,int>& p1, pair<pii,int>& p2){if (p1.first.first==p2.first.first) return p1.first.second<p2.first.second; return p1.first.first>p2.first.first;});
    int mini=INT_MAX;
    rep(i,0,n){
        if (tab[i].first.second<mini){
            mini=tab[i].first.second;
        }
        else ok[tab[i].second]=1;
    }
    rep(i,0,n){
        cout<<ok[i]<<" ";
    }
    cout<<"\n";

    vi ok2(n);
    sort(tab.begin(),tab.end(), [](pair<pii,int>& p1, pair<pii,int>& p2){if (p1.first.first==p2.first.first) return p1.first.second>p2.first.second; return p1.first.first<p2.first.first;});
    int maxi=0;
    rep(i,0,n){
        if (tab[i].first.second>maxi){
            maxi=tab[i].first.second;
        }
        else ok2[tab[i].second]=1;
    }
    rep(i,0,n){
        cout<<ok2[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}