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
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    if (a+b>n){
        cout<<"NO\n";
        return;
    }
    if (a==0 && b==0){
        cout<<"YES\n";
        rep(i, 0, n) cout<<i+1<<" ";
        cout<<"\n";
        rep(i, 0, n) cout<<i+1<<" ";
        cout<<"\n";
        return;
    }
    if (a==0 || b==0){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    vi orda;
    rep(i,0,n-a-b){
        orda.push_back(i+1);
    }
    rep(i,n-a-b,n-b){
        orda.push_back(i+b+1);
    }
    rep(i,n-b,n){
        orda.push_back(i+1-a);
    }
    for (auto x : orda) cout<<x<<" ";
    cout<<"\n";
    rep(i,1,n+1) cout<<i<<" ";
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