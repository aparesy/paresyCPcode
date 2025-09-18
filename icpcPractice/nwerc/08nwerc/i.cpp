#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vpi vector<pair<int,int>>
#define pii pair<int,int>

double norm(pii v){
    return sqrt((double)(v.first*v.first+v.second*v.second));
}

// double distance(pii a1, pii a2, pii b){
//     pii parallel = {a2.first-a1.first, a2.second-a1.second};
//     pii normal = {parallel.second, -parallel.first};
//     return ((double) fabs(normal.first*(a1.first-b.first)-normal.second*(a1.second-b.second)) / (double)norm(normal));
// }

double distance(pii a, pii b, pii p) {
    double x = p.first, y = p.second;
    double x1 = a.first, y1 = a.second;
    double x2 = b.first, y2 = b.second;
    double dx = x2 - x1, dy = y2 - y1;
    if (dx == 0 && dy == 0) {
        // a and b are the same point
        return hypot(x - x1, y - y1);
    }
    double t = ((x - x1) * dx + (y - y1) * dy) / (dx * dx + dy * dy);
    if (t < 0) return hypot(x - x1, y - y1);
    if (t > 1) return hypot(x - x2, y - y2);
    double proj_x = x1 + t * dx;
    double proj_y = y1 + t * dy;
    return hypot(x - proj_x, y - proj_y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
    int ni;
    cin>>ni;
    vpi inner(ni);
    for (int i=0;i<ni;i++){
        int a,b;
        cin>>a>>b;
        inner[i]={a,b};
    }
    inner.push_back(inner[0]);
    int no;
    cin>>no;
    vpi outer(no);
    for (int i=0;i<no;i++){
        int a,b;
        cin>>a>>b;
        outer[i]={a,b};
    }
    outer.push_back(outer[0]);
    double mindist=(double)1e18;
    for (int i=0;i<ni;i++){
        for (int j=0;j<no;j++){
            if (distance(inner[i], inner[i+1], outer[j])<mindist){
                mindist=distance(inner[i], inner[i+1], outer[j]);
            }
        }
    }
    for (int i=0;i<no;i++){
        for (int j=0;j<ni;j++){
            if (distance(outer[i], outer[i+1], inner[j])<mindist){
                mindist=distance(outer[i], outer[i+1], inner[j]);
            }
        }
    }
    cout<<setprecision(10)<<mindist/2.<<endl;
    }
}