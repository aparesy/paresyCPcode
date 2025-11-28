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
    ll n,q;
    cin>>n>>q;
    ll totCol=0;
    ll totRows=0;
    vb col(n,true);
    vb row(n,true);
    int nbRows=0;
    int nbCols=0;
    rep(i,0,q){
        string s;
        cin>>s;
        int x;
        cin>>x; x--;
        if (s[0]=='R'){
            if (row[x]){
                row[x]=false;
                cout<<n*(n+1ll)/2ll  - totCol + (n-nbCols)*(x+1ll)<<"\n";
                totRows+=x+1;
                nbRows++;
            }
            else{
                cout<<0<<"\n";
            }
        }
        else{
            if (col[x]){
                col[x]=false;
                cout<<n*(n+1ll)/2ll  - totRows + (n-nbRows)*(x+1ll)<<"\n";
                totCol+=x+1;
                nbCols++;
            }   
            else{
                cout<<0<<"\n";
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("adjustment.in", "r", stdin);
    freopen("adjustment.out", "w", stdout);
    solve();
}   