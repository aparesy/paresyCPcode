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

ll rev(ll n){
    ll tmp=0LL;
    while (n){
        tmp*=10LL;
        tmp+=(n%10LL);
        n/=10LL;
    }
    return tmp;
}

void solve(){
    ll x,y;
    cin>>x>>y;
    rep(i,0,9){
        ll tmp=x;
        x=y;
        y=rev(tmp+y);
    }
    cout<<x<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}