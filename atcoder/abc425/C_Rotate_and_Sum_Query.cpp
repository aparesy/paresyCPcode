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
    ll n,q;
    cin>>n>>q;
    vl tab(n);
    input(tab);
    vl cumsum(n+1);
    cumsum[0]=0;
    rep(i,0,n){
        cumsum[i+1]=cumsum[i]+tab[i];
    }
    ll rotate=0;
    rep(i,0,q){
        int x;
        cin>>x;
        if (x==2){
            // query
            ll l,r;
            cin>>l>>r; l--;r--;
            // withou rotate : (r+1) - (l)
            // with rotate : r and l might overflow. We look at their relative positions to  0,n,2n,...
            // We decompose whether r>l or l>r
            r+=rotate;
            l+=rotate;
            l%=n;
            r%=n;
            r+=n;
            r%=n;
            l+=n;
            l%=n;
            if (r>=l){
                cout<<cumsum[r+1LL]-cumsum[l]<<"\n";
            }
            else{
                cout<<cumsum[r+1LL]+cumsum[n]-cumsum[l]<<"\n";
            }
        }
        else{
            ll y;
            cin>>y;
            rotate+=y;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}