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
    int s=sqrt(n)+1;
    vl sparseTable(s);
    rep(i,0,s){
        sparseTable[i]=INT_MAX;
        rep(j,i*s, (i+1)*s){
            if (j<n) sparseTable[i]=min(sparseTable[i], tab[j]);
        }
    }
    int q;
    cin>>q;
    rep(i,0,q){
        int l,r;
        cin>>l>>r;
        ll mini=INT_MAX;
        rep(i,0,s){
            // Do we take the block ?
            if (i*s >= l && (i+1)*s-1<=r) mini=min(mini,sparseTable[i]);
        }
        int ind=l;
        while(ind<n && (ind%s)!=0 && ind<=r){
            mini=min(mini,tab[ind]);
            ind++;
        }
        ind=r;
        while (ind>=0 && (ind%s)!=s-1 && ind>=l){
            mini=min(mini,tab[ind]);
            ind--;
        }
        cout<<mini<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); int t=get();
    rep(i,0,t)
    solve();
}   