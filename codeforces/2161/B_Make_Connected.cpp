// Useful functions : nth_element, rotate, unique, merge, count, generate

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
using ll=long long;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x
#define all(x) x.begin(),x.end()

ll get(){
   ll x;
   cin>>x;
   return x;
}

void solve(){
    int n=get();
    vvi grid(n, vi(n));
    rep(i,0,n){
        string s;
        cin>>s;
        rep(j,0,n){
            if (s[j]=='.'){
                grid[i][j]=0; // White
            }
            else grid[i][j]=1;
        }
    }

    vii cases;

    rep(i,0,n){
        rep(j,0,n){
            if (grid[i][j]){
                cases.push_back({i,j});
            }
        }
    }

    if (cases.size() == 0){
        cout<<"YES\n";
        return;
    }

    bool square=false;
    rep(i,0,n-1){
        rep(j,0,n-1){
            if (grid[i][j] && grid[i+1][j] && grid[i][j+1] && grid[i+1][j+1]){
                square=true;
            }
        }
    }

    if (square && cases.size()!=4){
        cout<<"NO\n";
        return;
    }
    if (square){
        cout<<"YES\n";
        return;
    } 

    vi c1(2*n);
    vi c2(2*n);
    for (auto [i,j] : cases){
        c1[i-j+n]++;
        c2[i+j]++;
    }
    bool d1, d2;
    d1=false;
    d2=false;
    int count1=0; int count2=0;
    rep(i,0,2*n){
        if(c1[i]){
            count1++;
        }
        if (count1>=2&& c1[i] && !c1[i-1]) d1=true;
        if (count1>2) d1=true;
    }
    rep(i,0,2*n){
        if(c2[i]){
            count2++;
        }
        if (count2>=2&& c2[i] && !c2[i-1]) d2=true;
        if (count2>2) d2=true;
    }
    if (d1&&d2){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}