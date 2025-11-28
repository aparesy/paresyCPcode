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
    int n,k;
    cin>>n>>k;
    vector<double> tab(n);
    input(tab);
    double l=0.;
    double r=1000000000.;
    double eps=1e-7;
    while (r-l>eps){
        double mid=r/2.+l/2.;
        int tot=0;
        rep(i,0,n){
            tot+=(int)tab[i]/mid;
        }
        if (tot<k)r=mid;
        else l=mid;
    }
    cout<<l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}