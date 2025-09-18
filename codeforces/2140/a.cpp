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
    string s;
    int n;
    cin>>n;
    cin>>s;
    int nbZ = 0;
    rep(i,0,n){
        if (s[i]=='0') nbZ++;
    }
    int tot1=0;
    int tot2=0;
    for (int i=0;i<n;i++){
        if (i<nbZ && s[i]=='1') tot1++;
        if (i>=nbZ && s[i]=='0') tot2++;
    }
    cout<<min(tot1,tot2)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}