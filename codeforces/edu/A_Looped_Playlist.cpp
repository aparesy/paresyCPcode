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
    ll n;
    cin>>n;
    ll p;
    cin>>p;
    vl tab(n);
    input(tab);
    ll sum=accumulate(tab.begin(),tab.end(),0LL);
    ll miniNb=n;
    int miniI=0;
    ll target=p%sum;
    int r=0;
    rep(i,0,n){
        while (target>0){
            target-=tab[r];
            r++;
            if (r==n) r=0;
        }
        if ((r-i+n)%n<miniNb){ miniNb=(r-i+n)%n; miniI=i;}
        target+=tab[i];
    }
    cout<<miniI+1<<" "<<miniNb+n*(p/sum);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}