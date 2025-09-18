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
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll scoreJan; ll scorePetra; scoreJan=scorePetra=0;
    vii values(n);
    rep(i,0,n){
        int a,b;
        cin>>a>>b;
        values[i]={a,b};
    }
    sort(values.begin(), values.end(), [](auto& p1, auto& p2){if (p1.first==p2.first) return p1.second>p2.second; return p1.first>p2.first;});
    if (s!="Petra"){
        n++;
        values.insert(values.begin(), {0,0});
    }
    vector<bool> prisJan(n);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    rep(i,0,n){
        pq.push({values[i].second, i});
    }
    rep(i,n/2,n){
        if (values[i].second>=pq.top().first){
            pq.pop();
            pq.push({values[i].second, i});
        }
    }

    
    while (!pq.empty()){
        prisJan[pq.top().second]=true;
        pq.pop();
    }

    rep(i,0,n){
        if (prisJan[i]){
            scoreJan+=values[i].second;
        }
        else scorePetra+=values[i].first;
    }
    cout<<scorePetra<<" "<<scoreJan<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}