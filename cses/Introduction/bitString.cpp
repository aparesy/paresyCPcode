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
#define rep(i,a,b) for(int i=a;i<b;i++)

void solve(){
    int n;
    cin>>n;
    ll mod=1e9+7LL;
    ll cur=1;
    ll puissance=2;
    while(n){
        if (n&1LL){
            cur*=puissance;
            cur%=mod;
        }
        puissance*=puissance;
        puissance%=mod;
        n>>=1LL;
    }
    cout<<cur;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}