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
    ll n,m,v;
    cin>>n>>m>>v;
    vl tab(n);
    input(tab);

    int nbCreatures=0;
    ll cur=0;
    rep(i,0,n){
        cur+=tab[i];
        if (cur>=v){
            nbCreatures++;
            cur=0;
        }
    }
    if (nbCreatures<m){
        cout<<-1<<"\n";
        return;
    }
    // At index i, if it is taken, whats the the max creatures to the right of it
    vi toTheRight(n);
    nbCreatures=0;
    cur=0;
    for (int i=n-1;i>=0;i--){
        toTheRight[i]=nbCreatures;
        cur+=tab[i];
        if (cur>=v){
            cur=0;
            nbCreatures++;
        }
    }
    ll maxiAlice=0;
    int j=0;
    cur=tab[0];
    while (j<n-1 && toTheRight[j+1]>=m){
        j++;
        cur+=tab[j];
    }
    if (toTheRight[j]>=m) maxiAlice=max(maxiAlice, cur);
    ll curLeft=0;
    int creaturesLeft=m;
    rep(i,1,n){
        curLeft+=tab[i-1];
        cur-=tab[i-1];
        if (curLeft>=v){
            creaturesLeft=max(0, creaturesLeft-1);
            curLeft=0;
        }
        while (j<n-1 && toTheRight[j+1]>=creaturesLeft){
            j++;
            cur+=tab[j];
        }
        if (toTheRight[j]>=creaturesLeft) maxiAlice=max(maxiAlice, cur);
    }
    cout<<maxiAlice<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}