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
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x

void solve(){   
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    rep(i,0,n){
        rep(j,0,m){
            cin>>grid[i][j];
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            vector<char> eviter;
            if (i!=0){
                eviter.push_back(grid[i-1][j]);
            }
            if (j!=0){
                eviter.push_back(grid[i][j-1]);
            }
            eviter.push_back(grid[i][j]);
            if (find(eviter.begin(), eviter.end(), 'A')==eviter.end()){
                grid[i][j]='A';
            }
            else if (find(eviter.begin(), eviter.end(),'B')==eviter.end()){
                grid[i][j]='B';
            }
            else if (find(eviter.begin(), eviter.end(),'C')==eviter.end()){
                grid[i][j]='C';
            }
            else{
                grid[i][j]='D';
            }
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            cout<<grid[i][j];
        }
        cout<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}