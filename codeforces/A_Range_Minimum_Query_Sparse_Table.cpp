#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAX_N = 1e6 + 14, LG = 20;

int n, q, a[MAX_N], sp[MAX_N][LG];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        cin >> n;
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sp[i][0] = a[i];
        }
        
        for (int k = 1; k < LG; ++k)
            for (int i = 0; i + (1 << k) <= n; ++i)
                sp[i][k] = min(sp[i][k - 1], sp[i + (1 << (k - 1))][k - 1]);
        
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            ++r;
            int k = 0;
            while (1 << k + 1 <= r - l) {
                ++k;
            }
            cout << min(sp[l][k], sp[r - (1 << k)][k]) << endl;
        }
    }
}