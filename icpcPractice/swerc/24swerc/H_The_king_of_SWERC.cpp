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
    string s;
    string maxs;
    unordered_map<string,int> h;
    int maxi=0;
    rep(i,0,n){
        cin>>s;
        h[s]++;
        if (h[s]>maxi){
            maxi=h[s];
            maxs=s;
        }
    }
    cout<<maxs;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}