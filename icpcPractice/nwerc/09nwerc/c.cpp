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
    ll d,n;
    cin>>d>>n;
    vl count(d,0LL);
    count[0]++;
    ll cur=0LL;
    ll tmp;
    rep(i,0,n){
        cin>>tmp;
        cur+=tmp;
        cur%=d;
        count[cur]++;
    }
    ll tot=0LL;
    rep(i,0,d){
        tot+=count[i]*(count[i]-1LL)/2LL;
    }
    cout<<tot<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}