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

ll dista(pair<ll,ll>& p1, pair<ll,ll>& p2, ll signe){ // en 1ere pose les indices
    return ((ll)abs(p1.first-p2.first) + 2LL*signe*(p1.second+p2.second));
}

int largestDistaInd(pair<ll,ll>& p, vector<pair<ll,ll>>& tab, ll signe){
    ll maxi=-100000000000LL;
    int max_i=-1;
    rep(i,0,tab.size()){
        if (dista(p, tab[i],signe)>=maxi){
            maxi=dista(p,tab[i],signe);
            max_i=i;
        }
    }
    return max_i;
}

void solve(){
    int n;
    cin>>n;
    vl tab(n);
    input(tab);
    rep(i,0,n){
        if (i%2) tab[i]=-tab[i];
    }
    ll scoreFirst = accumulate(tab.begin(), tab.end(), 0LL);
    if (n==1){
        cout<<scoreFirst<<"\n";
        return;
    }
    // signe -1 si on fait pair to impair
    vector<pair<ll,ll>> tab1;
    for (int i=0;i<n;i+=2){
        tab1.push_back({i,tab[i]});
    }
    vector<pair<ll,ll>> tab2;
    for (int i=1;i<n;i+=2){
        tab2.push_back({i,tab[i]});
    }
    stack<pair<ll,int>> s;
    s.push({tab2.back().first-2LL*tab2.back().second, tab2.back().first});
    for (int i=tab2.size()-1;i>=0;i--){
        ll tmp=tab2[i].first-2LL*tab2[i].second;
        if (tmp>s.top().first){
            s.push({tmp,tab2[i].first});
        }
    }
    ll maxi=0LL;
    rep(i,0,tab1.size()){
        while(!s.empty() && s.top().second < tab1[i].first){
            s.pop();
        }
        if (!s.empty() && -2LL*tab1[i].second-tab1[i].first + s.top().first > maxi){
            maxi = -2LL*tab1[i].second-tab1[i].first + s.top().first;
        }
    }   

    while (!s.empty()) s.pop();
    s.push({tab1.back().first-2LL*tab1.back().second, tab1.back().first});
    for (int i=tab1.size()-1;i>=0;i--){
        ll tmp=tab1[i].first-2LL*tab1[i].second;
        if (tmp>s.top().first){
            s.push({tmp,tab1[i].first});
        }
    }
    rep(i,0,tab2.size()){
        while(!s.empty() && s.top().second < tab2[i].first){
            s.pop();
        }
        if (!s.empty() && -2LL*tab2[i].second-tab2[i].first + s.top().first > maxi){
            maxi = -2LL*tab2[i].second-tab2[i].first + s.top().first;
        }
    } 
    cout<<scoreFirst+max(((ll)((n%2)?n-1:n-2)), maxi)<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}