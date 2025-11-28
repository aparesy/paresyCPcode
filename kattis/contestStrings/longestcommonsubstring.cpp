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

vi kmp(string& s){
    int n=s.length();
    vi pi(n);
    rep(i,1,n){
        int j=pi[i-1];
        while(j>0 && s[j]!=s[i])j=pi[j-1];
        if (s[j]==s[i])j++;
        pi[i]=j;
    }
    return pi;
}

bool patternMatch(string& t, string& s){
    int n=s.length();
    string tmp=s+'#'+t;
    vi pi=kmp(tmp);
    for (auto x : pi) if (x==n) return true;
    return false;
}

void solve(){
    int n=get();
    vector<string> tab(n);
    input(tab);
    int maxSize=0;
    rep(i,0,n){
        maxSize=max(maxSize, (int)tab[i].size());
    }
    int l=0;
    int r=maxSize+1;
    while(r-l>1){
        int m=(r+l)/2;
        bool trouve=false;
        rep(i,0,(int)(tab[0].size())-m+1){
            bool ok=true;
            if (i+m-1>=tab[0].size()) break; string s=tab[0].substr(i,m);
            for (int j=1; ok && j<n; j++){
                if (!patternMatch(tab[j], s))
                    ok=false;
            }
            if (ok) trouve=true;
        }
        if (!trouve) r=m;
        else l=m; 
    }
    cout<<l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}