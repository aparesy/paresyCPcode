#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    ll mod=1e9+7ULL;
    if (m>n){
        cout << 1 << endl;
    }
    else{
        // vector<ll> cur(m,0);
        // for (int i=0;i<m;i++){
        //     cur[i]=1;
        // }
        vector<vector<ll>> mat(m, vector<ll>(m,0));
        for (int i=0;i<m-1;i++){
            mat[i][i+1]=1ULL;
        }
        mat[m-1][m-1]=1ULL;
        mat[m-1][0]=1ULL;

        vector<vector<ll>> mat2(m, vector<ll>(m,0));
        for (int i=0;i<m;i++){
            mat2[i][i]=1ULL;
        }

        while (n){
            if (n&1){
                prod_mat(mat2, mat,m,mod);
            }
            prod_mat(mat,mat,m,mod);
            n>>=1;
        }

        // cout << "matrice : " <<endl;
        // for (int i=0;i<m;i++){
        //     for (int j=0;j<m;j++){
        //         cout << mat2[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        ll res=0ULL;
        for (int i=0;i<m;i++){
            res+=mat2[0][i];
        }
        cout << res%mod << endl;
    }
}