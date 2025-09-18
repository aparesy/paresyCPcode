#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define rep(i,a,b) for(int i=a;i<b;i++)

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> t;
    rep(i,0,n){
        t.push_back(s[i]=='0'?1:0);
    }
    vector<int> cumsum(n+1);
    cumsum[0]=0;
    ll nbImpair=0;
    rep(i,1,n+1){
        cumsum[i]=cumsum[i-1]+t[i-1];
        if (cumsum[i]&1) nbImpair++;
    }
    cout << nbImpair*(nbImpair-1LL)/2LL + (n+1LL-nbImpair)*(n-nbImpair)/2LL;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}