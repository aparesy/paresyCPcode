#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

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

ll exp_mod(ll x, ll y, ll mod){
    ll tmp=1;
    while (y){
        if (y&1){
            tmp=tmp*x%mod;
        }
        x=x*x%mod;
        y>>=1;
    }
    return tmp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;
    ll mod=10000007;
    cin>>n>>k;
    while (n!=0 && k!=0){
        cout << ((2LL*exp_mod(n-1,k,mod)+exp_mod(n,k,mod)+exp_mod(n,n,mod)+2LL*exp_mod(n-1,n-1,mod))%mod) << endl;
        cin>>n>>k;
    }
}