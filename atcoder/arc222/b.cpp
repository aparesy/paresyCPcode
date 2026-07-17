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
int a,b,c;

void solve(){
    int tot=0;

    int maxi = max({a,b,c});

    auto arrange2= [&](int& cur, int& loser, int& winner){
        if (winner==0 && cur==loser){
            tot+=cur;
            return;
        }
        if (loser==0 && cur==winner){
            tot+=cur;
            return;
        }
        if (cur==winner && cur==loser){
            if (cur==1) return;
            if (cur==2){
                tot+=1;
                return;
            }
            tot+=3ll*((cur-1ll)/2ll) + (cur%2==0);
            return;
        }
        if (cur==winner){
            if (loser==0){
                tot+=cur;
                cur=0;
                winner=0;
            }
            else{
                tot+=cur-1;
                cur=0;
                winner=1;
            }
        }
        else{
            // cur > winner
            if (winner){
                tot+=winner;
                cur-=winner+1;
                winner=0;
            }
            else{
                if (cur==loser){
                    tot+=cur;
                    cur=loser=0;
                }
            }
        }
        tot+=max(0ll,min(cur,loser-1ll));
    };

    auto transit = [](int qty, int& a, int& b){
        a-=qty;
        b+=qty;
    };

    auto arrange = [&](int& cur, int& loser, int& winner){
        int curw = cur/2;
        int curl = (cur+1)/2;
        int loserw = loser/2;
        int loserl = (loser+1)/2;
        int winnerw = winner/2;
        int winnerl = (winner+1)/2;
        // int x = max(0ll,min(winnerl-1ll,loserw)); 
        // if (x==0){
        //     transit(winnerl, winnerl, winnerw);
        //     transit(loserw, loserw, loserl);
        // }
        // else{
        //     transit(winnerl+1-x, winnerl, winnerw);
        //     transit(loserw-x,loserw,loserl);
        // }
        // tot+=x;


        if (loserl<curw+1){
            int x = min(curw+1ll, loserw+loserl);
            transit(x-loserl,loserw,loserl);
        }

        if (winnerw<curl-1){
            int x = min(curl-1ll, winnerw+winnerl);
            transit(x-winnerw,winnerl,winnerw); 
        }

        int x;
        if (curw<loserl-1){
            x = min(loserl-1, curw+curl);
            transit(x-curw, curl, curw);
        }

        if (curw>loserl-1){
            if (loserl){
                transit(curw-(loserl-1),curw,curl);
            }
            else{
                transit(curw,curw,curl);
            }
        }
            tot+=max(0ll, min(curw, loserl+1ll));

            tot+=max(0ll, min(winnerw, curl+1ll));

        tot+=max(0ll,min(loserw,winnerl-1ll));
    };

    if (maxi==a){
        arrange(a,b,c);
    }
    else if (maxi==b){
        arrange(b,c,a);
    }
    else{
        arrange(c,a,b);
    }
    cout<<tot<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ttt; cin>>ttt;
    while (cin>>a>>b>>c) solve();
}