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
    double n,k;
    cin>>n>>k;
    double d,s;
    cin>>d>>s;
    if (n==k){
        cout<<"impossible";
    }
    double x=(d*n-s*k)/(n-k);
    if (x<0. || x>100.){
        cout<<"impossible";
    }
    else cout<<fixed<<setprecision(6)<<x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}