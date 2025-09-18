#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main(){
  string s;
  cin>>s;
  bool ok=true;
  for (int i=0;i<s.length();i++){
    if (s[i]=='.' && ok){
        s[i]='o';
        ok=false;
    }
    else if (s[i]=='#'){
        ok=true;
    }
  }
  cout<<s;
}