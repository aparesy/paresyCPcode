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
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x
#define all(x) x.begin(),x.end()

ll get(){
   ll x;
   cin>>x;
   return x;
}

void solve(){
    ll n,h;
    cin>>n>>h;
    vl tab(n);
    input(tab);
    sort(all(tab));
    int maxi=0;
    int i=0;
    ll curScore=h;

        while(curScore>tab[i] && i<n){
            curScore+=tab[i]/2ll;
            i++;
        }
        curScore*=2ll;
        while(curScore>tab[i] && i<n){
            curScore+=tab[i]/2ll;
            i++;
        }
        curScore*=2ll;
        while(curScore>tab[i] && i<n){
            curScore+=tab[i]/2ll;
            i++;
        }
        curScore*=3ll;
        while(curScore>tab[i] && i<n){
            curScore+=tab[i]/2ll;
            i++;
        }
        maxi=i;
    

    i=0;
    curScore=h;

        while(curScore>tab[i] && i<n){
            curScore+=tab[i]/2ll;
            i++;
        }
        curScore*=2ll;
        while(curScore>tab[i] && i<n){
            curScore+=tab[i]/2ll;
            i++;
        }
        curScore*=3ll;
        while(curScore>tab[i] && i<n){
            curScore+=tab[i]/2ll;
            i++;
        }
        curScore*=2ll;
        while(curScore>tab[i] && i<n){
            curScore+=tab[i]/2ll;
            i++;
        }
        maxi=max(i,maxi);

        i=0;
    curScore=h;

        while(curScore>tab[i] && i<n){
            curScore+=tab[i]/2ll;
            i++;
        }
        curScore*=3ll;
        while(curScore>tab[i] && i<n){
            curScore+=tab[i]/2ll;
            i++;
        }
        curScore*=2ll;
        while(curScore>tab[i] && i<n){
            curScore+=tab[i]/2ll;
            i++;
        }
        curScore*=2ll;
        while(curScore>tab[i] && i<n){
            curScore+=tab[i]/2ll;
            i++;
        }
        maxi=max(i,maxi);

    cout<<maxi<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}