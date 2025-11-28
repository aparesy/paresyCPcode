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
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    vi tab(n);
    rep(i,0,n){
        if(s[i]=='a') tab[i]=0;
        else tab[i]=1;
    }

    vi nbA(n+1);
    vi nbB(n+1);
    rep(i,1,n+1){
        nbA[i]=nbA[i-1]+(tab[i-1]==0);
        nbB[i]=i-nbA[i];
    }

    ll tot=0;
    rep(i,0,n){
        ll l=i-1; ll r=n;
        while(r-l>1){
            int m=(r+l)/2;
            if (nbA[m+1]-nbA[i]<a) l=m;
            else r=m;
        }

        ll l2=i-1;
        ll r2=n;
        while(r2-l2>1){
            int m=(r2+l2)/2;
            if (nbB[m+1]-nbB[i]<b) l2=m;
            else r2=m;
        }

        if (r2>=r) tot+=r2-r;
    }
    cout<<tot;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}