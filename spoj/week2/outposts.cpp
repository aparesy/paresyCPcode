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

vi parent;
vi rang;

void make_set(int v) {
    parent[v] = v;
    rang[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rang[a] < rang[b])
            swap(a, b);
        parent[b] = a;
        if (rang[a] == rang[b])
            rang[a]++;
    }
}



void solve(){
    int s,p;
    cin>>s>>p;
    vector<pii> points(p);
    priority_queue<pair<double,pii>, vector<pair<double,pii>>, greater<pair<double,pii>>> q;

    parent.resize(p);
    rang.resize(p);
    rep(i,0,p)
    make_set(i);

    rep(i,0,p){
        int a,b;
        cin>>a>>b;
        points[i]={a,b};
        rep(j,0,i)
        q.push({hypot(points[i].first-points[j].first,points[i].second-points[j].second), {j,i}});
    }
    int tot_taken=0;
    pii lastTaken={0,0};
    do{
        auto [dist, paire] = q.top();
        auto [i,j]=paire;
        q.pop();
//        cout<<find_set(i)<<" "<<find_set(j)<<"\n";
        if (find_set(i)!=find_set(j)){
            union_sets(i,j);
            lastTaken={i,j};
            tot_taken++;
            //cout<<i<<j<<"\n";
        }
    }
    while(tot_taken<p-s);
    cout<<fixed<<setprecision(2)<<hypot(points[lastTaken.first].first-points[lastTaken.second].first, points[lastTaken.first].second-points[lastTaken.second].second)<<endl;
    return;
    while(!q.empty()){
        auto [dist, paire] = q.top();
        auto [i,j]=paire;
        q.pop();
        if (find_set(i)!=find_set(j)){
            cout<<dist<<"\n";
            return;
        }
    }
    cout<<0<<"\n";  
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}