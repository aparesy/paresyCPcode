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
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x

void solve(){
    string s;
    getline(cin,s);
    int n=s.length();
    string tab;
    cin>>tab;
    int k;
    cin>>k;
    unordered_map<string,int> ok;
    int tot=0;
    int count=0;
    string cur;
    rep(i,0,n){
        cur="";
        count=0;
        rep(j,i,n){
            cur.append(1u,s[j]);
            if (!(tab[s[j]-'a']-'0')){
                count++;
            }
            if (count<=k && ok.find(cur)==ok.end()){
                tot++;
                ok[cur]=1;
            }
        }
    }
    cout<<tot;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}