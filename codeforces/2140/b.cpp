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

int nbDigits(int n){
    if (n==0) return 0;
    return nbDigits(n/10)+1;
}

void solve(){
    ll x;
    cin>>x;
   // cout << (x*(ll)(pow(10,nbDigits(x)+1))+2*x) <<"\n";
   cout<<2LL*x<<"\n";
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}