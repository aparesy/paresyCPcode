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
    string s,t;
    cin>>s>>t;
    ll mod=1e9+7ll;
    ll p=41ll;
    ll hashOriginal=0;
    int n=s.length();
    rep(i,0,n){
        hashOriginal+=t[i];
        hashOriginal%=mod;
        hashOriginal*=p;
        hashOriginal%=mod;
    }
    vl pArray(n+1);
    pArray[0]=1;
    rep(i,1,n+1){
        pArray[i]=pArray[i-1]*p;
        pArray[i]%=mod;
    }
    ll hashS=0;
    rep(i,0,n){
        hashS+=s[i];
        hashS%=mod;
        hashS*=p;
        hashS%=mod;
    }
    rep(i,0,n){
        if (hashS==hashOriginal){
            cout<<i<<"\n";
            return;
        }
        ll tmp=pArray[n]*s[i];
        tmp%=mod;
        hashS-=tmp;
        hashS%=mod;
        hashS+=mod;
        hashS%=mod;
        hashS+=s[i];
        hashS%=mod;
        hashS*=p;
        hashS%=mod;
    }
    cout<<-1<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}