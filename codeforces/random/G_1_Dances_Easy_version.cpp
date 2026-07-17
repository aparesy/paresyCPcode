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
    int n,m;
    cin>>n>>m;
    vl a(n-1);
    input(a);
    vl b(n);
    input(b);
    vl c(n);
    rep(i,0,n){
        if (i==0){
            c[i]=1;
        }
        else c[i]=a[i-1];
    }
    sort(all(c));
    sort(all(b));
    int i=0;
    int j=0;
    while (j<n){
        if (c[i]<b[j]){
            i++;j++;
        }
        else{
            j++;
        }
    }
    cout<<j-i<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}