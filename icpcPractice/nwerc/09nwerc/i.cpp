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

double dist(pdd p1, pdd p2){
    return hypot(p2.first-p1.first, p2.second-p1.second);
}

double pente(pdd p1, pdd p2){
    return atan2(p2.second - p1.second, p2.first - p1.first);
}

void solve(){
    int n;
    cin>>n;
    vector<pdd> points;
    double x,y;
    rep(i,0,n){
        cin>>x>>y;
        points.push_back({x,y});
    }
    int ref = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].second < points[ref].second ||
        (points[i].second == points[ref].second && points[i].first < points[ref].first)){
            ref = i;
        }
    }
    swap(points[0], points[ref]);
    vector<tuple<double,double,int>> newPoints; // Direction et distance relative à 0
    rep(i,1,n){
        newPoints.push_back(make_tuple(pente(points[0], points[i]), dist(points[0], points[i]), i));
    }
    sort(newPoints.begin(), newPoints.end());
    cout<<ref<<" ";
    rep(i,0,n-1) cout<<(get<2>(newPoints[i])==ref?0:get<2>(newPoints[i]))<<" ";
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}