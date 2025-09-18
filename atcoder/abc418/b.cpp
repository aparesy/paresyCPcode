#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
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
    double scoreMax=0.;
    rep(i,0,n){
        rep(j,i+3,n+1){
            int tot=0.;
            rep(k,i,j){
                if (s[k]=='t')tot+=1;
            }
            if (((double)(tot-2))/((double)(j-i-2)) > scoreMax) scoreMax=((double)(tot-2))/((double)(j-i-2));
        }
    }
    cout<<setprecision(14)<<scoreMax;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}