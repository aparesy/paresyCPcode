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
    map<string, map<char,pair<bool,pair<int,int>>>> mp;
    vector<tuple<int,int,int,int>> v; // pbs, penalty, last submission, team number. Sort needs to be decreasing except for last submission, so we negate it 
    map<int,string> name_of_id;
    map<string,stack<pair<pair<int,int>,int>>> submissions; //penalty, time and time without penalty, im so cooked
    map<string,int> prevok;
    forn(i,s){
        string a,b,c,d;
        cin>>a>>b>>c>>d;
        var(a);
        char pb = b[0];
        int tm = str_to_time(c);
        if (mp.count(a) && mp[a].count(pb) && mp[a][pb].first){
            continue;
        }
        if (d[0]=='O' && d[1]=='K'){
            mp[a][pb].first=1;
            mp[a][pb].second.first-=tm;
            mp[a][pb].second.second=prevok[a];
            submissions[a].push({mp[a][pb].second, tm}); // Now we get previous time which is very good
            prevok[a]=-i;
        }
        else{   
            mp[a][pb].second.first-=20;
        }
    }
    int i=0;
    for (auto [nm, tot] : mp){
        tuple<int,int,int,int> tmp;
        T(tmp,0)= 0;
        T(tmp,1)= 0;
        T(tmp,2)= 0;
        T(tmp,3)= i;
        name_of_id[i]=nm;
        for (auto [pb, tm] : tot){
            if (tm.first){
                T(tmp,0)++;
                T(tmp,1)+=tm.second.first;
                T(tmp,2)=min(T(tmp,2), tm.second.second);
            }
        }
        v.push_back(tmp);
        i++;
    }
    sort(all(v));
    vector<tuple<int,int,int,int>> v2=v;
    reverse(all(v));
    // Now v is scoreboard
    var(v2.size());
    var(T(v2[0],0));
    var(T(v2[0],1));
    var(T(v2[0],2));
    var(T(v2[0],3));
    var(name_of_id[1]);
    set<pair<string,string>> st;
    forn(i,12){
        string cur=name_of_id[T(v[i],3)];
        auto tmp = v[i];
        bool ok=true;
        while(ok){
            if (submissions[cur].empty()) break;
            auto lastsub2=submissions[cur].top();
            auto lastsub=lastsub2.first;
            submissions[cur].pop();
            tmp = {T(tmp,0)-1,T(tmp,1)-lastsub.first,lastsub.second,-1};
            int x = v2.end()-lower_bound(all(v2), tmp);
            var(x);
            if (x>12){
                ok=false;
                string y="x:xx";
                y[0]=(lastsub2.second/60)+'0';
                y[2]=(lastsub2.second%60)/10+'0';
                y[3]=(lastsub2.second%60)%10+'0';
                st.insert({y,cur});
            }
        }
    }

    for(auto [aa,bb] : st){
        cout<<bb<<" "<<aa<<"\n";
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