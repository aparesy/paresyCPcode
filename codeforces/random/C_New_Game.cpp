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
    int n,ka;
    cin>>n>>ka;
    vi tab(n);
    input(tab);
    map<int,int> count;
    rep(i,0,n){
        count[tab[i]]++;
    }
    int indexFirst=count.begin()->first;
    ll cur=0;
    int maxi=0;
    int curKey=indexFirst;
    for (auto [k,v]:count){
        if (k==curKey){
            cur+=v;
            if (k-indexFirst>=ka){
                cur-=count[k-ka];
            }
        }
        else{
            curKey=k;
            indexFirst=k;
            cur=v;
        }
        if (maxi<cur) maxi=cur;
        curKey++;
    }
    cout<<maxi<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}