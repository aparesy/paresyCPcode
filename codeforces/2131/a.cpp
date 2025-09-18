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
    int n;
    cin>>n;
    vi a(n);
    vi b(n);
    for (auto& x : a)cin>>x;
    for (auto& x : b)cin>>x;
    int tot=1;
    rep(i,0,n){
        if (a[i]>b[i]) tot+=a[i]-b[i];
    }
    cout<<tot<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}