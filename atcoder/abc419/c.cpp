#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define rep(i,a,b) for(int i=a;i<b;i++)

// int farthest(int ind, vector<pair<ll,ll>> points){
//     int indMax=0;
//     int distMax=0LL;
//     int n=points.size();
//     rep(i,0,n){
//         if (abs(points[ind].first-points[i].first)+abs(points[ind].second-points[i].second) > distMax){
//             indMax=i;
//             distMax=abs(points[ind].first-points[i].first)+abs(points[ind].second-points[i].second);
//         }
//     }
//     return indMax;
// }

void solve(){
    int n;
    cin>>n;
    vector<pair<ll,ll>> points(n);
    rep(i,0,n){
        ll x,y; cin>>x>>y;
        points[i]={x,y};
    }
    ll xmax=0LL; ll ymax=0LL; ll xmin=points[0].first; ll ymin=points[0].second;
    rep(i,0,n){
        if (points[i].first > xmax) xmax=points[i].first;
        if (points[i].first < xmin) xmin=points[i].first;
        if (points[i].second > ymax) ymax=points[i].second;
        if (points[i].second < ymin) ymin=points[i].second;
    }
    cout<<(max(xmax-xmin, ymax-ymin)+1LL)/2LL;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}