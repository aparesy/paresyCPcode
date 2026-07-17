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
    string s;
    cin>>s; // s de taille n-1
    int tot=1;
    rep(i,0,n-1){
        // Comment gagner ? Il faut et il suffit, étant donné k 0 et n-k 1, que le bord gauche soit supprimable (i.e. nb de 0 >=1)
        // et que le bord droit aussi (réciproquement)
        // Gagner pour un mec en bord : Finir par un 0 ou un 1
        if (i==0){
            cout<<1<<" ";
        }
        else{
            if (s[i-1]==s[i]) tot++;
            else tot=1;
            cout<<i-tot+2<<" ";
        }
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}