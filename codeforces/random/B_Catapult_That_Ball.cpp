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

const int N = 1e5 + 14, S = 300;
int n, q, a[N], b[N];

int main() {
    int t; cin>>t;
        while(t--){
        cin >> n >>q;
        for(int i = 0; i < n; ++i)
            {cin >> a[i]; a[i]=-a[i];}
        for(int i = 0; i < n; i += S)
            b[i / S] = *min_element(a + i, a + i + S);
        int tot=0;
        while(q--) {
            int l, r;
            cin >> l >> r; l--; r--;
            int l0=l;
            int ans = INT_MAX;
            while (l < r){
                if(l % S == 0 and l + S <= r) {
                    ans = min(ans, b[l / S]);
                    l += S;
                }
                else
                    ans = min(ans, a[l++]);
            }   
            tot+=(ans>=a[l0]);
        }
        cout<<tot<<"\n";
    }
}

