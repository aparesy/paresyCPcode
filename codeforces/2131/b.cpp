#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define rep(i,a,b) for(int i=a;i<b;i++)

void solve(){
    int n;
    cin>>n;
    if (n==2){
        cout<<"-1 2"<<endl;
        return;
    }
    else{
        cout<<"-1 3 ";
        for (int i=2;i<n;i++){
            if (i%2 && i==n-1) cout<<"2 ";
            else if (i%2) cout <<"3 ";
            else cout<<"-1 ";
        }
        cout<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);int t;
    cin>>t;
    rep(i,0,t)
    solve();
}