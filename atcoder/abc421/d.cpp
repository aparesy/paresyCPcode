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

void updatePos(ll& x, ll& y, char dir, ll num){
    switch(dir){
        case 'U' : y-=num;
        case 'D' : y+=num;
        case 'L' : x-=num;
        case 'R' : x+=num;
    };
}

void solve(){
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    ll n,m,l;
    cin>>n>>m>>l;
    deque<pair<char,ll>> moves1;
    rep(i,0,m){
        char a; ll b;
        cin>>a>>b;
        moves1.push_back({a,b});
    }
    deque<pair<char,ll>> moves2;
    rep(i,0,l){
        char a; ll b;
        cin>>a>>b;
        moves2.push_back({a,b});
    }
    int i=0;
    int j=0;

    ll tot=0LL;
    while (i<m && j<l){
        auto [dir1,num1]=moves1.front();
        moves1.pop_front();
        auto [dir2,num2]=moves2.front();
        moves2.pop_front();
        ll x=min(num1,num2);
        if (x==num1){
            moves2.push_front({dir2,num2-num1});
            i++;
        }
        else{
            moves1.push_front({dir1,num1-num2});
            j++;
        }
        set<char> s;
        s.insert(dir1);
        s.insert(dir2);

        if (s.size()==1){
            if (x1==x2 && y1==y2){
                tot+=x;
            }
        }
        else{
            switch (dir1)
            {
            case 'U':
                switch(dir2){
                    case 'D': if (x1==x2 && y1<=y2 && y1-y2<=2*x && (y1-y2)%2==0) tot++;
                    case 'L' : if ()
                }
            
            default:
                break;
            }
        }
        updatePos(x1,y1,dir1,num1);
        updatePos(x2,y2,dir2,num2);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}