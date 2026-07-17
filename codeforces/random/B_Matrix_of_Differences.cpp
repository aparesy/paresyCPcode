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
    int n;cin>>n;
    int cur=1;
    vi stock(n);
    int taille=1;
    stock[0]=cur;
    int aaa=0;
    for (int i=n*n-1;i>0;i--){
        if ((n*n-1-i)%2){
            cur-=i;
        }
        else cur+=i;
        stock[taille]=cur;
        taille++;
        if (taille==n){
            if (aaa){
                for (int j=n-1;j>=0;j--) cout<<stock[j]<<" ";
            }
            else rep(j,0,n) cout<<stock[j]<<" ";
            taille=0;
            aaa=1-aaa;
            cout<<"\n";
        }
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