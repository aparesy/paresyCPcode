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
    ll x=0,y=0;
    rep(i,0,s.length()){
        x*=2LL;
        y*=2LL;
        switch(s[i]){
            case '1' : x++; break;
            case '2' : y++; break;
            case '3' : x++;y++; break;
        };

    }
    cout<<s.size()<<" "<<x<<" "<<y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}