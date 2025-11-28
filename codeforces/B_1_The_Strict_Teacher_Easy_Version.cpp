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
     ll n,m,q;
     cin>>n>>m>>q;
     ll p1,p2,pdavid;
     cin>>p1>>p2>>pdavid;
    if (pdavid < p1 && pdavid < p2){
        cout<<min(p1,p2)-1LL<<"\n";
    }
    else if (pdavid>p1 && pdavid>p2){
        cout<<n-max(p1,p2)<<"\n";
    }
    else{
        cout<<(labs(p1-p2))/2LL<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=get();
    rep(i,0,t)
    solve();
}