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
      ll c;
      cin>>c;
      vl tab(n);
      for (auto& x : tab) cin>>x;
      sort(tab.begin(),tab.end());
      ll cost=1LL;
      int i=0;
      ll tot=0;
      while (tab[i]<=c && i<n){
        i++;
      }
      i--;
      if (tab[i]>c){
        i--;
      }
      while(i>=0){
        tot++;
        cost*=2LL;
        i--;
        while(i>=0 && cost*tab[i]>c){
            i--;
        }
      }
      cout << n-tot << endl;
   }
}