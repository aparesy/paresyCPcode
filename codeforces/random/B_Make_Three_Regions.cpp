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

int nvRegions(vector<string>& s, int i, int j, int n){
    if (s[i][j]=='x')return 0;
    if (j==0){
        if (s[1-i][j]=='.'){
            if (s[1-i][j+1]=='x' && s[i][j+1]=='.') return 1;
            else return 0;
        }
        else{
            return 0;
        }
    }
    if (j==n-1){
        if (s[1-i][j]=='.'){
            if (s[1-i][j-1]=='x' && s[i][j-1]=='.') return 1;
            else return 0;
        }
        else{
            return 0;
        }
    }
    if (s[1-i][j]=='x'){
        if (s[i][j+1]=='.' && s[i][j-1]=='.'){
            return 1;
        }
        else return 0;
    }
    if (s[i][j-1]=='.' && s[i][j+1]=='.'){
        return (s[1-i][j-1]=='x') + (s[1-i][j+1]=='x');
    }
    if (s[i][j-1]=='.'){
        return (s[1-i][j-1]=='x');
    }
    if (s[i][j+1]=='.'){
        return (s[1-i][j+1]=='x');
    }
    return 0;
}

void solve(){
    int n;
    cin>>n;
    vector<string> s(2);
    cin>>s[0]>>s[1];
    int cc=0;
    vb vu(2*n);
    queue<pair<int,int>> q;
    rep(i,0,2){
        rep(j,0,n){
            if (s[i][j]=='.' && !vu[i*n+j]){
                vu[i*n+j]=true;
                q.push({i,j});
                cc++;
                while (!q.empty()){
                    auto [x,y]=q.front();q.pop();
                    if (y && !vu[x*n+y-1]&&s[x][y-1]=='.'){
                        vu[x*n+y-1]=true;
                        q.push({x,y-1});
                    }
                    if (y!=n-1 && !vu[x*n+y+1]&&s[x][y+1]=='.'){
                        vu[x*n+y+1]=true;
                        q.push({x,y+1});
                    }
                    if (!vu[(1-x)*n+y]&&s[1-x][y]=='.'){
                        vu[(1-x)*n+y]=true;
                        q.push({1-x,y});
                    }
                }
            }
        }
    }
    int tot=0;
    rep(i,0,2){
        rep(j,0,n){
            if (cc+nvRegions(s,i,j,n)==3) tot++;
        }
    }
    cout<<tot<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}