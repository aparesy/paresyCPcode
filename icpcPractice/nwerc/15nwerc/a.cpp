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
    int n,m;
    cin>>n>>m;
    vii startId(n);
    vii endId(n);
    rep(i,0,n){
        int a,b;
        cin>>a>>b;
        startId[i]={a,i};
        endId[i]={a+b,i};
    }
    int tot=0;
 //   sort(endId.begin(), endId.end());
    sort(startId.begin(),startId.end());
    // int j=n-1;
    // vb taken(n);
    // for (int i=n-1;i>=0;i--){
    //     while (j>=0 && startId[j].first>endId[i].first+m && taken[startId[j].second]){
    //         j--;
    //     }
    //     if (j>=0 && startId[j].first>=endId[i].first){
    //         tot++;
    //         taken[startId[j].second]=true;
    //     }
    // }
    // cout<<tot;

    priority_queue<int, vi, greater<int>> q;
    rep(i,0,n){
        while (!q.empty() && q.top()+m<startId[i].first) q.pop();
        if (!q.empty() && q.top()<=startId[i].first){
            q.pop();
            tot++;
        }
        q.push(endId[startId[i].second].first);
    }
    cout<<tot;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}