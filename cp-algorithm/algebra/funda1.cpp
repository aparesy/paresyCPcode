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
      ll x,y,n;
      cin>>x>>y>>n;
      ll tmp=x;
      x=1;
      while (y){
        if (y&1){
            x=x*tmp%n;
        }
        tmp=tmp*tmp%n;
        y>>=1;
      }    
      cout << x<<endl;
   }
   cin>>t;
}