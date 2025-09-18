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
    string s;
    cin>>s;
    int q;
    cin>>q;
    int  n=s.length();
    unsigned int mod=1e9+7;
    vector<unsigned int> prefixHash(n+1);
    prefixHash[0]=0;
    rep(i,0,n){
        prefixHash[i+1] = prefixHash[i]*(mod);
    }
    rep(i,0,q){
        int a,b;
        cin>>a>>b;
        cout<< 
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}