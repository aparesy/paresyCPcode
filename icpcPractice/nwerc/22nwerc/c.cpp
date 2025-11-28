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
    ll s=get();
    double l=0.;
    double r=3e5;
    double eps=1e-8;

    while(r-l>eps){
        double m=(r+l)/2.;
        double y=1.;
        ll tot=0.;
        double x=sqrt(m*m-y*y);
        double prevx=m;
        while(y<=m+eps){
            tot+=(ll)min(x,prevx);
            prevx=x;
            y+=1.;
            x=sqrt(m*m-y*y);
        }
        if (4ll*tot > s){
            r=m;
        }
        else l=m;
    }
    cout<<fixed<<setprecision(8)<<l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}