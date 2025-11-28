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

int req(vi& tab, int n){
    cout<<"? "<<n<<" ";
    rep(i,0,tab.size()){
        if (tab[i]){
            cout<<i<<" ";
        }
    }
    cout.flush();
    int x;
    cin>>x;
    return x;
}

void solve(){
    int n;
    cin>>n;
    int i=1;
    vi unique_first(2*n+1);
    vi ans(2*n+1);
    int tot=0;
    while(i<=2*n){
        unique_first[i]=1;
        tot++;
        int x=req(unique_first, tot);
        if (x){
            unique_first[i]=0; // i is the sec elt of a couple
            tot--;
            ans[i]=x;
        }
        i++;
    }
    // now unique_first is built
    rep(i,1,2*n+1){
        unique_first[i]=1-unique_first[i];
    }
    unique_first[0]=0;
    rep(i,1,2*n+1){
        if (!unique_first[i]){
            unique_first[i]=1;
            int x=req(unique_first,n+1);
       //     auto ind=find(all(ans),x);
            ans[i]=x;
            unique_first[i]=0;
        }
    }
    cout<<"! ";
    rep(i,1,2*n+1){
        cout<<ans[i]<<" ";
    }
    cout.flush();
}

int main(){

    int t; cin>>t; rep(i,0,t){
    solve();}
}