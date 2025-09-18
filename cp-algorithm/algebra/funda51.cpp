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

void prod_mat(vector<vector<ll>>& mat2, vector<vector<ll>> mat, ll m, ll mod){
    auto tmp = mat2;
    for (int i=0;i<m;i++){
        for (int j=0;j<m;j++){
            mat2[i][j]=0;
            for (int k=0;k<m;k++){
                mat2[i][j]+=(tmp[i][k]*mat[k][j]%mod);
            }
            mat2[i][j]%=mod;
        }
    }
}

ll fibo(ll n, ll mod){
    ll n1=n;
    vvl matFib(2,vl(2));
    vvl matCur(2,vl(2));
    matFib[1][1]=0LL;
    matFib[0][1]=matFib[0][0]=matFib[1][0]=1LL;
    matCur[0][0]=matCur[1][1]=1LL;
    matCur[0][1]=matCur[1][0]=0LL;
    while(n1){
        if(n1&1){
            prod_mat(matCur, matFib, 2, mod);
        }
        prod_mat(matFib, matFib, 2, mod);
        n1>>=1;
    }
    if (n==0)return 0LL;
    return matCur[0][1];
}

void solve(){
    ll mod=1000000007LL;
    ll n;
    cin>>n;
    if (n==0)cout<<0<<endl;
    else if (n==1)cout<<2<<endl;
    else cout<<(fibo(n+1LL,mod)+fibo(n+2LL,mod))%mod<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}