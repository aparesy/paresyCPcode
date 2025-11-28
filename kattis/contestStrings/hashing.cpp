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
    int q=get();
    vi hashes(n+1);
    ll curHash=0;
    rep(i,0,n){
        curHash+=s[i];
        curHash%=mod;
        curHash*=p1;
        curHash%=mod;
        hashes[i+1]=curHash;
    }   
    rep(i,0,q){
        int l,r;
        cin>>l>>r;
        ll tmp=hashes[r];
        int dist=r-l;
        ll tmp2=hashes[l]*fastExp(p1,dist);
        tmp2%=mod;
        tmp-=tmp2;
        tmp%=mod;
        tmp+=mod;
        tmp%=mod;
        cout<<tmp<<"\n";
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    solve(s);
}