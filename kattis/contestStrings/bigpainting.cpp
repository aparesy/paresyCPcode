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

ll mod=1e9+7ll;
ll p1=37ll;
ll p2=41ll;

void solve(){
    int h1,w1,h2,w2;
    cin>>h1>>w1>>h2>>w2;
    vvi original(h1, vi(w1));
    rep(i,0,h1){
        string s;
        cin>>s;
        rep(j,0,w1){
            original[i][j]=(s[j]=='x')+1;
        }
    }
    vvi entier(h2, vi(w2));
    rep(i,0,h2){
        string s;
        cin>>s;
        rep(j,0,w2){
            entier[i][j]=(s[j]=='x')+1;
        }
    }
    ll hashOriginal=0ll;
    ll pRow=1;
    rep(i,0,h1){
        pRow*=p1;
        pRow%=mod;
        ll pCol=1;
        rep(j,0,w1){
            pCol*=p2;
            pCol%=mod;
            ll hashHere=pRow*pCol;
            hashHere%=mod;
            hashHere*=original[i][j];
            hashHere%=mod;
     //       cout<<hashHere<<" ";
            hashOriginal+=hashHere;
            hashOriginal%=mod;
        }
//        cout<<"\n";
    }

    vector<vl> EntierHash(h2, vl(w2));
    pRow=1;
    rep(i,0,h2){
        pRow*=p1;
        pRow%=mod;
        ll pCol=1;
        rep(j,0,w2){
            pCol*=p2;
            pCol%=mod;
            ll tmp=pRow*pCol;
            tmp%=mod;
            tmp*=entier[i][j];
            tmp%=mod;
      //      cout<<tmp<<" ";
            EntierHash[i][j]=tmp;
        }
        //cout<<"\n";
    }

    vector<vl> CumSumHash(h2, vl(w2));
    rep(i,0,h2){
        ll curLigne=0;
        rep(j,0,w2){
            curLigne+=EntierHash[i][j];
            curLigne%=mod;
            CumSumHash[i][j]=curLigne;
            if (i){
                CumSumHash[i][j]+=CumSumHash[i-1][j];
                CumSumHash[i][j]%=mod;
            }
        }
    }

    int tot=0;
    pRow=1;
    rep(i,0,h2-h1+1){
        ll pCol=1;
        rep(j,0,w2-w1+1){
            ll originalSide=hashOriginal*pRow;
            originalSide%=mod;
            originalSide*=pCol;
            originalSide%=mod;
            ll EntierSide=CumSumHash[i+h1-1][j+w1-1];
            if (i){
                EntierSide-=CumSumHash[i-1][j+w1-1];
            }
            if (j){
                EntierSide-=CumSumHash[i+h1-1][j-1];
            }
            if (i&&j){
                EntierSide+=CumSumHash[i-1][j-1];
            }
            EntierSide=((EntierSide%mod)+mod)%mod;
            if (EntierSide==originalSide) tot++;
            pCol*=p2;
            pCol%=mod;
        }
        pRow*=p1;
        pRow%=mod;
    }

    cout<<tot;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}