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
    vi start(n);
    vi end(n);
    rep(i,0,n){
        cin>>start[i]>>end[i];
    }
    vii startWithId(n);
    rep(i,0,n){
        startWithId[i]={start[i],i};
    }
    sort(startWithId.begin(), startWithId.end());
    priority_queue<pii, vector<pii>, greater<pii>> q;
    int tot=0;
    vi affect(n);
    rep(i,0,n){
        auto [tmp, id] = startWithId[i];
        if (q.empty() || q.top().first >= tmp){
            tot++;
            affect[id] = tot;
            q.push({end[id], id});
        }
        else{
            affect[id] = affect[q.top().second];
            q.pop();
            q.push({end[id],id});
        }
    }
    cout<<tot;
    cout<<"\n";
    rep(i,0,n) cout<<affect[i]<<" ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}