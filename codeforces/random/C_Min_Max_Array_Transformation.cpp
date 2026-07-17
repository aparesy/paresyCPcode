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
    vl a(n);
    vl b(n);
    input(a);
    input(b);
    // a est borné par b; pour un di le min corre
    int i=0;
    rep(j,0,n){
        while(b[i]<a[j]) i++;
        cout<<b[i]-a[j]<<" ";
    }
    cout<<"\n";
    // le max n'est pas le max : il faut avancer tant que a[i+1]<=b[i]
    i=0;
    rep(j,0,n){
        if (i<j)i++;
        while (i<n-1 && a[i+1]<=b[i]) i++;
        cout<<b[i]-a[j]<<" ";
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}