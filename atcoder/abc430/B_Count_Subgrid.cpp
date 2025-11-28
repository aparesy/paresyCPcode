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

ll mod=1e9+7ll;

ll hashGrid(vvl& grid, int n){
    ll tot=0;
    rep(i,0,n){
        rep(j,0,n){
            tot+=grid[i][j]+1ll;
            tot*=41ll;
            tot%=mod;
        }   
    }
    return tot;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vvl grid(n,vl(n));
    rep(i,0,n){
        string s;
        cin>>s;
        rep(j,0,n){
            if (s[j]=='.')grid[i][j]=0;
            else grid[i][j]=1;
        }
    }
    set<ll> differentHashes;
    rep(i,0,n-m+1){
        rep(j,0,n-m+1){
            vvl tmp(m, vl(m));
            rep(k,i,i+m){
                rep(l,j,j+m){
                    tmp[k-i][l-j]=grid[k][l];
                }
            }
            differentHashes.insert(hashGrid(tmp, m));
        }
    }
    cout<<differentHashes.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}