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

void solve(){
    ll n,x;
    cin>>n>>x;
    vl tab(n);
    input(tab);
    vl opt(x+1);
    opt[0]=0;
    rep(i,1,x+1){
        opt[i]=INT64_MAX-1LL;
        for (auto c : tab){
            if (i-c>=0 && opt[i-c]+1LL<opt[i]){
                opt[i]=opt[i-c]+1LL;
            }
        }
    }
    if (opt[x]==INT64_MAX-1LL){
        cout<<-1;
    }
    else cout<<opt[x];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}