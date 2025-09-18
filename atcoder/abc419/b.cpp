#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define rep(i,a,b) for(int i=a;i<b;i++)

void solve(){
    int q;
    cin>>q;
    priority_queue<int, vi, greater<int>> pq;
    rep(i,0,q){
        int n;
        cin>>n;
        if (n==1){
            int x;
            cin>>x;
            pq.push(x);
        }
        else{
            int x=pq.top();
            pq.pop();
            cout<<x<<"\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}