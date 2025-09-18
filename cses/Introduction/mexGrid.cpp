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

int count_trailing_zeros(const bitset<200>& b) {
    for (int i = 0; i < 200; ++i) {
        if (!b[i]) return i;
    }
    return 200;
}

void solve(){
    int n;
    cin>>n;
    vector<bitset<200>> hor(n);
    vector<bitset<200>> ver(n);
    vvi grid(n,vi(n));
    rep(i,0,n){
        rep(j,0,n){
            grid[i][j]=count_trailing_zeros(hor[i]|ver[j]);
            hor[i][grid[i][j]]=true;
            ver[j][grid[i][j]]=true;
        }
    }
    rep(i,0,n){
        rep(j,0,n){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    } 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}