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
    ll tot=1;
    unordered_map<string, bool> h;
    sort(s.begin(),s.end());
    h[s]=true;
    while(next_permutation(s.begin(),s.end())){
        if (!h[s]){
            tot++;
        h[s]=true;
        }
    }
    cout<<tot<<"\n";
    h.clear();
    sort(s.begin(),s.end());
    h[s]=true;
    cout<<s<<"\n";
    while(next_permutation(s.begin(),s.end())){
        if (!h[s]){
            cout<<s<<"\n";
            h[s]=true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}