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

void solve(string& s){
    int n=s.length();
    set<string> res;
    rep(i,0,n){
        int j=i+1;
        for (int l=2; i+l/2<n; l+=2){
            if (s[i+1-l/2]!=s[i+l/2]) break;
            else res.insert(s.substr(i+1-l/2,l));
            if (i-l/2<0) break;
        }
        for (int l=3; i+1-l/2>=0 && i+1+l/2<n; l+=2){
            if (s[i+1-l/2]!=s[i+1+l/2]) break;
            else res.insert(s.substr(i+1-l/2,l));
        }
    }
    for (auto x : res)cout<<x<<"\n";
    cout<<"\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while(cin>>s)
    solve(s);
}