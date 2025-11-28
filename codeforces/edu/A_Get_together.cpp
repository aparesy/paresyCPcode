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

double eps=5e-7;
double eps2=1e-8;
void solve(){
    int n=get();
    vector<pair<double,double>> tab(n);
    rep(i,0,n){
        cin>>tab[i].first>>tab[i].second;
    }
    double l=0;
    double r=1e12;
    while(r-l>eps){
        double m=(r+l)/2.;
        vector<pair<double,double>> segments(n);
        rep(i,0,n){
            segments[i].first=tab[i].first-m*tab[i].second;
            segments[i].second=tab[i].first+m*tab[i].second;
        }
        double farthestRight=(*max_element(all(segments))).first;
        double closestLeft=segments[0].second;
        rep(i,0,n){
            closestLeft=min(closestLeft, segments[i].second);
        }
        if (farthestRight-eps2<=closestLeft) r=m;
        else l=m;
    }
    cout<<fixed<<setprecision(6)<<l<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}