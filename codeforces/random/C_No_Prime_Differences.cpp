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
    int n,m;
    cin>>n>>m;
    if (m==1){
        rep(j,0,n){
            cout<<j+1<<"\n";
        }
        cout<<endl;
    }
    else if (m==2){
        ;
    }
    else if (m%2==0){
        rep(i,0,n){
            rep(j,0,m){
                cout<<i*m+j+1<<" ";
            }
            cout<<"\n";
        }
        cout<<endl;
    }
    else if (n%2==0){
        rep(i,0,m){
            rep(j,0,n){
                cout<<i*n+j+1<<" ";
            }
            cout<<"\n";
        }
        cout<<endl;
    }
    else{
        vvi grid(n,vi(m))
        int i=0;
        while (i+3<m){
            
        }
        cout<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}