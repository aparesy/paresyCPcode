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
    ll n,q,m;
    cin>>n>>q>>m;
    vvi tab(n,vi(n));
    rep(i,0,m){
        int a,b,c,d;
        ll x;
        cin>>a>>b>>c>>d; a--;b--;c--;d--; //NE PAS OUBLIER DE TRANSLATER LES REQUETES
        rep(j,a,c+1){
            rep(j2,b,d+1){
                cin>>x;
                tab[j][j2]+=x;
            }
        }
    }

    int tmp=log2(n)+1;
    ll segtr2d[tmp][n][n];
    rep(i,0,n){
        rep(j,0,n){
            segtr2d[0][i][j]=tab[i][j];
        }
    }
    rep(k,1,tmp){
        for (int i=0;i+(1LL<<(k-1))<n;i++){
            for (int j=0;j+(1<<(k-1))<n;j++){
                segtr2d[k][i][j]=max(max(segtr2d[k-1][i][j],segtr2d[k-1][i+(1<<(k-1))][j]),max(segtr2d[k-1][i][j+(1<<(k-1))],segtr2d[k-1][i+(1<<(k-1))][j+(1<<(k-1))]));
            }
        }
    }

    rep(temporaire,0,q){
        int i,j,s;
        cin>>i>>j>>s;
        i--;j--;
        int taille=log2(s);
        int taille2=(1<<taille);
        cout<<max(max(segtr2d[taille][i][j],segtr2d[taille][i+s-taille2][j]),max(segtr2d[taille][i][j+s-taille2],segtr2d[taille][i+s-taille2][j+s-taille2]))<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}