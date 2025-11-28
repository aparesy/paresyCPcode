// Useful functions : nth_element, rotate, unique, merge, count, generate

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
using ll=long long;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x
#define all(x) x.begin(),x.end()

ll get(){
   ll x;
   cin>>x;
   return x;
}

int dist[(int)6e5];
int n;
vector<int> adj[(int)6e5];

int farthest(int s){
    fill(dist, dist + n + 1, -1);

    queue<int> q;
    q.push(s);
     vb vu(n+1);
     vu[s]=true;
     dist[s]=0;
     int t;
     while (!q.empty()){
        t=q.front();
        q.pop();
        for (auto vois : adj[t]){
            if (!vu[vois]){
                q.push(vois);
                vu[vois]=true;
                dist[vois]=dist[t]+1;
            }
        }
     }
    return t;
}

void solve(){
    cin>>n;
    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    rep(i,1,n+1){
        sort(all(adj[i]));
    }
    int s=1;
    int t=farthest(s); // dsit actualisé
    s=farthest(t); // distances par rapport à t
    t=farthest(s); // dsitances par rapport à s
    int tmpDist=dist[t];
    rep(i,1,n+1){
        if (dist[i]*2 == tmpDist){
            cout<<max(s,t)<<"\n";
        }
        else if (dist[i]*2 > tmpDist){
            cout<<s<<"\n";
        }
        else cout<<t<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}