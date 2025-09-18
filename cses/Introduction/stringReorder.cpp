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
    cin>>s;
    vi count(26);
    int n=s.length();
    rep(i,0,n){
        count[s[i]-'A']++;
        if (count[s[i]-'A']>(n+1)/2){
            cout<<-1;
            return;
        }
    }
    int j=0;
    int last=-1;
    rep(i,0,n){
        auto maxi=max_element(count.begin(),count.end());
        if (*maxi==(n-i+2)/2){
           // cout<<"ok";
            (*maxi)--;
            cout<<(char)(maxi-count.begin()+'A');
            last=maxi-count.begin();
            continue;
        }
        while (count[j]==0 || j==last) j++;
        cout<<(char)(j+'A');
        count[j]--;
        last=j;
        j=0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}