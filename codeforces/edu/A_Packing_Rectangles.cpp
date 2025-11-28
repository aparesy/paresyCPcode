#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll unsigned long long
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x

void solve(){
    ll w, h, n;
    cin >> w >> h >> n;
    ll l = 0, r = 1e18;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        ll a = mid / w;
        ll b = mid / h;
        if (a == 0 || b == 0) {
            l = mid;
            continue;
        }
        if (a > n) a = n;
        // Check using division to avoid overflow
        if ((n + a - 1) / a <= b) r = mid;
        else l = mid;
    }
    cout << r << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}