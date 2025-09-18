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
#define rep(i,a,b) for(int i=a;i<b;i++)

pair<ll,ll> fib (bitset<400000>& n, ll mod) {
    pair<ll,ll> res = {0, 1}; // (F(0), F(1))

    // Traverse bits from most significant to least
    bool started = false;
    for (int i = n.size() - 1; i >= 0; i--) {
        if (!started && !n[i]) continue; // skip leading zeros
        started = true;

        // Apply doubling formulas
        ll a = res.first;   // F(k)
        ll b = res.second;  // F(k+1)
        ll c = (a * ((2LL * b % mod - a + mod) % mod)) % mod;     // F(2k)
        ll d = ((a * a) % mod + (b * b) % mod) % mod;             // F(2k+1)

        if (n[i])  // bit = 1 → advance
            res = {d, (c + d) % mod};
        else       // bit = 0 → stay
            res = {c, d};
    }

    return res; // res.first = F(n), res.second = F(n+1)
}

void solve(){
    string s;
    cin>>s;
    bitset<400000> n;
    string dec = s;
    int idx = 0;
    while (dec != "0") {
        int carry = 0;
        string next = "";
        for (char c : dec) {
            int cur = carry * 10 + (c - '0');
            int q = cur / 2;
            carry = cur % 2;
            if (!next.empty() || q > 0) next.push_back('0' + q);
        }
        n[idx++] = carry; // least significant bit
        dec = next.empty() ? "0" : next;
    }
    ll mod= 1000000007LL;
    cout<<fib(n,mod).first<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}