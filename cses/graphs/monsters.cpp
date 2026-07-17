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
int n,m;

bool valid(pii& a){
    return a.first>=0 && a.second>=0 && a.first<n && a.second<m;
}

void solve(){
    vector<string> grid(n);
    forn(i,n) cin>>grid[i];
    queue<pair<pii, int>> qm;
    queue<pair<pii, int>> qa;
    vvi vu(n,vi(m,false));
    vector<vii> prec(n,vii(m));
    pii a;
    forn(i,n){
        forn(j,m){
            if (grid[i][j]=='M'){
                vu[i][j]=true;
                qm.push({make_pair(i,j), 0});
            }
            if (grid[i][j]=='A'){
                vu[i][j]=true;
                qa.push({make_pair(i,j), 0});
                a={i,j};
            }
            if (grid[i][j]=='#'){
                vu[i][j]=true;
            }
        }
    }
    if (a.first==0 || a.second==0 || a.first==n-1 || a.second==m-1){
        cout<<"YES\n"<<0;
        return;
    }
    vector<pii> delta{{1,0},{0,1},{-1,0},{0,-1}};
    while(!qa.empty()){
        // One round of monsters progressing and one step of self progressing
        auto r = (qa.front()).second;
        while(!qm.empty() && qm.front().second==r){
            auto [pos, _] = qm.front();
            qm.pop();
            for (auto d : delta){
                pii pos2{pos.first+d.first, pos.second+d.second};
                if (valid(pos2) && !vu[pos2.first][pos2.second]){
                    vu[pos2.first][pos2.second]=true;
                    qm.push({pos2,r+1});
                }
            }
        }

        while(!qa.empty() && qa.front().second==r){
            auto [pos, _] = qa.front();
            qa.pop();
            for (auto d : delta){
                pii pos2{pos.first+d.first, pos.second+d.second};
                if (valid(pos2) && !vu[pos2.first][pos2.second]){
                    vu[pos2.first][pos2.second]=true;
                    prec[pos2.first][pos2.second]=d;
                    qa.push({pos2,r+1});


                    if (pos2.first==0 || pos2.first==n-1 || pos2.second==0 || pos2.second==m-1){
                        cout<<"YES\n";
                        cout<<r+1<<"\n";
                        pii cur=pos2;
                        vector<char> res;
                        while (cur!=a){
                            pii tmp=prec[cur.first][cur.second];
                            if (tmp.first==-1) res.push_back('U');
                            if (tmp.first==1) res.push_back('D');
                            if (tmp.second==-1) res.push_back('L');
                            if (tmp.second==1) res.push_back('R');
                            cur.first-=tmp.first;
                            cur.second-=tmp.second;
                        }
                        reverse(all(res));
                        for (auto x : res) cout<<x;
                        return;
                    }
                }
            }
        }
    }

    cout<<"NO\n";
    return;
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin>>n>>m) solve();
}