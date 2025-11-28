// Useful functions : nth_element, rotate, unique, merge, count, generate

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
using ll=uint64_t;
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

ll subsequenceSum[61][300001];

void solve(){
    int n=get(); // n<=60 2^{n/2} doesnt pass, maybe try to split in two, for each subset sum, compute the amount of others that 
    vl tab(n);
    input(tab);
    sort(all(tab), greater<ll>());
    ll tot=accumulate(all(tab), 0ll);
    rep(j,0,tot/2+1){
        subsequenceSum[0][j]=0;
    }
    subsequenceSum[0][0]=1;
    subsequenceSum[0][tab[0]]=1;
    rep(i,1,n){
        rep(j,0,tot/2+1){
            subsequenceSum[i][j]=subsequenceSum[i-1][j];
            if (j>=tab[i]) subsequenceSum[i][j]+=subsequenceSum[i-1][j-tab[i]];
        }
    }

    ll tmp=0;
    rep(i,0,n-1){
        rep(j,tot/2+1-tab[i+1], tot/2+1){
            tmp+=subsequenceSum[i][j];
        }
    }

    if (tab[0]>=tot/2+1) tmp++;
    cout<<tmp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}