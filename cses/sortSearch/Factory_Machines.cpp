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
    ll n,t;
    cin>>n>>t;
    vl tab(n);
    input(tab);
    // T tasks for the machines. It's a binary search : if you cannot complete the task, increase the time
    ll l=0;
    ll r=1e18+1LL;
    while(r-l>1LL){
        ll m=l+(r-l)/2ll;
        ll tot=0LL;
        for (auto x : tab){
            if (tot<t) tot+=m/x;
            else break;
        }
        if (tot<t){
            l=m;
        }
        else r=m;
    }
    cout<<r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}