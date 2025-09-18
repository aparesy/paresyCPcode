#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x

ll backtrack(vb& col, vb& diag1, vb& diag2, int i, vector<vector<char>>& plateau){
    if (i==8) return 1;
    ll tot=0;
    rep(j,0,8){
        if (!col[j] && !diag1[i+j] && !diag2[7-i+j] && plateau[i][j]=='.'){
            col[j]=true; diag1[i+j]=true; diag2[7-i+j]=true;
            tot+=backtrack(col,diag1,diag2,i+1,plateau);
            col[j]=false; diag1[i+j]=false; diag2[7-i+j]=false;
        }
    }
    return tot;
}

void solve(){
    vector<vector<char>> plateau(8,vector<char>(8));
    rep(i,0,8){
        input(plateau[i]);
    }
    ll tot=0;
    vb col(8);
    vb diag1(8);
    vb diag2(8);
    cout<<backtrack(col,diag1,diag2,0,plateau);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}