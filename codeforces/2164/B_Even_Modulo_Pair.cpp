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
    vi pairs;
    vi aaa;
    rep(i,0,n){
        if ((tab[i]%2)==0){
            pairs.push_back(i);
        }
        else aaa.push_back(i);
    }
    if (pairs.size()>=2){
        cout<<tab[pairs[0]]<<" "<<tab[pairs[1]]<<"\n";
        return;
    }
    for (auto i : pairs){
        rep(j,0,i){
            if (((tab[i]%tab[j])%2)==0){
                cout<<tab[j]<<" "<<tab[i]<<"\n";
                return;
            }
        }
    }

    // Il ne reste plus que des elts impairs
    rep(i,0,n-1){
        if (((tab[i+1]%tab[i])%2)==0){
            cout<<tab[i]<<" "<<tab[i+1]<<"\n";
            return;
        }
    }
    rep(i,0,n){
        rep(j,i+1,n){
            if (((tab[j]%tab[i])%2)==0){
                cout<<tab[i]<<" "<<tab[j]<<"\n";
                return;
            }
        }
    }
    cout<<"-1"<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}