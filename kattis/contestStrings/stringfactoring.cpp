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

int kmpFactor(string s){
    int n=s.length();
    vi pi(n);
    pi[0]=0;
    rep(i,1,n){
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j]) j=pi[j-1];
        if (s[i]==s[j])j++;
        pi[i]=j;
    }
    if (n%(n-pi[n-1])){
        return n;
    }
    else return n-pi[n-1];
}

void solve(){
    string s;
    cin>>s;
    int n=s.length();
    vvi dp(n,vi(n));
    rep(l,1,n+1){
        rep(i,0,n-l+1){
            int j=i+l-1;
            int longueurFact=kmpFactor(s.substr(i,l));
            if (longueurFact==l){
                dp[i][j]=l;
            }
            else dp[i][j]=dp[i][i+longueurFact-1];
            rep(k,i,j){
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]);
            }
        }
    }
    cout<<dp[0][n-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}