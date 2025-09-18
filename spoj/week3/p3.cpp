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
#define vvd vector<vector<double>>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x

double f(int x, int nb, double k, int& dec){
    int taille = x/nb;
    int nbGrand=x%nb;
    int nbPetit=nb-nbGrand;
    dec = nbPetit;
    return ((double)(taille+1)*(double)(taille+1)*(double)nbGrand)*k + ((double)(taille)*(double)(taille)*(double)nbPetit)*k;
}

void solve(){
    // n pelouses équidistantes sur la diag : /n
    double k1,k2;
    cin>>k1>>k2;
    int m,n;
    cin>>m>>n;
    // On compte les petits et les grands
    int nbGrands = n%m;
    int nbPetits = m-(n%m);
    int taillePetit=n/m;

    int dec;
    double miniGlob=DBL_MAX;
    if (!nbGrands){
        dec=0;
            double haut=0.;
            double bas=0.;

            bas+=f(100,taillePetit*nbPetits, k2,dec);
            
            vector<int> tailleBloc(nbPetits);
            rep(i,0,taillePetit*nbPetits){
                if (i<dec){
                    tailleBloc[i%nbPetits]+=100/(nbPetits*taillePetit);
                }
                else{
                    tailleBloc[i%nbPetits]+=100/(nbPetits*taillePetit)+1;
                }
            }
            rep(i,0,nbPetits){
                haut+=(double)tailleBloc[i]*(double)tailleBloc[i]*k1;
            }
            miniGlob=min(miniGlob, haut+bas);
        cout<<fixed<<setprecision(3)<<miniGlob;
        return;
    }
    rep(t,0,101){
        if (t>=nbPetits*taillePetit && 100-t>=nbGrands*(taillePetit+1)){
            dec=0;
            double haut=0.;
            double bas=0.;

            bas+=f(t,taillePetit*nbPetits, k2,dec);
            
            vector<int> tailleBloc(nbPetits);
            rep(i,0,taillePetit*nbPetits){
                if (i<dec){
                    tailleBloc[i%nbPetits]+=t/(nbPetits*taillePetit);
                }
                else{
                    tailleBloc[i%nbPetits]+=t/(nbPetits*taillePetit)+1;
                }
            }
            rep(i,0,nbPetits){
                haut+=(double)tailleBloc[i]*(double)tailleBloc[i]*k1;
            }
            dec=0;
            bas+=f(100-t, (taillePetit+1)*nbGrands, k2, dec);

            vector<int> tailleBloc2(nbGrands);
            rep(i,0,(taillePetit+1)*nbGrands){
                if (i<dec){
                    tailleBloc2[i%nbGrands]+=(100-t)/(nbGrands*(taillePetit+1));
                }
                else{
                    tailleBloc2[i%nbGrands]+=(100-t)/(nbGrands*(taillePetit+1))+1;
                }
            }
            rep(i,0,nbGrands){
                haut+=(double)tailleBloc2[i]*(double)tailleBloc2[i]*k1;
            }

            miniGlob=min(miniGlob, haut+bas);
        }
    }
    cout<<fixed<<setprecision(3)<<miniGlob;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}