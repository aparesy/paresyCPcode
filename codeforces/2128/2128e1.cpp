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
      ll k;
      cin>>k;
      vl tab(n);
      for (auto& x : tab) cin>>x;
      vl tabTrie = tab;
      sort(tabTrie.begin(), tabTrie.end());
      int l=0;
      int r=n;
      while (l<r){
        int mid=(l+r)/2;
        int medChoisi=tabTrie[mid]; //On choisit une médiane; Si c'est bien une ksubmed, on monte sinon on descend
        vl gainL(n+1);
        vl gainR(n+1);
        for (int i=1;i<=n;i++){
            gainL[i]=gainL[i-1]+(medChoisi<=tab[i-1]?-1:1); // Gain en enlevant i éléments à gauche/droite
            gainR[i]=gainR[i-1]+(medChoisi<=tab[n-i]?-1:1);
        }
        int start=0;
        for (auto x : tab) start+=(medChoisi<=x?1:-1);
      }
   }    
}