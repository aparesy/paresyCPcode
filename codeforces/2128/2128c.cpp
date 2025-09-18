#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int t;
   cin>>t;
   while(t--){
      ll n;
      cin>>n;
      vl tab(n);
      for (auto& x : tab) cin>>x;
      int mini=tab[0];
      bool ok=true;
      for (int i=1;i<n;i++){
        if (tab[i]>2*mini-1) ok=false;
        if (tab[i] < mini) mini=tab[i];
      }
      if (ok){
        cout<<"YES\n";
      }
      else cout<<"NO\n";
   }
}