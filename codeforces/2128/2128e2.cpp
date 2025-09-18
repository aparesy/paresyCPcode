#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int median(vector<int>& tab, int l, int r){

}

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
      int l=0;
      int r=k;
      int bestMed=0;
      bool encore=true;
      while (encore && r<n){
        encore=false;
        int nouveauR=r+1;
        int nouveauMed=tab[r];
        set<int> leftTab;
        set<int> rightTab;
        leftTab.insert(tab[r]);
        while (nouveauR < n && nouveauMed < bestMed){
            if (*leftTab.rbegin() >= tab[nouveauR]){
                leftTab.insert(tab[nouveauR]);
            }
            else{
                rightTab.insert(tab[nouveauR]);
            }
            if (leftTab.size() >= rightTab.size()+2){
                rightTab.insert(*leftTab.rbegin());
                leftTab.erase(std::prev(leftTab.end()));
            }
            if (rightTab.size() >= leftTab.size()+2){
                leftTab.insert(*rightTab.begin());
                rightTab.erase(std::prev(rightTab.begin()));
            }
            nouveauR++;
            nouveauMed=*rightTab.begin();
        }
        if (nouveauMed>=bestMed){
            encore=true;
            r=nouveauR+1;
            bestMed=median(tab,l,r);
        }
        if (encore){
            int nouveauL=l+1;
            int nouveauMed
        }
      }
      
   }
}