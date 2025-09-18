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
    bool toutNeg=true;
    rep(i,0,n){
        if (tab[i]>=0) toutNeg=false;
    }
    if (toutNeg){
        cout<<*max_element(tab.begin(),tab.end());
        return;
    }
    ll curMin=0LL;
    ll curCum=0LL;
    ll curMax=0LL;
    rep(i,0,n){
        curCum+=tab[i];
        if (curCum<curMin){
            curMin=curCum;
        }
        if (curCum-curMin>curMax){
            curMax=curCum-curMin;
        }
    }
    cout<<curMax;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}