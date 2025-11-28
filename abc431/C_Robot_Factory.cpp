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
    int n,m,k;
    cin>>n>>m>>k;
    vi h(n);
    input(h);
    vi b(m);
    input(b);
    sort(all(h));
    sort(all(b));
    int tot=0;
    int i=0;
    int j=0;
    while(i<n){
        while(j<m && b[j]<h[i]) j++;
        if (j<m){tot++; j++;}
        i++;
    }
    // for (auto x : h) cout<<x<<" ";
    // cout<<"\n";

    // for (auto x : b) cout<<x<<" ";
    // cout<<"\n";
    // cout<<tot<<"\n";    
    if (tot>=k){
        cout<<"Yes\n";
    }
    else cout<<"No\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}