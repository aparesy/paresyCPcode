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

// bool croisement_seg(pii& d1, pii& f1, pii& d2, pii& f2){
//     return ((f1.first-d1.first)*(d2.first-d1.first)+(f1.second-d1.second)*(d2.second-d1.second))*
//         ((f1.first-d1.first)*(f2.first-d1.first)+(f1.second-d1.second)*(f2.second-d1.second))<=0;
// }

// Orientation test: returns sign of cross product
int orientation(pii a, pii b, pii c) {
    long long val = 1LL * (b.second - a.second) * (c.first - b.first) -
                    1LL * (b.first - a.first) * (c.second - b.second);
    if (val == 0) return 0;        // collinear
    return (val > 0) ? 1 : 2;      // 1 = clockwise, 2 = counterclockwise
}

// Check if point q lies on segment pr
bool onSegment(pii p, pii q, pii r) {
    return (q.first >= min(p.first, r.first) && q.first <= max(p.first, r.first) &&
            q.second >= min(p.second, r.second) && q.second <= max(p.second, r.second));
}

inline bool operator!=(const pii& a, const pii& b) {
    return a.first != b.first || a.second != b.second;
}

// Proper segment intersection test
bool croisement_seg(pii& d1, pii& f1, pii& d2, pii& f2) {
    int o1 = orientation(d1, f1, d2);
    int o2 = orientation(d1, f1, f2);
    int o3 = orientation(d2, f2, d1);
    int o4 = orientation(d2, f2, f1);

    // General case
    if (o1 != o2 && o3 != o4 && d1!=d2) return true;


    return false;
}


bool bipartite(vvi& adj){
    vi coul(adj.size());
    rep(i,0,adj.size()){
        if (coul[i]==0){
            coul[i]=1;
            queue<pii> q;
            q.push({i,1});
            while (!q.empty()){
                auto [s,couleur]=q.front();
                q.pop();
                for (auto t : adj[s]){
                    if (coul[t]==coul[s]) {return false; }
                    else if (coul[t]==0){
                        coul[t]=3-couleur;
                        q.push({t,3-couleur});
                    }
                }
            }
        }
    }
    return true;
}

void solve(){
    int w,p;
    cin>>w>>p;
    vii points(w);
    rep(i,0,w){
        int x,y;
        cin>>x>>y;
        points[i]={x,y};
    }
    vvi adj(p);
    vector<pair<int,pii>> segments(p);
    rep(i,0,p){
        int s,x,y;
        cin>>s>>x>>y; s--;
        segments[i]={s,make_pair(x,y)};
        rep(j,0,i){
            if (croisement_seg(points[s], segments[i].second, points[segments[j].first], segments[j].second)){
                adj[j].push_back(i);
                adj[i].push_back(j);
           //     cout<<i<<" "<<j<<endl;
            }
        }
    }

    if (bipartite(adj)) cout<<"possible";
    else cout<<"impossible";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}