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
    int n;
    cin>>n;
    // Si n est impair, la somme est congrue à 0, cohérent
    // La permut commence par n. Si on peut faire des compléments à n+1, ok ??
    if (n%2==0){
        cout<<n<<" ";
        int tot=1;
        int mini=1;
        int maxi=n+1;
        for (int i=0;i<n-1;i++){
            if (tot==mini){
                cout<<maxi-mini-1<<" ";
                tot=maxi-1;
                maxi=tot;
            }
            else{
                cout<<mini+n-tot+1<<" ";
                tot=mini+1;
                mini=tot;
            }
        }
        cout<<"\n";
    }
    else{
        if (n==1){
            cout<<1<<"\n";
        }
        else{
            cout<<"-1"<<"\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=get();
    rep(i,0,t)
    solve();
}