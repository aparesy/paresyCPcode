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
    vi tab(n);
    string st;
    cin>>st;
    rep(i,0,n){
        tab[i]=st[i]-'0';
    }
    vl tot(n);
    tot[0]=tab[0];
    for (int i=1;i<n;i++){
        tot[i]=tab[i]+tot[i-1];
    }
    ll retenue=0;
    vector<char> s(n);
    for (int i=n-1;i>=0;i--){
        ll tmp=retenue+tot[i];
        retenue=tmp/10;
        s[n-1-i]=(tmp%10)+'0';
    }
    bool ok=false;
    if (retenue) cout<<retenue;
    if (retenue) ok=true;
    rep(i,0,n){
        if (s[n-1-i]-'0') ok=true;
        if (ok) cout<<s[n-1-i];
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}