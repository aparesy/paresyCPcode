#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)

void solve(){
    int t;
    cin>>t;
    vl tab(t);
    for (auto& x : tab)cin>>x;
    rep(a,0LL,10001LL){
        rep(b,0LL,10001LL){
            ll x=tab[0];
            rep(i,1LL,t){
                x=(a*a*x+a*b+b)%10001; if(x<0) x+=10001LL;
                if (x!=tab[i]) break;
                if (i==t-1){
  //                  cout<<a<<" "<<b<<endl;
                    x=(a*tab[0]+b)%10001; if(x<0) x+=10001LL;
                    rep(j,0,t){
                        cout<<x<<endl;
                        x=(a*a*x+a*b+b)%10001; if (x<0)x+=10001LL;
                    }
                    return;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}