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

double minSeq(vector<ll>& tab){
    // Given an array of points, returns the minimal distance of an increasing sequence to it
    int n=tab.size();
    vector<pair<double,int>> metaArray;
    metaArray.push_back({tab[0],1});
    vector<ll> cumTab(n+1);
    rep(i,1,n+1){
        cumTab[i]=cumTab[i-1]+tab[i-1];
    }
    rep(i,1,n){
        metaArray.push_back({tab[i],1});
        while (metaArray.size()>=2 && metaArray[metaArray.size()-1].first < metaArray[metaArray.size()-2].first){
            auto last1 = metaArray[metaArray.size()-1];
            auto last2=metaArray[metaArray.size()-2];
            metaArray.pop_back();
            metaArray.pop_back();
            metaArray.push_back({((double)((last1.first*((double)last1.second)))+((double)(last2.first*((double)last2.second))))/((double)(last1.second+last2.second)),last1.second+last2.second});
        }
    }
    double tot=0;
    int i=0;
    for (auto [x,size] : metaArray){
        rep(j,0,size){
            tot+=((double)(tab[i])-x)*((double)(tab[i])-x);
            i++;
        }
    }
    return tot;
}

void solve(){
    int n=get();
    vector<pair<ll,ll>> points(n);
    rep(i,0,n){
        cin>>points[i].first>>points[i].second;
    }
    vector<ll> xcord(n);
    vector<ll> ycord(n);
    rep(i,0,n){
        xcord[i]=points[i].first;
        ycord[i]=points[i].second;
    }
    cout<<fixed<<setprecision(7)<<minSeq(xcord)+minSeq(ycord);
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}