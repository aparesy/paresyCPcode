// Useful functions : nth_element, rotate, unique, merge, count, generate

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
using ll=long long;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x
#define all(x) x.begin(),x.end()

ll get(){
   ll x;
   cin>>x;
   return x;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vl tab(m);
    input(tab);
    // Find all pairs such that ai+bj>=n
    sort(all(tab));
    ll tot=0ll;
    for (int nbGauche=1;nbGauche<=n/2;nbGauche++){
        // Compte les couleurs qui ont nbGauche au moins
        ll lGauche=-1;
        ll rGauche=m;
        while (rGauche-lGauche>1){
            int mid=(lGauche+rGauche)/2;
            if (tab[mid]<nbGauche){
                lGauche=mid;
            }
            else rGauche=mid;
        } // rGauche est l'indice minimal correct, le nombre est par csq m-rGauche
        ll rDroit=m;
        ll lDroit=-1;
        while(rDroit-lDroit>1){
            int mid=(rDroit+lDroit)/2;
            if (tab[mid]<n-nbGauche){
                lDroit=mid;
            }
            else rDroit=mid;
        }
        if (((n%2)==0)&&nbGauche==n/2) tot+=(m-rGauche)*(m-rGauche-1ll);
        else tot+=((m-rGauche)*(m-rDroit)-(m-rDroit))*2ll;
    }
    cout<<tot<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}