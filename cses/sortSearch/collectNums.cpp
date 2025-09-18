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
    set<int> s;
    int tot=0;
    rep(i,0,n){
        if (s.empty() || (s.lower_bound(tab[i])==s.begin() && (*s.lower_bound(tab[i]) > tab[i])) || *(--s.lower_bound(tab[i]))!=tab[i]-1){
            tot++;
            s.insert(tab[i]);
        }
        else{
            s.erase(--s.lower_bound(tab[i]));
            s.insert(tab[i]);
        }
    }
    cout<<tot;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}