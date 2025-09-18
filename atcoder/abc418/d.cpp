#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define rep(i,a,b) for(int i=a;i<b;i++)

long double slope(ll x1, ll y1, ll x2, ll y2){
    if (y1==y2 && x1>x2) return 0.L;
    else if (y1==y2) return LDBL_MAX;
    return ((long double)(x2-x1))/((long double) abs(y2-y1));
}

void solve(){
    int n;
    cin>>n;
    vector<pair<ll,ll>> pt(n);
    rep(i,0,n){
        ll x,y;
        cin>>x>>y;
        pt[i]={x,y};
    }
    vector<pair<long double, pair<int,int>>> pentes;
    rep(i,0,n){
        rep(j,0,n){
            if (i!=j){
                pentes.push_back({slope(pt[i].first, pt[i].second, pt[j].first, pt[j].second),{i,j}});
            }
        }
    }
    sort(pentes.begin(), pentes.end());
    int curL=1;
    ll tot=0;
    rep(i,1,pentes.size()){
        if (pentes[i]==pentes[i-1]){
            curL++;
        }
        else{
            tot+=curL*(curL-1)/2;
            curL=1;
        }
        cout<<tot<<" "<<pentes[i]<<" "<<curL<<endl;
    }
    tot+=curL*(curL-1)/2;
    cout<<tot<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}