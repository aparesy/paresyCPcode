#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main(){
  ll n,k,x;
  cin>>n>>k>>x;
  x-=1;
  vector<string> v(n);
  for (auto& y : v) cin>>y;
  sort(v.begin(), v.end());
  string str="";
  for (int i=0;i<k;i++){
    int tmp=x%n;
    str=v[tmp]+str;
    x-=tmp;
    x=x/n;
  }
  cout<<str;
}