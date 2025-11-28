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
    ll a,b;
    cin>>a>>b;
    if ((ll)log2(b)>(ll)log2(a)){
        cout<<-1<<"\n";
        return;
    }
    else{
        vl ops;
        for (ll i=0;(1ll<<i)<=a;i++){
            if(((a>>i) ^ (b>>i))&1ll){
                ops.push_back(1ll<<i);
            }
        }
        cout<<ops.size()<<"\n";
        for (auto x : ops){
            cout<<x<<" ";
        }
        if (ops.size())cout<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}