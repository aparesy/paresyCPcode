#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define rep(i,a,b) for(int i=a;i<b;i++)

void solve(){
    ll n,k;
    cin>>n>>k;
    vl s(n);
    vl t(n);
    for (auto& x : s)cin>>x;
    for(auto& x : t) cin>>x;
    rep(i,0,n){
        s[i]=(s[i]%k+k)%k;
        if (s[i]>k/2){
            s[i]=k-s[i];
        }
        t[i]=(t[i]%k+k)%k;
        if (t[i]>k/2){
            t[i]=k-t[i];
        }
    }
    sort(t.begin(), t.end());
    sort(s.begin(),s.end());
    rep(i,0,n){
        if (s[i]!=t[i]){
            cout<<"NO\n"; return;
        }
    }
    cout<<"YES\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}