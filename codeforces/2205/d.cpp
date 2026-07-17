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

vi longestdecr(vi& tab){
    vi lis(n);
    // set<pair<int,int>> cur;
    // forn(i,n){
    //     auto it = cur.lower_bound({tab[i],99999999ll});
    //     if (it==cur.end()){
    //         cur.insert({tab[i],1});
    //         lis[i]=1;
    //     }
    //     else{   
    //         auto [a,b] = *it;
    //         cur.erase(*it);
    //         cur.insert({tab[i],b+1});
    //         lis[i]=b+1;
    //         var(a);
    //         var(b);
    //         var(tab[i]);
    //     }   
    // }
    // return lis;

    stack<pair<int,int>> st;
    forn(i,n){
        if (st.empty()){
            st.push({tab[i],1});
            lis[i] = 1;
        }
        else{
            while(!st.empty() && tab[i]>st.top().first){
                st.pop();
            }
            if (st.empty()){
                st.push({tab[i], 1});
            }
            else{
                st.push({tab[i], st.size()+1});
            }
            lis[i] = st.size();
        }
    }
    return lis;
}

void solve(){
    vi tab(n);
    forn(i,n) cin>>tab[i];
    vi lds = longestdecr(tab);
    vi tmp(n);
    forn(i,n){
        tmp[i]=tab[i];
    }
    forn(i,n){
        tab[i] = tmp[n-1-i];
    }
    vi lds2 = longestdecr(tab);

    int maxi=0;
    forn(i,n){
        // var(lds[i]);
        // var(lds[n-1-i]);
        maxi = max(maxi, lds[i]+lds2[n-1-i]-1);
    }
    cout<<n-maxi<<"\n";
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
    while (cin>>n) solve();
}