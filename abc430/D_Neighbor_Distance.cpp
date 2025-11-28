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
    int n=get();
    vl tab(n);
    input(tab);
    ll sum=0;
    set<pair<ll,int>> cur;
    cur.insert({0,-1});
    map<int, ll> closestDistance; //-1, ..., n-1
    cur.insert({tab[0], 0});
    sum+=2ll*tab[0];
    closestDistance[-1]=tab[0];
    closestDistance[0]=tab[0];
    cout<<sum<<"\n";
    rep(i,1,n){
        auto it=cur.lower_bound({tab[i], 0});
        ll mini=INT64_MAX;
        if (it!=cur.end()){
            mini=min(mini, (*it).first-tab[i]);
            sum-=closestDistance[(*it).second];
            closestDistance[(*it).second]=min(closestDistance[(*it).second], (*it).first-tab[i]);
            sum+=closestDistance[(*it).second];
        }
        if (it!=cur.begin()){ // On a quelqu'un avant (garanti)
            it--;
            mini=min(mini, tab[i]-(*it).first);
            sum-=closestDistance[(*it).second];
            closestDistance[(*it).second]=min(closestDistance[(*it).second], tab[i]-(*it).first);
            sum+=closestDistance[(*it).second];
        }
        cur.insert({tab[i], i});
        closestDistance[i]=mini;
        sum+=mini;
        cout<<sum<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}