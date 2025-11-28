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

void update(int& nbCur, pii& cur, int i){
                    nbCur++;
                if (nbCur==1){
                    cur.first=i;
                }
                if (nbCur==2){
                    cur.second=i;
                }
}

void solve(){
    int c,d;
    cin>>c>>d;
    int nbFizz=0;
    int nbBuzz=0;
    pii fizzpos;
    pii buzzpos;
    rep(i,c,d+1){
        string s;
        cin>>s;
        if (s[0]=='F'){
            if (s.length()==4){
                update(nbFizz,fizzpos,i);
            }
            else{
                update(nbFizz,fizzpos,i);
                update(nbBuzz,buzzpos,i);
            }
        }
        else if (s[0]=='B'){
            update(nbBuzz,buzzpos,i);
        }
    }
    if (nbFizz>=2){
        cout<<fizzpos.second-fizzpos.first<<" ";
    }
    else{
        if (nbFizz==1){
            cout<<fizzpos.first<<" ";
        }
        else{
            cout<<d+1<<" ";
        }
    }

    if (nbBuzz>=2){
        cout<<buzzpos.second-buzzpos.first<<" ";
    }
    else{
        if (nbBuzz==1){
            cout<<buzzpos.first<<" ";
        }
        else{
            cout<<d+1<<" ";
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}