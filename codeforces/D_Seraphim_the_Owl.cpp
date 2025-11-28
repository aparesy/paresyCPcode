// Useful functions : nth_element, rotate, unique, merge, count, generate

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
using ll=long long;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x
#define all(x) x.begin(),x.end()

ll get(){
   ll x;
   cin>>x;
   return x;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vl a(n);
    input(a);
    vl b(n);
    input(b);
    // It is not always best to switch directly. Best way to reach pos i ?
    // Is it possible to land on a bad tile while greeddy ?No
    int pos=n;
    ll tot=0LL;
    for (int i=n-1;i>=m;i--){
        tot+=min(a[i],b[i]);
    }
    ll mini=a[m-1];
    ll cur=a[m-1];
    for (int i=m-2;i>=0;i--){
        cur+=a[i]+b[i+1];
        cur-=a[i+1];
        mini=min(mini,cur);
    }
    cout<<tot+mini<<"\n";
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=get();
    rep(i,0,t)
    solve();
}