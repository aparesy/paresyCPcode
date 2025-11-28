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

void fastApplyPerm(vi& p, ll k){ // compute p^k
    int n=p.size();
    vi res(n);
    iota(all(res),0);
    while(k){
        if (k&1ll){
            vi res2(n); rep(j,0,n) res2[j]=res[j];
            rep(i,0,n){
                res[p[i]]=res2[i];
            }
        }
        vi p2(n);
        rep(j,0,n){p2[j]=p[j];}
        rep(i,0,n){
            p[i]=p2[p2[i]];
        }
        k>>=1ll;
    }
    rep(i,0,n) p[i]=res[i];
}

ll fastExp(ll a, ll b, ll mod){
    ll res=1ll;
    while(b){
        if (b&1ll){
            res*=a;
            if (res>mod) res%=mod;
            if (res==0) res+=mod;
        }
        a*=a;
        if (a>mod) a%=mod;
        if (a==0) a+=mod;
        b>>=1;
    }
    return res;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll cur=fastExp(2ll,k, n);
    ll cur2=cur;
    rep(i,0,n){
        cout<<s[(((i*fastExp(2ll, k, n))%n)+n)%n];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}