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

const int NMAX=10000001;

ll tab[NMAX];

ll fact[NMAX];
ll mod=998244353ll;

ll fastInv(ll a){
    return a <= 1 ? a : mod - (long long)(mod/a) * fastInv(mod % a) % mod;
}

void solve(){
    ll n=get();
    ll d=get();
    fact[0]=1;
    rep(i,1,NMAX){
        fact[i]=fact[i-1]*i;
        fact[i]%=mod;
    }
    rep(i,0,n){
        cin>>tab[i];
    }
    sort(tab, tab+n);
    ll tot=1;
    rep(i,1,n){
        ll l=-1;
        ll r=i;
        while(r-l>1){
            ll m = (r+l)/2;
            if(tab[m]>=tab[i]-d){
                r=m;
            }
            else l=m;
        }
        tot*=(i-r+1ll);
        tot%=mod;
    }
    map<ll,int> occ;
    rep(i,0,n){
        occ[tab[i]]++;
    }
    for (auto [x,y] : occ){
        if (y>1){
            tot*=fastInv(fact[y]);
            tot%=mod;
        }
    }
    cout<<tot<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}