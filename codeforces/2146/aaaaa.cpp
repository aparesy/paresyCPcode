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
    int n=12;
    int maxi=0;
    vi parm(n+1);
    rep(i,0,n+1){
        parm[i]=i;
    }
    do{
        int somme=0;
        rep(i,0,n+1){
            somme+=(parm[i]|i);
            if (somme>maxi)maxi=somme;
        }
    }
    while(next_permutation(parm.begin(),parm.end()));
    cout<<maxi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}