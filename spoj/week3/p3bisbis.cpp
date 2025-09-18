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
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x

void solve(){
    double k1,k2;
    cin>>k1>>k2;
    int m,n;
    cin>>m>>n;
    // On compte les petits et les grands
    int nbGrands = n%m;
    int nbPetits = m-(n%m);
    int taillePetit=n/m;

    if (!nbGrands){
        int taille=100/nbPetits;
        int surplus = 100%nbPetits;
        int taille2 = 100/n;
        int surplus2 = 100%n;
        cout<<fixed<<setprecision(3)
        <<((double)(taille*taille))*k1*((double)(nbPetits-surplus))+((double)((taille+1)*(taille+1))*k1*((double)(surplus)))+
            ((double)(taille2*taille2))*k2*((double)(n-surplus2))+((double)((taille2+1)*(taille2+1))*k2*((double)(surplus2)));
        return;
    }
    double minGlob=DBL_MAX;
    rep(t,1,100){
        double tmp=0.;
        int taille=t/nbPetits;
        int surplus = t%nbPetits;
        int taille2 = t/(nbPetits*(taillePetit));
        int surplus2 = t%(nbPetits*(taillePetit));
        tmp+=((double)(taille*taille))*k1*((double)(nbPetits-surplus))+((double)((taille+1)*(taille+1))*k1*((double)(surplus)))+
            ((double)(taille2*taille2))*k2*((double)(nbPetits*(taillePetit)-surplus2))+((double)((taille2+1)*(taille2+1))*k2*((double)(surplus2)));
        taille=(100-t)/nbGrands;
        surplus = (100-t)%nbGrands;
        taille2 = (100-t)/(nbGrands*(taillePetit+1));
        surplus2 = (100-t)%(nbGrands*(taillePetit+1));
        tmp+=((double)(taille*taille))*k1*((double)(nbGrands-surplus))+((double)((taille+1)*(taille+1))*k1*((double)(surplus)))+
            ((double)(taille2*taille2))*k2*((double)(nbGrands*(taillePetit+1)-surplus2))+((double)((taille2+1)*(taille2+1))*k2*((double)(surplus2)));
        minGlob=min(minGlob,tmp);
    }
    cout<<fixed<<setprecision(3)<<minGlob;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}