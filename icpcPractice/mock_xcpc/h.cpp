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

int queryMult(int n){
    cout<<"multi "<<n<<"\n"<<flush;
    int x;
    cin>>x; 
    return x;
}

int queryType(int n){
    cout<<"type "<<n<<"\n"<<flush;
    string y;
    cin>>y;
    if (y[0]=='l') return 0;
    else return 1;
}

pair<int,int> doubleQueryL(int n){
    // mult at the left of n and type
    int x=queryMult(n-1);
    int y=queryType(n);
    return {x,y};
}

pair<int,int> doubleQueryR(int n){
    // mult at the right of n and type
    int x=queryMult(n);
    int y=queryType(n);
    return {x,y};
}

int solve(){
    int n;
    cin>>n;
    // int tg = queryType(1);
    // if (tg==0){
    //     int nbRose=queryMult(1);
    //     return nbRose;
    // }    
    // int td=queryType(n);
    // if (td==1){
    //     int nbLilas=queryMult(n-1);
    //     return n-nbLilas;
    // }
    //now, guaranteed to have a rose at left and a lilas at right
    int l=1;
    int r=n;
    //invariant : type[l] = rose and type[r] = lilas
    while (r-l>1){
        int m=(l+r)/2;
        int mtype=queryType(m);
        if (mtype==0) r=m;
        else l=m;
    }
    int mult1=queryMult(l-1);
    int mult2=queryMult(l);
    int diff=mult1-mult2;
    if (diff==0){
        if (l!=n){
            int mult3=queryMult(l+1);
            int ri=mult3-mult2;
            return ri+l-1;
        }
        else{
            int mult0=queryMult(l-2);
            int ri=mult0-mult1;
            return ri+l+1;
        }
    }
    return l+(mult2/diff)-diff;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t){
        int s=solve();
        cout<<"answer "<<s<<"\n"<<flush;
    }
}