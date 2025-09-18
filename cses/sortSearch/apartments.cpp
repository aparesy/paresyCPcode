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
    int n,m,k;
    cin>>n>>m>>k;
    vl a(n);
    input(a);
    vl b(m);
    input(b);
    sort(b.begin(),b.end());
    int tot=0;
    sort(a.begin(),a.end());
    int i=0;
    rep(j,0,m){
        while(i<n && a[i]<b[j]-k)i++;
        if (i<n && a[i]<=b[j]+k){
            tot++;
            i++;
        }
    }
    cout<<tot;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}