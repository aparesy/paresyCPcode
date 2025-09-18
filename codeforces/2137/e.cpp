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

int mexify(int n, vi& tab, bool& avantRes){
    vi present(n+1);
    for (auto x : tab){
        if (x<=n){
            present[x]++;
        }
    }
    int minAbsent=n;
    for(int i=0; i<n && minAbsent==n;i++){
        if (present[i]==0){
            minAbsent=i;
        }
        if (present[i]>=2){
            avantRes=true;
        }
    }
    for (int i=0;i<n;i++){
        if (present[tab[i]]>1 || tab[i]>=minAbsent){
            tab[i]=minAbsent;
        }
    }
    return minAbsent;
}

void solve(){
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    vi tab(n);
    input(tab);
    bool avantRes=false;
    if (k==1){
        mexify(n,tab,avantRes);
        cout<<accumulate(tab.begin(),tab.end(),0LL)<<"\n";
        return;
    }

    int resultMexify=mexify(n,tab,avantRes);
 //   cout<< resultMexify<<"test\n";
    k--;
    if (!avantRes){
        if (resultMexify==n){
            cout<<n*(n-1LL)/2LL<<"\n";
            return;
        }
        if (resultMexify==n-1){
            cout<<resultMexify*(resultMexify+1LL)/2LL<<"\n";
            return;
        }
        cout<<max(0LL,resultMexify*(resultMexify-1LL)/2LL) + ((k%2)?(resultMexify+1LL):resultMexify)*(n-resultMexify)<<"\n";
        return;
    }
    
    resultMexify=mexify(n,tab,avantRes);
    k--;
    if (resultMexify==n){
        cout<<n*(n-1LL)/2LL<<"\n";
        return;
    }
    cout<<max(0LL,resultMexify*(resultMexify-1LL)/2LL) + ((k%2)?(resultMexify+1LL):resultMexify)*(n-resultMexify)<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}