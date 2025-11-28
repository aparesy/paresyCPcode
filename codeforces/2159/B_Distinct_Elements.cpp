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
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x
#define all(x) x.begin(),x.end()

ll get(){
   ll x;
   cin>>x;
   return x;
}

void solve(){
    int n;
    cin>>n;
    vl tab(n);
    input(tab);
    vl gaps(n);
    gaps[0]=1;
    rep(i,0,n-1){
        gaps[i+1]=tab[i+1]-tab[i];
    }
    vl res(n);
    res[0]=1;
    vl maxi(n);
    maxi[0]=1;
    rep(i,1,n){
        ll ind=i-gaps[i];
        if (ind==-1ll){
            res[i]=maxi[i-1]+1ll;
        }
        else{
            res[i]=res[ind];
        }
        maxi[i]=max(maxi[i-1],res[i]);
    }
    rep(i,0,n){
        cout<<res[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}