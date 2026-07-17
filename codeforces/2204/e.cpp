#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
 
#ifdef DEBUG
 
#define var(x) cerr << #x << ": " << x << '\n';
#define range(a, b) cerr << #a << ", " << #b << ": "; for (auto _it = a; _it != b; ++_it) cerr << *_it << ' '; cerr << '\n';
#else
#define var(x)
#define range(a, b)
#define cerr if (false) cerr
#endif
 
#define vi vector<int>
#define vii vector<pii>
#define forn(i, n) for (int i = 0; i < n; i++) 
#define F first
#define S second
#define T(x, i) get<i>(x)
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define rep(i,a,b) for (int i = a; i < b; i++)
#define sz(v) int(v.size())

const int E2 = 100, E3 = 1000, E4 = 10000, E5 = 100000, E6 = 1000000, E9 = 1000000000;
const ll E18 = 1ll * E9 * E9;
const int FFT_MOD = 998244353;
const int SIMPLE_MOD = E9 + 7;
mt19937 rng(time(0));
 
 
#define int ll
 
const int MAXN = 2e6 + 10;
int n;
string s;
map<int,int> mp;

int reduce(int x){
    if (x<=9) return 0;
    int tot=0;
    while(x){
        tot+=(x%10);
        x/=10;
    }
    return tot;
}

int reduceTot(int x){
    if (x<=9) return x;
    return reduce(x)+reduceTot(reduce(x));
}

void addDigits(int cur, map<int,int>& mp2){
    while(cur){
        mp2[cur%10]++;
        cur/=10;
    }
}

void solve(){
    mp.clear();
    n=s.length();
    int tot=0;
    forn(i,n){
        tot+=s[i]-'0';
        mp[s[i]-'0']++;
    }
    // cout<<tot<<" "<<"aaa\n";
    if (s.length()<=1){
        cout<<s<<"\n";
        return;
    }
    if (mp[0]==n-2){
        vector<char> aaa;
        forn(i,n){
            aaa.push_back(s[i]);
        }
        sort(all(aaa));
        cout<<aaa[n-1];
        forn(i,n-1){
            cout<<aaa[i];
        }
        cout<<"\n";
        return;
    }
    forn(cur,1000000){
        if (cur==tot-reduceTot(cur)){
            // cout<<tot-reduceTot(cur)<<"\n";

            map<int,int> mp2;
            addDigits(reduce(cur),mp2);
            addDigits(reduce(reduce(cur)),mp2);
            addDigits(reduce(reduce(reduce((cur)))),mp2);
            addDigits(cur,mp2);

            bool ok=true;
            forn(i,10){
                if (mp2[i]>mp[i]){
                    // cout<<i<<" "<<mp2[i]<<" "<<mp[i]<<"\n";
                    ok=false;
                }
            }
            if (ok){
                // cout<<"b"<<"\n";
                for(int i=9;i>=0;i--){
                    forn(j,mp[i]-mp2[i]){
                        cout<<(char)(i+'0');
                    }
                }
                cout<<cur;
                if (reduce(cur)) cout<<reduce(cur);
                if (reduce(reduce(cur))) cout<<reduce(reduce(cur));
                if (reduce(reduce(reduce(cur)))) cout<<reduce(reduce(reduce(cur)));
                cout<<"\n";
                return;
            }
        }
    }
}   

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (cin>>s) solve();
}