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

int luck(ll x){
    int minDig=9;
    int maxDig=0;
    while (x){
        int dig=x%10;
        if (dig<minDig) minDig=dig;
        if (dig>maxDig) maxDig=dig;
        x/=10;
    }
    return maxDig-minDig;
}

void solve(){
    ll l,r;
    cin>>l>>r;
    ll maxi=0;
    ll max_i=l;
    rep(i,l,min(r+1,l+100)){
        if (luck(i)>maxi){
            max_i=i;
            maxi=luck(i);
        }
    }
    cout<<max_i<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}