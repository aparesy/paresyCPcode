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
      ll tot=n;
      for (int i=0;i<n-1;i++){
        tot+=i+1;
        if (tab[i]>tab[i+1]){
            tot+=(i+1)*(n-i-1);
        }
      }
      cout<<tot<<endl;
   }
}