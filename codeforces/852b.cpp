#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

// Nombre de chemins qui arrivent en un type i avec un poids p : 
// Pour l=2 1 si i=p, 0 sinon
// Pour l=3 : nombre de chemins avec un poids (p-i) (sommme des chemins de poids p-i)

int main(){
    ll n;
    int l,m;
    cin>>n>>l>>m;
    ll mod = 10e9+7;
    vector<int> start(n);
    vector<int> path(n);    
    vector<int> end(n);
    for (auto& x : start) cin>>x;
    for (auto& x : path) cin>>x;
    for (auto& x : end) cin>>x;

    int beg[m];
    for (int i=0;i<m;i++){
        beg[i]=0;
    }
    for (auto x : start) beg[x%m]++;

    int fin[m];
    for (int i=0;i<m;i++){
        fin[i]=0;
    }
    for (auto x : end) fin[x%m]++;

    ll bouts[m]; //Nombre de bouts (deb+fin) dont la somme congrue à i
    for (int i=0;i<m;i++){
        bouts[i]=0;
    }
    for (int i=0;i<m;i++){
        for (int j=0;j<m;j++){
            bouts[(i+j)%m] += (beg[i]*fin[j]) % mod ;
        }
    }

    int tmp[m];
    for (int i=0;i<m;i++){
        tmp[i]=0;
    }
    for (auto x : path) tmp[x%m]++;

    ll chemin[(ll)(log2(l))+2][m][m];
    for (int i=0;i<m;i++){
        for (int j=0;j<m;j++){
            chemin[0][i][j] = tmp[j];
        }
    }

    for (int i=1; (1<<i) <= l ; i++){
        for (int j=0;j<m;j++){
            for (int k=0;k<m;k++){
                chemin[i][j][k]=0;
                for (int l=0;l<m;l++){
                    chemin[i][j][k] += chemin[i-1][j][l]*chemin[i-1][l][k]%mod;
                }
            }
        }
    }

    // On print pour voir ce qui se passe

    for (int i=0; (1<<i) <= l ; i++){
        cout << "Matrice à la puissance " << (1<<i) << " : " << endl << endl;
        for (int j=0;j<m;j++){
            for (int k=0;k<m;k++){
                cout << chemin[i][j][k];
                cout << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    ll cur[n][m];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cur[i][j]=0;
        }
    }

    ll cheminTot[m][m];
    for (int i=0;i<m;i++){
        for (int j=0;j<m;j++){
            cheminTot[i][j]=beg[(j-i+m)%m];
        }
    }

    for (int i=0;i<n;i++){
        cur[i][start[i]%m]++;
    }

    for (int i=0;(1<<i) <= l;i++){
        if ((1<<i)&l){
            for (int j=0;j<m;j++){
                for (int k=0;k<m;k++){
                    for (int l=0;l<m;l++){
                        cheminTot[j][k]+=chemin[i][j][l]*chemin[i][l][k]%mod;
                    }
                }
            }
        }
    }

    ll mat[m][m];
    ll mat2[m][m];
    for (int i=0;i<m;i++){
        for (int j=0;j<m;j++){
            mat2[i][j]=((i==j)?tmp[i]:0);
        }
    }

    ll tot=0;
    for (int i=0;i<n;i++){
        tot+=cheminTot[0][end[(m-i)%m]]%mod;
    }
    cout<<tot;
}