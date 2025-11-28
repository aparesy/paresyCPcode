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
    int n,q;
    cin>>n>>q;
    vl totCapacity(n);
    input(totCapacity);
    vl filling(n);
    vi pointsTo(n,-1);
    set<pair<ll,int>> toProcess;
    rep(i,0,n){
        while(toProcess.size() && (*toProcess.begin()).first<totCapacity[i]){
            auto [cap, index] = (*toProcess.begin());
            toProcess.erase(toProcess.begin());
            pointsTo[index]=i;
        }
        toProcess.insert({totCapacity[i],i});
    }

    rep(i,0,q){
        string s;
        cin>>s;
        if (s[0]=='+'){
            ll a,b;
            cin>>a>>b;
            set<int> toProcess;
            int curLevel=a-1;
            while(curLevel!=-1 && filling[curLevel]+b>totCapacity[curLevel]){
                b-=totCapacity[curLevel]-filling[curLevel];
                filling[curLevel]=totCapacity[curLevel];
                toProcess.insert(curLevel);
                curLevel=pointsTo[curLevel];
            }
            if (curLevel!=-1){
                filling[curLevel]+=b;
            }
            for (auto node : toProcess){
                pointsTo[node]=curLevel;
            }
        }
        else{
            int level;
            cin>>level;
            cout<<filling[level-1]<<"\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}