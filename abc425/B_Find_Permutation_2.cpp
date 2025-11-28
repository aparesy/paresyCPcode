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
    int n;
    cin>>n;
    vi tab(n);
    input(tab);
    vi count(n+1);
    rep(i,0,n){
        if (tab[i]!=-1){
            count[tab[i]]++;
            if (count[tab[i]]>1){
                cout<<"No\n";
                return;
            }
        }
    }
    cout<<"Yes\n";
    int i=1;
    while(count[i])i++;
    rep(j,0,n){
        if (tab[j]==-1){
            cout<<i<<" ";
            i++;
            while(count[i])i++;
        }
        else cout<<tab[j]<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}   