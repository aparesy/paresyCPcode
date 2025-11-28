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

bool isZer(string& s){
    rep(i,0,s.length()){
        if (s[i]=='1') return false;
    }
    return true;
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    string t;
    cin>>t;
    if (isZer(s) && !isZer(t)){
        cout<<"NO\n";
        return;
    }
    int i=0;
    while(i<n && s[i]=='0'){
        if (t[i]=='1'){
            cout<<"NO\n";
            return;
        }
        i++;
    }
    cout<<"YES\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}