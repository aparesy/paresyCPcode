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
#define vvb vector<vb>

ll get(){
   ll x;
   cin>>x;
   return x;
}

int charToInt(char c){
    return c-'A';
}

pair<pii, int> dirNaturelle(int dir, char c, pii coord){
    int x=charToInt(c);
    pair<pii, int> res;
    res.first=coord;
    if (x==0){
        res.second=dir;
        switch (dir)
        {
        case 1:
            /* code */ res.first.first++;
            break;
        case 2:
            /* code */ res.first.second--;
            break;
                case 3:
            /* code */ res.first.first--;
            break;
                case 4:
            /* code */ res.first.second++;
            break;
        }
    }
    else if (x==1){
        res.second=dir;
        switch (dir)
        {
        case 1:
            /* code */ res.first.first++;
            break;
        case 2:
            /* code */ res.first.second--;
            break;
                case 3:
            /* code */ res.first.first--;
            break;
                case 4:
            /* code */ res.first.second++;
            break;
        }
    }
    else{

    }
}

void solve(){
    int h,w;
    cin>>h>>w;
    vector<string> grid(h);
    rep(i,0,h){
        cin>>grid[i];
    }
    priority_queue<pair<int, pair<int, pii>>, vector<pair<int, pair<int, pii>>>, greater<pair<int, pair<int, pii>>>> q;
    pair<int, pair<int, pii>> p0;
    p0.first=0;
    p0.second.first=1;
    p0.second.second={0,0};
    vvb vu(h, vb(w));
    vu[0][0]=true;
    while(q.empty()){
        auto [t, tmp]=q.top();
        q.pop();
        auto [x,y]=tmp.second;
        int dir=tmp.first;
        if (x==h-1 && y==w-1){
            cout<<t<<"\n";
            return;
        }
        vu[h-1][w-1]=true;
        auto [x2,y2]=dirNaturelle(dir, grid[x][y]);
        if (!vu[x2.first][x2.second]){
            pair<int, pair<int, pii>> p1;
            p1.first=t;
            p1.second.first=y2;
            p1.second.second=x2;
            q.push(p1);
        }
        for (auto [x2, y2] : dirChange(dir, grid[x][y])){
            pair<int, pair<int, pii>> p1;
            p1.first=t+1;
            p1.second.first=y2;
            p1.second.second=x2;
            q.push(p1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}