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
    string s;
    cin>>s;
    if (s=="red") cout<<"SSS";
    else if (s=="blue") cout<<"FFF";
    else if (s=="green")cout<<"MMM";
    else cout<<"Unknown";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}