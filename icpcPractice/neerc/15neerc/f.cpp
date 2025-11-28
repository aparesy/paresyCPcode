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

struct Point{
    double x;
    double y;
};

double eps=1e-8;

void solve(){
    double w;
    cin>>w;
    int n=get();
    vector<Point> stones(n);
    rep(i,0,n){
        cin>>stones[i].x>>stones[i].y;
    }
    double l=0;
    double r=w;
    if (n==0){
        cout<<w/2.<<" "<<0.;
        return;
    }
    pair<double, double> tmp;
    while(r-l>eps){
        double m=(r+l)/2.;
        stack<int> s;
        vb vu(n);
        vb vu2(n);
        vvi adj(n);
        rep(i,0,n){
            rep(j,0,n){
                if (hypot(stones[i].x-stones[j].x, stones[i].y-stones[j].y)<=m) adj[i].push_back(j);
            }
        }
        rep(i,0,n){
            if (stones[i].x<m){
                s.push(i);
                vu[i]=true;
            }
        }
        while (!s.empty()){
            auto v=s.top();
            s.pop();
            for (auto t : adj[v]){
                if (!vu[t]){
                    vu[t]=true;
                    s.push(t);
                }
            }
        }
        rep(i,0,n){
            if (stones[i].x>=w-m){
                s.push(i);
                vu2[i]=true;
            }
        }
        while (!s.empty()){
            auto v=s.top();
            s.pop();
            for (auto t : adj[v]){
                if (!vu2[t]){
                    vu2[t]=2;
                    s.push(t);
                }
            }
        }
        bool ok=false;
        
        rep(i,0,n){
            if (stones[i].x<=2.*m && vu2[i]){
                ok=true;
                tmp.first=stones[i].x/2.;
                tmp.second=stones[i].y;
            }
            if (stones[i].x>=w-2.*m && vu[i]){
                ok=true;
                tmp.first=stones[i].x/2.+w/2.; 
                tmp.second=stones[i].y;
            }
            if (ok) break;
        }

        if (!ok){
            rep(i,0,n){
                rep(j,0,n){
                    if (vu[i] && vu2[j] && hypot(stones[i].x-stones[j].x, stones[i].y-stones[j].y)<=2.*m){
                        ok=true;
                        tmp.first=stones[i].x/2.+stones[j].x/2.;
                        tmp.second=stones[i].y/2.+stones[j].y/2.;
                    } 
                }
            }
            if (ok) break;
        }

        if (ok){
            r=m;
        }
        else l=m;
    }
    cout<<fixed<<setprecision(3)<<tmp.first<<" "<<tmp.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("froggy.in", "r", stdin);
    freopen("froggy.out", "w", stdout);

    solve();
}