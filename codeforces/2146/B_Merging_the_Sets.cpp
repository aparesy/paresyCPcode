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
    ll n,m;
    cin>>n>>m;
    vvl tabs(n);
    rep(i,0,n){
        int tabLength;
        cin>>tabLength;
        tabs[i].resize(tabLength);
        input(tabs[i]);
    }

    vvi elemCount(m+1);
    rep(i,0,n){
        for (auto x : tabs[i]){
            elemCount[x].push_back(i);
        }
    }
    vb obligado(n);
    int obCount=0;
    rep(i,1,m+1){
        if (elemCount[i].size()==0){
            cout<<"NO\n";
            return;
        }
        if(elemCount[i].size()==1 && !obligado[elemCount[i][0]]){
            obligado[elemCount[i][0]]=true;
            obCount++;
        }
    }
    if (obCount==n || obCount==n-1){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}