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
    ll s;
    cin>>n>>s;
    vl a(n);
    input(a);
    ll sum=0;
    int l=0;
    int maxi=0;
    rep(r,0,n){
        sum+=a[r];
        while (sum>s){
            sum-=a[l];
            l++;
        }
        maxi=max(maxi,r-l+1);

    }
    cout<<maxi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}