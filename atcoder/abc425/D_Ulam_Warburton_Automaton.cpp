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
    int h,w;
    cin>>h>>w;
    int totalPoints=0;
    vector<vb> grid(h,vb(w));
    stack<pair<int,int>> s;
    vector<vb> vu(h,vb(w));
    rep(i,0,h){
        rep(j,0,w){
            char c;
            cin>>c;
            if (c=='.'){
                grid[i][j]=false;
            }
            else{
                vu[i][j]=true;
                s.push({i,j});
                totalPoints++;
            }
        }
    }
    bool ok=true;
    vector<pii> directions = {{-1,0},{1,0},{0,1},{0,-1}};
    while(ok){
        ok=false;
        stack<pair<int,int>> s2;
        while(!s.empty()){
            auto [i,j]=s.top();
            grid[i][j]=true;
            s.pop();
            s2.push({i,j});
        }
        s=s2;
        s2={};
        while(!s.empty()){
            auto [i,j]=s.top();
            s.pop();
            for (auto dir : directions){
                int i2=i+dir.first;
                int j2=j+dir.second;
                if (i2>=0 && i2<h && j2>=0 && j2<w && !vu[i2][j2] && !grid[i2][j2]){
                    int tot=0;
                    for (auto dir2 : directions){
                        int i3=i2+dir2.first;
                        int j3=j2+dir2.second;
                        if (i3>=0 && i3<h && j3>=0 && j3<w){
                            tot+=grid[i3][j3];
                        }
                    }
                    vu[i2][j2]=true;
                    if (tot==1){
                        ok=true;
                        s2.push({i2,j2});
                        totalPoints++;
                    }
                }
            }
        }
        s=s2;
        s2={};
    }
    cout<<totalPoints;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}