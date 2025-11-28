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
    sort(all(tab));
    n--;
    int i=n/2;
    int j=n/2+1;
    n++;
    while(i>=0){
        cout<<tab[i]<<" ";
        if (j<n){
            cout<<tab[j]<<" ";
            j++;
        }
        i--;
    }
            if (j<n){
            cout<<tab[j]<<" ";
            j++;
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}