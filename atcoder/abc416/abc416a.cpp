#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main(){
  ll n,l,r;
  cin>>n>>l>>r;
  string s;
  cin>>s;
  bool ok=true;
  for (int i=l-1;i<=r-1;i++){
    if (s[i]=='x'){
        ok=false;
    }
  }
  if (ok) cout<<"Yes"; else cout<<"No";
}