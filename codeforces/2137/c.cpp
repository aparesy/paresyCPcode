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
    ll a,b;
    cin>>a>>b;
    if ((a%2)==0 && (b%2)==1){
        cout<<-1<<"\n";
        return;
    }
    if ((a%2) && (b%2)){
        cout<< a*b+1LL<<"\n";
        return;
    }
    if ((a%2)==0){
        cout<<2LL+a*(b/2LL)<<"\n";
        return;
    }    
    if ((b%4)==0){
        cout<<2LL+a*(b/2LL)<<"\n";
        return;
    }
    cout<<-1<<"\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}