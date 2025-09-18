#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define rep(i,a,b) for(int i=a;i<b;i++)

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if (n>=3&&s[n-3]=='t'&&s[n-2]=='e'&&s[n-1]=='a')  cout<<"Yes"; else cout<<"No";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}