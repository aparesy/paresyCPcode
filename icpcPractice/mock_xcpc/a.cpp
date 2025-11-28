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
    int n,m;
    cin>>n>>m;
    vector<vb> grid(n,vb(m));
    rep(i,0,n){
        string s;
        cin>>s;
        rep(j,0,m){
            if (s[j]=='.') grid[i][j]=true;
        }
    }
    vector<vector<int>> lig(n);
    vector<vector<int>> col(m);
    rep(i,0,n){
        rep(j,0,m){
            if (grid[i][j]){
                lig[i].push_back(j);
                col[j].push_back(i);
            }
        }
    }

    //pr chaque case, compute amount of horiz and vert where the second ends on that case
    vector<vector<pair<ll,ll>>> amnt2(n,vector<pair<ll,ll>>(m));
    rep(i,0,n){
        rep(j,0,m){
            amnt2[i][j].first=lig[i].size()-1;
            amnt2[i][j].second=col[j].size()-1;
        }
    }
    vl sumAmnt2Lig(n);
    vl sumAmnt2Col(m);
    rep(i,0,n){
        rep(j,0,m){
            if (grid[i][j]){
                sumAmnt2Lig[i]+=amnt2[i][j].second;
                sumAmnt2Col[j]+=amnt2[i][j].first;
            }
        }
    }

    //nb de quadruplets : nb de paires de paires
    ll tot=0;
    rep(i,0,n){
        ll x=lig[i].size();
        if (x>=4){
            tot+=x*(x-1ll)*(x-2ll)*(x-3ll);
        }

        if (x>=3){
            rep(j,0,m){
                if (grid[i][j]){
                    tot+=2ll*(x-1ll)*(x-2ll)*(col[j].size()-1ll);
                }
            }
        }

        if (x>=2){
            tot+=sumAmnt2Lig[i]*(sumAmnt2Lig[i]-1ll);
            rep(j,0,m){
                if (grid[i][j]) tot-=amnt2[i][j].second*(amnt2[i][j].second-1ll);
            }
        }
    }
    rep(j,0,m){
        ll x=col[j].size();
        if (x>=4){
            tot+=x*(x-1ll)*(x-2ll)*(x-3ll);
        }

        if (x>=3){
            rep(i,0,n){
                if (grid[i][j]){
                    tot+=2ll*(x-1ll)*(x-2ll)*(lig[i].size()-1ll);
                }
            }
        }

        if (x>=2){
            tot+=sumAmnt2Col[j]*(sumAmnt2Col[j]-1ll);
            rep(i,0,n){
                if (grid[i][j]) tot-=amnt2[i][j].first*(amnt2[i][j].first-1ll);
            }
        }
    }
    cout<<tot<<"\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}