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
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x

void solve(){
    int n;
    ll s;
    cin>>n>>s;
    vl a(n);
    input(a);
    ll sum=0;
    ll r=0;
    ll mini=n;
    while (r<n && sum<s){
        sum+=a[r]; r++;
    }
        mini=min(mini,r);
    if (sum<s){
        cout<<-1;
        return;
    }
    rep(l,0,n){
        sum-=a[l];
        while (r<n && sum<s){
            sum+=a[r];
            r++;
        }
        if (sum>=s) mini=min(mini,r-l-1LL);

    }
    cout<<mini;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}