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
int p,s;

int str_to_time(string st){
    return ((int)st[3]-'0')+10*((int)st[2]-'0')+60*((int)st[0]-'0');
}

void solve(){
    map<string,map<char,pair<int,int>>> mp; 
    map<string,tuple<int,int,int>> score; 
    stack<pair<tuple<string,string,string,string>,int>> subs;
    forn(i,s){
        string a,b,c,d;
        cin>>a>>b>>c>>d;
        char pb = b[0];
        int tm = str_to_time(c);
        if (mp.count(a) && mp[a].count(pb) && mp[a][pb].first){
            continue;
        }
        if (d==string("OK")){
            mp[a][pb].first=1;
            mp[a][pb].second+=tm;
            T(score[a],0)--;
            T(score[a],1)+=mp[a][pb].second;
            tuple<string,string,string,string> x = {a,b,c,d};
            subs.push(make_pair(x, T(score[a],2)));
            T(score[a],2)=i;
        }
        else{
            mp[a][pb].second+=20;
        }
    }

    vector<pair<tuple<int,int,int>,string>> v;
    for (auto [a,b] : score){
        v.push_back({b,a});
    }
    sort(all(v));

    set<string> medals;
    forn(i,12){
        medals.insert(v[i].second);
    }

    vector<tuple<int,int,int>> v2;
    for(auto [a,b] : v) v2.push_back(a);

    vector<pair<string,string>> res;
    map<string, tuple<int,int,int>> curState;
    for (auto str : medals){
        curState[str] = score[str];
    }
    while(!subs.empty()){
        auto [subinfo,lasttime] = subs.top();
        subs.pop();
        if (lower_bound(all(v2), curState[T(subinfo,0)]) - v2.begin()>12) continue;
        auto& x = curState[T(subinfo,0)];
        T(x,0)++;
        char pb = T(subinfo,1)[0];
        T(x,1)-=mp[T(subinfo,0)][pb].second;
        T(x,2)=lasttime;
        if (lower_bound(all(v2), curState[T(subinfo,0)]) - v2.begin()>12){
            res.push_back({T(subinfo,2),T(subinfo,0)});
        }
    }

    reverse(all(res));
    for (auto [x,y] : res){
        cout<<y<<" "<<x<<"\n";
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
    while (cin>>p>>s) solve();
}