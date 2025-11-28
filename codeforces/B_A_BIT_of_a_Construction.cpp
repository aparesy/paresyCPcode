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
    ll n,k;
    cin>>n>>k;
    //Somme de n termes qui valent k. Cas simple : k=1<<j-1. Alors k 0 0  0 0 suffit.
    // Qund estce qu'on peut activer tous les bits ?
    //trivial
    ll j=0;
    if (n==1){
        cout<<k<<"\n";
    }
    else if (n>1){
        while(k>=(1LL<<j)-1LL) j++;
        j--;
        cout<<(1LL<<j)-1LL<<" ";
        cout<<k-(1LL<<j)+1LL<<" ";
        rep(i,0,n-2){
            cout<<0<<" ";
        }
        cout<<"\n";
    }
    else{
        cout<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=get();
    rep(i,0,t)
    solve();
}