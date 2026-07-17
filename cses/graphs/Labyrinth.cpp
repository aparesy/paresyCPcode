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
int n,m;

vector<string> grid;

int make_v(int i, int j){
    return i*m+j;
}

bool correct(int pos){
    int i=pos/m;
    int j=pos%m;
    if (i<0 || j<0) return false;
    if (i>=n || j>=m) return false;
    if (grid[i][j]=='#') return false;
    return true;
}

typedef struct cell{
    char prev;
    int pos;
    int i;
    int j;
    bool vu;
    int up(){
        if (i==0) return -1;
        else return pos-m;
    }
    int down(){
        if (i==n-1) return -1;
        else return pos+m;
    }
    int right(){
        if (j==m-1) return -1;
        return pos+1;
    }
    int left(){
        if (j==0) return -1;
        return pos-1;
    }
} cell;

void solve(){
    cin>>m;
    grid.resize(n);
    forn(i,n) cin>>grid[i];
    vector<cell> tab(n*m);
    queue<int> q;
    forn(i,n){
        forn(j,m){
            tab[i*m+j]={'X', i*m+j, i, j, false};
            if (grid[i][j]=='A'){
                q.push(make_v(i,j));
                tab[i*m+j].vu=true;
            }
        }
    }

    while(!q.empty()){
        int p=q.front();
        q.pop();
        int i=p/m;
        int j=p%m;
        if (grid[i][j]=='B'){
            vector<char> res;
            int pos=p;
            while(grid[pos/m][pos%m]!='A'){
                char c=tab[pos].prev;
                res.push_back(c);
                if (c=='D') pos=tab[pos].up();
                if (c=='U') pos=tab[pos].down();
                if (c=='L') pos=tab[pos].right();
                if (c=='R') pos=tab[pos].left();
            }
            reverse(all(res));
            cout<<"YES\n"<<sz(res)<<"\n";
            for (auto c : res){
                cout<<c;
            }
            cout<<"\n";
            return;
        }
        else{
            if (correct(tab[p].up()) && !tab[tab[p].up()].vu){
                tab[tab[p].up()].vu=true;
                tab[tab[p].up()].prev='U';
                q.push(tab[p].up());
            }
            if (correct(tab[p].down()) && !tab[tab[p].down()].vu){
                tab[tab[p].down()].vu=true;
                tab[tab[p].down()].prev='D';
                q.push(tab[p].down());
            }
            if (correct(tab[p].left()) && !tab[tab[p].left()].vu){
                tab[tab[p].left()].vu=true;
                tab[tab[p].left()].prev='L';
                q.push(tab[p].left());
            }
            if (correct(tab[p].right()) && !tab[tab[p].right()].vu){
                tab[tab[p].right()].vu=true;
                tab[tab[p].right()].prev='R';
                q.push(tab[p].right());
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
    while (cin>>n) solve();
}