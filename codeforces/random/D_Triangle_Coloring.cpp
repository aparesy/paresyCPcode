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

ll fastExp(ll a, ll b, ll mod){
    ll res=1;
    while (b){
        if (b&1){
            res*=a;
            res%=mod;
        }
        a*=a;
        a%=mod;
        b>>=1;
    }
    return res;
}

void solve(){
    int n=get();
    vl tab(n);
    ll tot=1;
    ll mod=998244353ll;
    for (int i=0;i<n;i+=3){
        vi tmp(3);
        cin>>tmp[0]>>tmp[1]>>tmp[2];
        sort(all(tmp));
        if (tmp[0]==tmp[1]){
            if (tmp[1]==tmp[2]){
                tot*=3ll;
            }
            else tot*=2ll;
        }
        tot%=mod;
    }

    // now choose n/6 out of n/3

    rep(i,n/6+1,n/3+1){
        tot*=((ll)i);
        tot%=mod;
    }

    ll tmpFact=1;
    rep(i,2,n/6+1){
        tmpFact*=((ll)i);
        tmpFact%=mod;
    }

    tot*=fastExp(tmpFact, mod-2ll, mod);

    tot%=mod;
    cout<<tot;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}