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

set<ll> allNb;
set<ll> allProd;

void bt(int n, int nb){
    allNb.insert(n);
    if (nb!=5){
        bt(10*n,nb+1);
        bt(10*n+1,nb+1);
    }

}

// void computeProd(){
//     for (auto x : allNb){
//         for (auto y : allNb){
//             allProd.insert(x*y);
//         }
//     }
// }

void solve(){
    int n;
    cin>>n;
    bool trouve;
    while(n>1){
        trouve=false;
        for (auto it=allNb.rbegin(); it!=allNb.rend() ; it++){
            int x=(*(it));
            if ((n%x) == 0 && x>1){
                n/=x;
                trouve=true;
                break;
            }
        }
        if (!trouve){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    bt(1,0);
   // computeProd();
    int t; cin>>t; rep(i,0,t)
    solve();
}