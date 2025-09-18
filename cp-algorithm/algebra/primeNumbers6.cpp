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
#define rep(i,a,b) for(int i=a;i<b;i++)

void solve(){
    int n;
    cin>>n;
    if (n<=2){
        cout<<1<<endl;
        if (n==1){
            cout<<1;
            return;
        }
        cout<<1<<" "<<1;
        return;
    }
    vector<int> prime(n+2,1);
    for(int i=2;i*i<n+2;i++){
        if(prime[i]==1){
            for (int j=i*i;j<n+2;j+=i){
                prime[j]=2;
            }
        }
    }
    cout<<2<<endl;
    for (int i=2;i<n+2;i++){
        cout<<prime[i]<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}