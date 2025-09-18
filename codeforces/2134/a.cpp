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
    ll n,a,b;
    cin>>n>>a>>b;
    if (a>b){
        if ((n-a)%2LL){
            cout<<"NO\n";
            return;
        }
        if (b!=0 && ((n-b)%2LL)){
            cout<<"NO\n";
            return;
        }
        cout<<"YES\n";
        return;
    }
    if (b==0){
        cout<<"YES\n";
            return;
    }
    if ((n-b)%2LL){
        cout<<"NO\n";
            return;
    }
    cout<<"YES\n";
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