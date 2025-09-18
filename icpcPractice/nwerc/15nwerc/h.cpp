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
    int n;
    cin>>n;
    int x,y; cin>>x>>y;
    vector<pair<pii,pii>> walls(n);
    rep(i,0,n){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        walls[i]={make_pair(a,b),make_pair(c,d)};
    }
    vi order(n);
    rep(i,0,n){
        order[i]=i;
    }
    int maxi=-1;
    do{
        if (possible(ordre, walls, x, y)){
            
        }
    }
    while(next_permutation(order.begin(),order.end()));
    if (maxi==-1)cout<<"impossible";
    else cout<<maxi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}