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
      int i=0;
      int j=n-1;
      bool up=true;
      while (i<=j){
        if (tab[i]<tab[j]){
            cout<<(up?"R":"L");
            if (up) j--; else i++;
            up=!up;
        }
        else{
            cout<<(up?"L":"R");
            if (up) i++; else j--;
            up=!up;
        }
      }
      cout<<endl;
   }
}