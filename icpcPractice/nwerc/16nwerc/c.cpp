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
    int x,y;
    cin>>x>>y;
    bool minus=false;
    if (x<0){
        x=-x;
        minus=true;
    }
    int n;
    cin>>n;
    double distVert=0.;
    distVert+=y;
    rep(i,0,n){
        int up,down;
        double speed;
        cin>>down>>up>>speed;
        distVert-=(up-down);
        distVert+=speed*((double)(up-down));
    }
    cout<<fixed<<setprecision(7)<<x/distVert;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}