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
    vvl tab(n,vl(m));
    rep(i,0,n){
        rep(j,0,m){
            cin>>tab[i][j];
        }
    }
    ll maxi=0LL;
    vector<vb> vu(n,vb(m));
    rep(i,0,n){
        rep(j,0,m){
            if (!vu[i][j] && tab[i][j]){
                queue<pii> q;
                q.push({i,j});
                vu[i][j]=true;
                ll tot=tab[i][j];
                while (!q.empty()){
                    auto [a,b]=q.front();
                    q.pop();
                    for (auto [c,d] : {make_pair(0,1),make_pair(1,0),make_pair(-1,0),make_pair(0,-1)}){
                        ll dir1=a+c; auto dir2=b+d;
                        if (0<=dir1 && 0<=dir2 && n>dir1 && m>dir2 && !vu[dir1][dir2] && tab[dir1][dir2]){
                            q.push({dir1,dir2});
                            vu[dir1][dir2]=true;
                            tot+=tab[dir1][dir2];
                        }
                    }
                }
                if (tot>maxi) maxi=tot;
            }
        }
    }
    cout<<maxi<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}