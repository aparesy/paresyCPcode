#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x

int ctb(ll n){
    int tot=0;
    while(n){
        if (n&1) return tot;
        tot++;
        n>>=1;
    }
    return tot;
}

void solve(){
    int q;
    cin>>q;
    rep(i,0,q){
        ll n,k;
        cin>>n>>k;
        ll tot=0LL;
        while (!(k&1)){
            tot+=n/2LL;
            n>>=1LL;
            k>>=1LL;
        }
        cout<<tot+(k/2LL)<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}