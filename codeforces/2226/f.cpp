#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
 
#ifdef DEBUG
 
// #define var(x) cerr << #x << ": " << x << '\n';
#define var(x) cerr << #x << ": " << x.first<<" "<<x.second << '\n';
#define range(a, b) cerr << #a << ", " << #b << ": "; for (auto _it = a; _it != b; ++_it) cerr << *_it << ' '; cerr << '\n';
#else
#define var(x)
#define range(a, b)
#define cerr if (false) cerr
#endif
 
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define vvii vector<vii>
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

void solve(){
    vi tab(n);
    forn(i,n) cin>>tab[i];
    pair<int,int> oddgap1 = {-1,-1};
    pair<int,int> oddgap2 = {-1,-1};
    int maxOdd=-1;
    int minOdd=-1;
    forn(i,n) if (tab[i]%2) {
        if ((tab[i]%2 && tab[i]<maxOdd && (oddgap2 > pair(tab[i], -maxOdd) || oddgap2.first==-1))){
            oddgap2 = pair(tab[i], -maxOdd);
        }
        if (maxOdd==-1 || (tab[i]%2 && tab[i]>maxOdd)){
            maxOdd=tab[i];
        }
        if (minOdd==-1 || (tab[i]%2 && tab[i]<minOdd)){
            minOdd=tab[i];
        }
        if (tab[i] < maxOdd && (oddgap1 < pair(maxOdd, -tab[i]) || oddgap1.first==-1)){
            oddgap1 = pair(maxOdd, -tab[i]);
        }

    }

    pair<int,int> evengap1 = {-1,-1};
    pair<int,int> evengap2 = {-1,-1};
    int maxeven=-1;
    int mineven=-1;
    forn(i,n) if (!(tab[i]%2)){
        if ((!(tab[i]%2) && tab[i]<maxeven && (evengap2 > pair(tab[i], -maxeven) || evengap2.first==-1))){
            evengap2 = pair(tab[i], -maxeven);
        }
        if (maxeven==-1 || (!(tab[i]%2) && tab[i]>maxeven)){
            maxeven=tab[i];
        }
        if (mineven==-1 || (!(tab[i]%2) && tab[i]<mineven)){
            mineven=tab[i];
        }
        if (tab[i] < maxeven && (evengap1 < pair(maxeven, -tab[i]) || evengap1.first==-1)){
            evengap1 = pair(maxeven, -tab[i]);
        }
    }
    var(oddgap1);
    var(evengap1);
    var(oddgap2);
    var(evengap2);
    if (oddgap1.first!=-1 && maxeven<oddgap1.first && mineven > -oddgap1.second && maxeven != -1){
        cout<<"No\n";
    }
    else if (oddgap2.first!=-1 && maxeven < -oddgap2.second && mineven > oddgap2.first && maxeven != -1){
        cout<<"No\n";
    }
    else if (evengap1.first!=-1 && maxOdd<evengap1.first && minOdd > -evengap1.second && maxOdd != -1){
        cout<<"No\n";
    }
    else if (evengap2.first!=-1 && maxOdd < -evengap2.second && minOdd > evengap2.first && maxOdd != -1){
        cout<<"No\n";
    }
    else if (maxeven == -1){
        forn(i,n-1){
            if (tab[i]>tab[i+1]){
                cout<<"No\n";
                return;
            }
        }
    }
    else if (maxOdd==-1){
        forn(i,n-1){
            if (tab[i]>tab[i+1]){
                cout<<"No\n";
                return;
            }
        }
    }
    else{
        cout<<"Yes\n";
    }
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ttt; cin>>ttt;
    while (cin>>n) solve();
}