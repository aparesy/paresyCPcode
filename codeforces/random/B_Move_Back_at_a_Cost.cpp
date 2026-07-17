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

ll inf=99999999999ll;

ll get(){
   ll x;
   cin>>x;
   return x;
}

void solve(){
    int n=get();
    vl tab(n);
    input(tab);
    vl suffMin(n+1);
    suffMin[n]=99999999999ll;
    for (int i=n-1;i>=0;i--){
        suffMin[i]=min(tab[i],suffMin[i+1]);
    }
    vi s;
    ll minPushed=99999999999ll;
    rep(i,0,n){
        if (tab[i]==suffMin[i] && tab[i]<=minPushed){
            s.push_back(tab[i]);
        }
        else{
            s.push_back(tab[i]+1);
            minPushed=min(minPushed,tab[i]+1ll);
        }
    }
    sort (all(s));
    for (auto x : s) cout<<x<<" ";
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}