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


bool orient(pii& a, pii& b, pii& c){
    // Renvoie vrai si l'angle entre ba et bc est négatif
    return (a.first-b.first)*(c.first-b.first)+(a.second-b.second)*(c.second-b.second)<0;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<int,pii>> ptInner(n);
    rep(i,0,n){
        int a,b;
        cin>>a>>b;
        ptInner[i] = {i,make_pair(a,b)};
    }
    int m;
    cin>>m;
    vii ptOuter(m);
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        ptOuter[i] = {a,b};
    }
    // Construction de l'enveloppe convexe :
    vector<pair<int,pii>> cvHullInner;
    rep(i,0,n){
        cvHullInner.push_back(ptInner[i]);
        while (cvHullInner.size()>=2 && orient(cvHullInner[i].second, cvHullInner[i-1].second, cvHullInner[i-2].second)){
            cvHullInner.pop_back();
            cvHullInner.pop_back();
            cvHullInner.push_back(ptInner[i]);
        }
    }
    while (cvHullInner.size()>=2 && orient(cvHullInner[0].second,cvHullInner.back().second, cvHullInner[cvHullInner.size()-2].second)){
        cvHullInner.pop_back();
    }
    while (cvHullInner.size()>=2 && orient(cvHullInner[1].second,cvHullInner[0].second, cvHullInner.back().second)){
        cvHullInner.erase(cvHullInner.begin());
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}