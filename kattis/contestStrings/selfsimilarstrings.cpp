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

ll mod=1e9+7ll;
ll p1=47ll;

ll fastExp(ll a, ll b){
    ll res=1;
    while(b){
        if (b&1){
            res*=a;
            res%=mod;
        }
        a*=a;
        a%=mod;
        b>>=1ll;
    }
    return res;
}

void solve(string& s){
    int n=s.length();
    int l=0;
    int r=n;
    while(r-l>1){
        int m=(r+l)/2;
        map<ll,int> hashes;
        ll curHash=0;
        rep(i,0,m){
            curHash+=s[i];
            curHash%=mod;
            curHash*=p1;
            curHash%=mod;
        }
        hashes[curHash]++;
        rep(i,1,n-m+1){
            ll tmp=s[i-1];
            tmp*=fastExp(p1, m);
            tmp%=mod;
            curHash-=tmp;
            curHash%=mod;
            curHash+=mod;
            curHash%=mod;
            curHash+=s[i+m-1];
            curHash%=mod;
            curHash*=p1;
            curHash%=mod;
            hashes[curHash]++;
        }
        bool ok=true;
        for (auto [u,v] : hashes){
            if (v==1) ok=false;
        }
        if (!ok) r=m;
        else l=m;
    }
    cout<<l<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while(cin>>s)
    solve(s);
}