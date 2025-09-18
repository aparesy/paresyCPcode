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
    vl a(n);
    vl b(n);
    for (auto& x : a) cin>>x;
    for (auto& x : b) cin>>x;
    int lasti=-1;
    for (int i=0;i<n-1;i++){
        if ((a[i]^a[i+1])==b[i]){
            // cout<<i<<endl;
            // for (auto x : a) cout<<x<<" ";
            // cout<<endl;
            int j=i;
            while (j>lasti&&((a[j]^a[j+1])==b[j])){
                a[j]=(a[j]^a[j+1]);
                j--;
            }
            lasti=i;
        }
    }
    rep(i,0,n){
        if (a[i]!=b[i]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}
