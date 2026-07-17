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
    ll n;
    cin>>n;
    if (n<=9 || n%10ll==9){
        cout<<"NO\n";
        return;
    }
    n/=10;
    int lastDigit=0;
    while(n){
        lastDigit=n%10ll;
        if (lastDigit==0){
            cout<<"NO\n";
            return;
        }
        n/=10ll;
    }
    if (lastDigit==1){
        cout<<"YES\n";
        return;
    }
    else cout<<"NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}