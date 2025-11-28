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
    int n;
    cin>>n;
    vl tab(n);
    vl t(n);
    input(tab);
    input(t);
    bool ok=true;
    rep(i,0,n){
        if (tab[i]!=t[i]) ok=false;
    }
    if (ok) cout<<"Bob\n";
    if (!ok){
        ok=true;
        rep(i,0,n){
            if (tab[i]!=t[n-1-i]){
                ok=false;
            }
        }
        if (ok) cout<<"Bob\n"; else cout<<"Alice\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}