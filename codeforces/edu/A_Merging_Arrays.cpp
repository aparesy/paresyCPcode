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
    vl a(n);
    vl b(m);
    input(a);
    input(b);
    ll i=0; ll j=0; ll tot=0;
    while(i<n && j<m){
        while(i<n&&j<m&&a[i]!=b[j]){
            if (a[i]<b[j])i++; else j++;
        }
        ll tmpI=i;ll tmpJ=j;
        while (i<n && a[i]==a[tmpI]) i++;
        while (j<m && b[j]==b[tmpJ]) j++;
        tot+=(tmpI-i)*(tmpJ-j);
    }
    cout<<tot;
//    while(i<n){ cout<<a[i]<<" "; i++;}
 //   while(j<m){ cout<<i<<" "; j++;}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}