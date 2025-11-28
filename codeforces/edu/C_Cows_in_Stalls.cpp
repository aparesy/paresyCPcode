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
    int n=get();
    int k=get();
    vl tab(n);
    input(tab);
    ll l=0;
    ll r=1e15;
    while(r-l>1){
        int k2=k;
        ll m=(r+l)/2ll;
        k2--;
        ll curDist=0;
        rep(i,1,n){
            curDist+=tab[i]-tab[i-1];
            if (curDist>=m){
                curDist=0;
                k2--;
            }
        }
        if (k2<=0){
            l=m;
        }
        else r=m;
    }
    cout<<l<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}