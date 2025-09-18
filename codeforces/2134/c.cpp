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
    int n;
    cin>>n;
    vl tab(n);
    input(tab);
    ll tot=0LL;
    if (n==2){
        cout<<max(0LL,tab[0]-tab[1])<<endl;
        return;
    }
    for (int i=1;i+1<n;i+=2){
        if (tab[i-1]>=tab[i]){
            tot+=tab[i+1];
            tab[i+1]=0LL;
            tot+=tab[i-1]-tab[i];
            tab[i-1]=tab[i];
        }
        else if (tab[i-1]+tab[i+1]>tab[i]){
            ll dif=tab[i-1]+tab[i+1]-tab[i];
            tab[i+1]-=dif;
            tot+=dif;
        }
    }
    if ((n-1)%2 && (tab[n-1]<tab[n-2])){
        tot+=tab[n-2]-tab[n-1];
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