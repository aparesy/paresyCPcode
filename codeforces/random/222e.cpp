#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

int charToIndex(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';             // 'a' to 'z' → 0 to 25
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 26;        // 'A' to 'Z' → 26 to 51
    } else {
        return -1;  // Invalid character
    }
}

int main(){
    ll mod = 1e9+7;
    ll n;
    int m, k;
    cin>>n>>m>>k;
    vector<vector<ll>> tot(m, vector<ll>(m));
    vector<vector<ll>> tmp(m, vector<ll>(m));
    vector<vector<ll>> tot2(m, vector<ll>(m));
    for (int i=0;i<m;i++){
        for (int j=0;j<m;j++){
            tot[i][j]=1;
            tot2[i][j]=(i==j); // L'identité, on va lui donner tot puissance n-1
        }
    }
    string s;
    for (int i=0;i<k;i++){
        cin>>s;
        tot[charToIndex(s[0])][charToIndex(s[1])]--;
    }
    for (ll i=0; (1ULL<<i) <= n; i++){
 //       cout << "tot à la puissance " << (1<<i) << " : " << endl << endl;
        if ((1ULL<<i)&(n-1)){
            tmp=tot2;
            // Produit de tot2 avec tot
            for (int j=0;j<m;j++){
                for (int k=0;k<m;k++){
                    tot2[j][k]=0;
                    for (int l=0;l<m;l++){
                        tot2[j][k]+=(tmp[j][l]*tot[l][k])%mod;
                    }
                    tot2[j][k]%=mod;
                }
            }
        }

        // for (int j=0;j<m;j++){
        //     for (int k=0;k<m;k++){
        //         cout << tot[j][k] << " ";
        //     }
        //     cout << endl;
        // }
        // cout<<endl;

        tmp=tot;
        for (int j=0;j<m;j++){
            for (int k=0;k<m;k++){
                tot[j][k]=0;
                for (int l=0;l<m;l++){
                    tot[j][k]+=(tmp[j][l]*tmp[l][k])%mod;
                }
                tot[j][k]%=mod;
            }
        }
        
    }

    ll total=0;
    for (int i=0;i<m;i++){
        for (int j=0;j<m;j++){
            total+=tot2[i][j];
            total%=mod;
        }
    }
    cout << total;
}