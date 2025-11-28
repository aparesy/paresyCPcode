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

bool vu[501][501][2];

pii fstMove;
pii sndMove;
int n;

void dfs(int x, int y, int type){
    // type is 0 or 1
    int a,b;
    if (type==1){
        a=fstMove.first; b=fstMove.second;
    }
    else{
        a=sndMove.first; b=sndMove.second;
    }
    if (x>=a){
        if (y>=b){
            if (!vu[x-a][y-b][type]){
                vu[x-a][y-b][type]=true;
                dfs(x-a,y-b,1-type);
            }
        }
        if (y+b<n){
            if (!vu[x-a][y+b][type]){
                vu[x-a][y+b][type]=true;
                dfs(x-a,y+b,1-type);
            }
        }
    }
    if (x+a<n){
        if (y>=b){
            if (!vu[x+a][y-b][type]){
                vu[x+a][y-b][type]=true;
                dfs(x+a,y-b,1-type);
            }
        }
        if (y+b<n){
            if (!vu[x+a][y+b][type]){
                vu[x+a][y+b][type]=true;
                dfs(x+a,y+b,1-type);
            }
        }
    }

    swap(a,b);
    if (x>=a){
        if (y>=b){
            if (!vu[x-a][y-b][type]){
                vu[x-a][y-b][type]=true;
                dfs(x-a,y-b,1-type);
            }
        }
        if (y+b<n){
            if (!vu[x-a][y+b][type]){
                vu[x-a][y+b][type]=true;
                dfs(x-a,y+b,1-type);
            }
        }
    }
    if (x+a<n){
        if (y>=b){
            if (!vu[x+a][y-b][type]){
                vu[x+a][y-b][type]=true;
                dfs(x+a,y-b,1-type);
            }
        }
        if (y+b<n){
            if (!vu[x+a][y+b][type]){
                vu[x+a][y+b][type]=true;
                dfs(x+a,y+b,1-type);
            }
        }
    }
}

void solve(){
    cin>>n>>fstMove.first>>fstMove.second>>sndMove.first>>sndMove.second;
    dfs(0,0,0);
    dfs(0,0,1);
    vu[0][0][0]=true;
    vu[0][0][1]=true;
    int tot=0;
    rep(i,0,n){
        rep(j,0,n){
            tot+= (vu[i][j][0] || vu[i][j][1]);
        }
    }
    cout<<tot;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}