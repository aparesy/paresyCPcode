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
    int n=get();
    vl tab(n);
    input(tab);
    if (accumulate(all(tab),0ll)%2){
        cout<<-1<<"\n";
        return;
    }
    vii res;

    vvi dp(2,vi(n));
    dp[0][0]=tab[0];
    dp[1][0]=tab[0];
    bool ok=false;
    rep(i,1,n){
        dp[0][i]=dp[1][i-1]+tab[i];
        if (ok){
            dp[1][i]=dp[0][i];
            ok=false;
            continue;
        }
        if (abs(dp[1][i-1]+tab[i])<=abs(dp[0][i-1]-tab[i])){
            dp[1][i]=dp[0][i];
            res.push_back({i-1,i-1});
        }
        else{
            dp[1][i]=dp[0][i-1]-tab[i];
            res.push_back({i-1,i});
            ok=true;
        }
    }

    if (!ok){
        res.push_back({n-1,n-1});
    }

    cout<<res.size()<<"\n";
    for (auto [x,y] : res){
        cout<<x+1<<" "<<y+1<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}