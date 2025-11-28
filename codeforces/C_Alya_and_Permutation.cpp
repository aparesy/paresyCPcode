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
    int n;
    cin>>n;
    if (n%2){
        cout<<n<<'\n';
        rep(i,2,n-1){
            cout<<i<<" ";
        }
        cout<<1<<" ";
        cout<<n-1<<" "<<n<<"\n";
    }
    else{
        int full=(1<<((int)log2(n)+1))-1;
        cout<<full<<'\n';
        if (full-1!=n){
            rep(i,full-n+1,n) cout<<i<<" ";
            rep(i,2,full-n-1){
                cout<<i<<" ";
            }
            cout<<1<<" ";
            cout<<full-n-1<<" "<<full-n<<" "<<n<<"\n";
        }
        else{
            rep(i,2,n){
                cout<<i<<" ";
            }
            cout<<1<<" "<<n<<"\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}