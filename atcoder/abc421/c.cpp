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
    int n;
    cin>>n;
    string s;
    cin>>s;
    vl ordre;
    vl longueur;
    ll compte=0;
    ll longueurCur=0;
    char curChar=s[0];
    ll tot=0;  
    rep(i,0,2*n){
        longueurCur++;
        if (s[i]==curChar) compte++;
        if (s[i]!=curChar) tot+=2*compte-longueurCur;
        if ((i%2)==1 && longueurCur/2==compte && (i+1<2*n && s[i+1]!=curChar)){
            longueur.push_back(longueurCur);
            ordre.push_back(tot);
            tot=0;
            longueurCur=0;
            compte=0;
            curChar=s[i+1];
        }
    }
    longueur.push_back(longueurCur);
    ordre.push_back(tot);

    ll tot1=0;
    ll tot2=0;
    rep(i,0,longueur.size()){
        if (i%2){
            tot1+=ordre[i];
            tot2+=ordre[i]+longueur[i]/2;
        }
        else{
            tot1+=ordre[i]+longueur[i]/2;
            tot2+=ordre[i];
        }
    }
    cout<<min(tot1,tot2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}