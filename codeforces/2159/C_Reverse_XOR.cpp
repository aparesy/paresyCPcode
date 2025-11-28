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
    ll n;
    cin>>n;
    vi tab;
    while(n){
        tab.push_back(n&1);
        n>>=1;
    }
    while (tab.size()>=2 && *(tab.begin())==0 && (*(tab.end()-1))==0){
        tab.erase(tab.begin());
        tab.erase(tab.end()-1);
    }
    while (tab.size() && *(tab.begin())==0){
        tab.erase(tab.begin());
    }
    int s=tab.size();
//    rep(i,0,s) cout<<tab[i]<<" ";
    rep(i,0,s){
        if (tab[i]!=tab[s-1-i] || (i==s-i-1 && tab[i]==1)){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}