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

struct Point {
    int x, y;
};

bool canCover(vector<Point>& points, int K, int L) {
    int N = points.size();
    vector<bool> covered(N, false);
    sort(points.begin(), points.end(), [](auto &a, auto &b) {
        return a.x < b.x;
    });

    int used = 0;
    while (true) {
        // find first uncovered point
        int i = -1;
        for (int t = 0; t < N; t++) {
            if (!covered[t]) { i = t; break; }
        }
        if (i == -1) return true; // all covered
        if (used == K) return false;

        used++;
        int bestCover = 0;
        vector<bool> bestMark(N, false);

        // try placing square's bottom edge using y-values within x[i] + L
        for (int j = i; j < N && points[j].x <= points[i].x + L; j++) {
            int y0 = points[j].y;

            vector<bool> temp = covered;
            int cnt = 0;
            for (int t = 0; t < N; t++) {
                if (!temp[t] &&
                    points[t].x >= points[i].x &&
                    points[t].x <= points[i].x + L &&
                    points[t].y >= y0 &&
                    points[t].y <= y0 + L) {
                    temp[t] = true;
                    cnt++;
                }
            }
            if (cnt > bestCover) {
                bestCover = cnt;
                bestMark = temp;
            }
        }
        covered = bestMark;
    }
}

int solve(){
    int n,k;
    cin>>n>>k;
    vector<Point> points(n);
    rep(i,0,n){
        cin>>points[i].x>>points[i].y;
    }
    int l=-1;
    int r=64001;
    while(r-l>1){
        int m=(r+l)/2;
        if (canCover(points,k,m)){
            r=m;
        }
        else l=m;
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    {int x=solve(); cout<<"Case #"<<t+1<<": "<<x<<"\n";};
}