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
    ll n,l,r,k;
    cin>>n>>k>>l>>r;
    vl tab(n);
    input(tab);
    // First pass : find new elts
    unordered_map<ll,set<int>> htemp; //foreach elem, indicate where it appears 
    set<ll> idxNextNew;
    idxNextNew.insert(n);
    rep(i,0,n){
        if (htemp.find(tab[i])==htemp.end()){
            idxNextNew.insert(i);
        }
        htemp[tab[i]].insert(i);
    }
    ll tot=0;
    ll j=0;
    unordered_map<ll,int> h;
    int hSize=0;
    while(hSize!=k && j<n){ // On ajoute des élts jusqu'a j==n ou on a k éléments
        if (h[tab[j]]==0) hSize++;
        h[tab[j]]++;
        j++;
    }
 //   if (j==n && hSize == k && j<=r && j>=l) tot++;
    if (hSize==k) tot+=max(0LL, min((*idxNextNew.lower_bound(j)),r)-max(j-1,l-1));
    rep(i,0,n){
        h[tab[i]]--;
        if (h[tab[i]]==0){
            hSize--;
            if (htemp[tab[i]].upper_bound(i)!=htemp[tab[i]].end()){
                idxNextNew.insert(*(htemp[tab[i]].upper_bound(i)));
            }
        }
        while(hSize!=k && j<n){
            if (h[tab[j]]==0) hSize++;
            h[tab[j]]++;
            j++;
        }
 //       if (j==n && hSize == k && j-i+1<=r && j-i+1>=l) tot++;
        if (hSize==k) tot+=max(0LL, min((*idxNextNew.lower_bound(j)),r+i+1)-max(j-1,l+i));
    }
    cout<<tot<<"\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=get();
    rep(i,0,t)
    solve();
}