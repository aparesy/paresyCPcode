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

// int sumDigit(int n){
//     if (n<10){
//         return n;
//     }
//     return (n%10)+(sumDigit(n/10));
// }

void decDigit(int n, vi& tab){
    if (n<10){
        tab.push_back(n);
        return;
    }
    decDigit(n/10,tab);
    tab.push_back(n%10);
}

void solve(){
    int n;
    cin>>n;
    ll tot=1;
    vi tab;
    decDigit(n,tab);
    for (auto x :tab){
        tot*=(((ll)(x+1))*((ll)(x+1))+((ll(x+1))))/2ll;
    }
    cout<<tot<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}