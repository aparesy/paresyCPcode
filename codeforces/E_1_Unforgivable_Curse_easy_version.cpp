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

bool solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    string s;
    cin>>s;
    string t;
    cin>>t;
    if (n==1){
        return (s[0]==t[0]);
    }
    if (n==2){
        if ((s[0]==t[0] && s[1]==t[1]) ){
            return true;
        }
        return false;
    }
    if (n==3){
        if (s[1]!=t[1]) return false;
        if (s[0]==t[0] && s[2]==t[2]) return true;
        return false;
    }
    if (n==4){
        if (s[1]!=t[1] || s[2] != t[2]) return false;
        if (s[0]==t[0] && s[3]==t[3]) return true;
        if (s[3] == t[0] && s[0]==t[3]) return true;
        return false;
    }
    if (n==5){
        if (s[2]!=t[2]) return false;
    }
    vi count(26);
    rep(i,0,n){
        count[s[i]-'a']++;
        count[t[i]-'a']--;
    }
    rep(i,0,26){
        if (count[i]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    if (solve()) cout<<"YES\n"; else cout<<"NO\n";
}