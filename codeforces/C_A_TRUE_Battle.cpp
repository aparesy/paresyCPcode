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
    // The goal is to make sure at least one cc is only ones
    int n=get();
    string s;
    cin>>s;
    if (s[0]=='1' || s[n-1]=='1'){
        cout<<"YES\n";
        return;
    }
    rep(i,0,n-1){
        if (s[i]=='1' && s[i+1]=='1'){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}