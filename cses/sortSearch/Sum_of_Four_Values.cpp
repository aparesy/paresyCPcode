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
    // Find all pairwise sums, resort and two pointers
    ll n,x;
    cin>>n>>x;
    vector<ll> tab(n);
    input(tab);
    vector<pair<ll,pii>> tab2;
    rep(i,0,n){
        rep(j,i+1,n){
            tab2.push_back({tab[i]+tab[j],make_pair(i,j)});
        }
    }
    sort(all(tab2));
    int i=0;
    int j=tab2.size()-1;
    while(i<j){
        if (tab2[i].first+tab2[j].first<x){
            i++;
        }
        else if (tab2[i].first+tab2[j].first>x){
            j--;
        }
        else{
            if (tab2[i].second.first==tab2[j].second.first || tab2[i].second.first==tab2[j].second.second
                || tab2[i].second.second==tab2[j].second.first || tab2[i].second.second==tab2[j].second.second){
                    if (tab2[i].first==tab2[i+1].first) i++;
                    else j--;
                }
            else{
                cout<<tab2[i].second.first+1<<" "<<tab2[i].second.second+1<<" "<<tab2[j].second.first+1<<" "<<tab2[j].second.second+1;
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}