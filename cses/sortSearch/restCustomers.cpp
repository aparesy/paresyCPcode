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
    int n;
    cin>>n;
    vl a(n);
    vl b(n);
    rep(i,0,n){
        cin>>a[i]>>b[i];
    }
    int i1=0;
    int i2=0;
    int tot=0;
    int maxi=0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    while (i1<n && i2<n){
        if (a[i1]<b[i2]){
            tot++;
            i1++;
            if (tot>maxi)maxi=tot;
        }
        else{
            tot--;
            i2++;
        }
    }
    cout<<maxi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}