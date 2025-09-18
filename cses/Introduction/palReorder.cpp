#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define rep(i,a,b) for(int i=a;i<b;i++)

void solve(){
    string s;
    cin>>s;
    int tab[26];
    rep(i,0,26) tab[i]=0;
    rep(i,0,s.length()){
        tab[s[i]-'A']++;
    }
    int imp=0;
    int impTot=0;
    rep(i,0,26){
        if (tab[i]%2){
            if (impTot){
                cout<<"NO SOLUTION"; return;
            }
            impTot++;
            imp=i;
        }
    }
    for (int i=0;i<26;i++){
        if (!(tab[i]%2)) rep(j,0,tab[i]/2) cout<<(char)(i+'A');
    }
    if (impTot) rep(j,0,tab[imp]) cout<<(char)(imp+'A');
    for (int i=25;i>=0;i--){
        if (!(tab[i]%2)) rep(j,0,tab[i]/2) cout<<(char)(i+'A');
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}