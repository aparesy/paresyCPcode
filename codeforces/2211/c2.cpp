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
#define vvi vector<vector<int>>
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
int n,k;

void solve(){
    vi a(n);
    vi b(n);
    forn(i,n){
        cin>>a[i];
    }
    map<int,int> mp1;
    map<int,int> mp2;
    forn(i,n){
        cin>>b[i];
    }
    forn(i,k){
        bool ok=true;
        set<int> st;
        if (b[i]!=-1) st.insert(b[i]);
        for (int j=i;j+k<n;j+=k){
            if (a[j]!=a[j+k]){ok=false;}
            if (b[j+k]!=-1) st.insert(b[j+k]);
        }
        var(i);
        var(ok);
        if (!ok){
            for (int j=i;j<n;j+=k){
                if (b[j]!=-1 && b[j]!=a[j]){
                    cout<<"NO\n";
                    return;
                }
                b[j]=a[j];
            }
        }
        else{
            if (sz(st)>=2){
                cout<<"NO\n";
                return;
            }
            if (sz(st)==1){
                b[i]=*st.begin();
            }
        }
    }
    forn(i,k){
        mp1[a[i]]++;
        mp2[b[i]]++;
    }
    for(auto [xx,b] : mp1){
        if (b<mp2[xx]){
            cout<<"NO\n";
            return;
        }
    }
    for(auto [xx,b] : mp2){
        if (b>mp1[xx] && xx!=-1){
            cout<<"NO\n";
            return;
        }
    }
    // for (int i=0;i+k<n;i++){
    //     //shift from i to i+1
    //     if (a[i]==a[i+k]){
    //         if (b[i]!=-1 && b[i+k]!=-1){
    //             if (b[i]!=b[i+k]){
    //                 cout<<"NO\n";
    //                 return;
    //             }
    //             int cur=i;
    //             while(cur>=k && b[cur-k]==-1){
    //                 cur-=k;
    //                 b[k]=b[k+cur];
    //             }
    //             if (cur>=k && b[cur-k]!=b[k] && a[cur-k]==a[k]){
    //                 cout<<"NO\n";
    //                 return;
    //             }
    //         }
    //         if (!(b[i]==-1 && b[i+k]==-1)){
    //             if (b[i+k]==-1){
    //                 b[i+k]=b[i];
    //             }
    //             else{
    //                 b[i]=b[i+k];
    //                 int cur=i;
    //                 while(cur>=k && b[cur-k]==-1){
    //                     cur-=k;
    //                     b[k]=b[k+cur];
    //                 }
    //                 if (cur>=k && b[cur-k]!=b[k] && a[cur-k]==a[k] ){
    //                     cout<<"NO\n";
    //                     return;
    //                 }
    //             }
    //         }
    //     }
    //     else{
    //         // OK
    //         if (b[i]!=a[i] && b[i]!=-1){
    //             cout<<"NO\n";
    //             return;
    //         }
    //         if (b[i+k]!=a[i+k] && b[i+k]!=-1){
    //             cout<<"NO\n";
    //             return;
    //         }
    //         b[i+k]=a[i+k];
    //         b[i]=a[i];
    //         int cur=i;
    //         while(cur>=k && b[cur-k]==-1){
    //             cur-=k;
    //             b[k]=b[k+cur];
    //         }
    //         if (cur>=k && b[cur-k]!=b[k] && a[cur-k]==a[k]){
    //             cout<<"NO\n";
    //             return;
    //         }
    //     }
    // }
    // mp1.clear();
    // mp2.clear();
    // reverse(all(b));
    // reverse(all(a));
    // forn(i,k){
    //     mp1[a[i]]++;
    //     mp2[b[i]]++;
    // }
    // for(auto [xx,b] : mp1){
    //     if (b<mp2[xx]){
    //         cout<<"NO\n";
    //         return;
    //     }
    // }
    cout<<"YES\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ttt; cin>>ttt;
    while (cin>>n>>k) solve();
}