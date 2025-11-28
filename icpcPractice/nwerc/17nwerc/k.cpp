// Useful functions : nth_element, rotate, unique, merge, count, generate

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
using ll=long long;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x
#define all(x) x.begin(),x.end()

ll get(){
   ll x;
   cin>>x;
   return x;
}

void solve(){
    int n;
    cin>>n;
    vl tab(n);
    input(tab);
    while (tab.size()<4096){
        tab.push_back(0);
    }
    int dane=tab[0];
    tab.erase(tab.begin());
    sort(all(tab));
    tab.push_back(dane);
    // Most probably a greedy, though constraints point at a more complex algo ?
    // Probably, you want the strongest other player to have a maximal chance to be defeated, and so on for the second strongest. Conversely, you want 
    // the weakest to fight dane in first round .... The correct fight tree is just sorted trivially with dane at the end
    // What's the proba for win ? For each balaced branch, each guy's win prob is easy 
    vector<vector<double>> proba(12,vector<double>());
    for (int i=0;i<12;i++){
        for (int pos=0;pos<4096;pos++){
            //proba[tour][pos]=proba[tour-1][pos]*(somme des victoires face aux adversaires possibles).
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}