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
    ll n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    vii intervals(m);
    rep(i,0,m){
        int l,r;
        cin>>l>>r;
        intervals[i]={l-1,r};
    }
    vector<int> changer(n+1,0);
    rep(i,0,m){
        changer[intervals[i].first] = (1^(changer[intervals[i].first]));
        changer[intervals[i].second] =(1^(changer[intervals[i].second]));
    }
    int cur=0;
    rep(i,0,n){
        cur^=changer[i];
        if (cur) cout<<t[i];
        else cout<<s[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}