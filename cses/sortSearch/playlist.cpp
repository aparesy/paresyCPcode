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
    int n;
    cin>>n;
    vl tab(n);
    input(tab);
    int maxi=1;
    int cur=1;
    int i=1;
    set<ll> s;
    s.insert(tab[0]);
    while(i<n){
        if (tab[i]!=tab[i-1] && s.find(tab[i])==s.end()){
            cur++;
            i++;
            s.insert(tab[i-1]);
        }
        else{
            if (cur>maxi) maxi=cur;
            cur=1;
            i++;
            s.clear();
            s.insert(tab[i-1]);
        }
    }
    if (cur>maxi) maxi=cur;
    cout<<maxi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}