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
    int k;
    cin>>k;
    string s;
    cin>>s;
    stack<int> people;
    queue<int> events;
    forn(i,n){
        if (s[i]=='0'){
            if (people.size()==k-1){
                if (people.size()==0){
                    cout<<-1<<"\n";
                    return;
                }
                else{
                    auto x = people.top();
                    people.pop();
                    events.push(x);
                    people.push(i+1);
                    events.push(i+1);
                }
            }
            else{
                people.push(i+1);
                events.push(i+1);
            }
        }
        else{
            if (people.size()<k-1){
                cout<<-1<<"\n";
                return;
            }
            while(people.size()>=k){
                auto x = people.top();
                people.pop();
                events.push(x);
            }
            people.push(i+1);
            events.push(i+1);
        }
    }
    vi vu(n+1);
    cout<<events.size()<<"\n";
    while(!events.empty()){
        auto x = events.front();
        events.pop();
        if (vu[x]){
            cout<<'O'<<" "<<x<<"\n";
        }
        else{
            cout<<'I'<<" "<<x<<"\n";
            vu[x]=true;
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
    int ttt; cin>>ttt;
    while (cin>>n) solve();
}