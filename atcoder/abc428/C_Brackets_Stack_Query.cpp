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

pii cnt[(int)1e6];
bool ok[(int)1e6];

void solve(){
    ll q;
    cin>>q;
    ll i=0;
    rep(tmp,0,q){
        int x;
        cin>>x;
        if (i==0 || ok[i-1]) ok[i]=true; else ok[i]=false;
        if (x==1){
            char c;
            cin>>c;
            if (c=='('){
                cnt[i].first++;
                if (cnt[i].second>cnt[i].first) ok[i]=false;
                i++;
                cnt[i]=cnt[i-1];
                cout<<"No\n";
            }
            else{
                cnt[i].second++;
                if (cnt[i].second>cnt[i].first) ok[i]=false;
                i++;
                cnt[i]=cnt[i-1];
                if (cnt[i].first==cnt[i].second && ok[i-1]){
                    cout<<"Yes\n";
                }
                else{
                    cout<<"No\n";
                }
            }
        }
        else{
            i--;
            if (i==0){
                cnt[i]={0,0};
                ok[i]=true;
            }
            else{
                cnt[i]=cnt[i-1];
                ok[i]=ok[i-1];
            }
            if (i==0 || cnt[i].first==cnt[i].second && ok[i]){
                cout<<"Yes\n";
            }
            else cout<<"No\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}