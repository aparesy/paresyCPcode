#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define double long double
#define vl vector<ll>
#define rep(i,a,b) for(int i=a;i<b;i++)

double dist(pdd a, pdd b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

void solve(){
    int n;
    cin>>n;
    vector<pair<double,double>> points;
    double x,y;
    rep(i,0,n){
        cin>>x>>y;
        points.push_back({x,y});
    }
    int d; cin>>d;
    double f; cin>>f;
    pdd curStart=points[0];
    pdd curEnd=points[n-1];
    vector<double> longueur(n); double tot=0.; longueur[0]=0.;
    rep(i,1,n){
        longueur[i]=dist(points[i], points[i-1]);
        tot+=longueur[i];
    }
    rep(i,1,n){
        longueur[i]+=longueur[i-1];
    }
    rep(i,1,n){
        longueur[i]/=tot;
    }
    rep(i,1,d){
        int j=0;
        while (j<n){
            if (longueur[j]>f) break;
            j++;
        }
        // Normalement, f<longueur[j] ie f se situe entre les points j-1 et j (car obligatoirement j>=1)
        curStart=points[j];
        curEnd=points[j+1];

        f=(longueur[j]-f)/(longueur[j]-longueur[j-1]);

        points[0]=curStart;
        rep(i,1,n){
            points[i]=points[i-1]
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}