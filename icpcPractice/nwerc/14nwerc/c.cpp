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

int round(int n){
    if(n%10>=5){
        return n+(((10-n)%10)+10)%10;
    }
    else return n-(n%10);
}

int dp[22][2001];

void solve(){
    int n,d;
    cin>>n>>d;
    vi tab(n);
    vi cumsum(n+1);
    cumsum[0]=0;
    input(tab);
    rep(i,0,n){
        cumsum[i+1]=cumsum[i]+tab[i];
    }
    rep(i,0,n+1){
        if (i==0){
            dp[0][0]=0;
        }
        else{
            dp[0][i]=round(cumsum[i]);
        }
    }
    rep(i,1,d+2){
        rep(j,0,n+1){
            dp[i][j]=INT32_MAX-1000;
            rep(k,0,j){
                dp[i][j]=min(dp[i][j], dp[i-1][k]+round(cumsum[j]-cumsum[k]));
            }
        }
    }
    cout<<dp[d+1][n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}