#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define rep(i,a,b) for(int i=a;i<b;i++)

void solve(){
    string s;
    cin>>s;
    int n=s.length();
    vector<vector<int>> bestScore(n+1, vector<int>(n,0));
    rep(i,1,n+1){
        rep(j,0,n){
            int mini=INT_MAX;
            rep(k,max(0,j-26),min(n,j+27)){
                if (abs(j-k)+bestScore[i-1][k]+dist(s[j],s[k])<mini){
                    mini=abs(j-k)+bestScore[i-1][k]+dist(s[j],s[k]);
                }
            }
            rep(k,min(n,j-26+n),n){
                if (abs(j-k)+bestScore[i-1][k]+dist(s[j],s[k])<mini){
                    mini=abs(j-k)+bestScore[i-1][k]+dist(s[j],s[k]);
                }
            }
            bestScore[i][j]=mini;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}