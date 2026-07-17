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
    int n=get();
    vi count(n);
    rep(i,0,n){
        int x=get();
        count[x]++;
    }
    if (count[0]==0){
        cout<<"0\n"; return;
    }
    bool ok=false;
    rep(i,0,n){
        if (count[i]==1){
            if (ok){
                cout<<i<<"\n";
                return;
            }
            else ok=true;
        }
        if (count[i]==0){
            cout<<i<<"\n";
            return;
        }
    }
    cout<<n<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}