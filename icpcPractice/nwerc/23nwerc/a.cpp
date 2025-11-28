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
    ll n,s;
    cin>>n>>s; // s sockets of width 3
    vl tab(n);
    input(tab);
    sort(all(tab));
    int posCur=3;
    int OnestoComplete=0;
    int TwostoComplete=0;
    int i=0;
    int tot=1;
    n--;
    while(posCur<=3*s-3 && i<n){
        while(posCur<=3*s-3 && i<n){
            int reste=tab[i]%3;
            if (reste==0){
                posCur+=tab[i];
                tot++;
            }
            else if (reste==1){
                if (TwostoComplete){
                    TwostoComplete--;
                    posCur-=3;
                }
                else{
                    OnestoComplete++;
                }
                tot++;
                posCur+=tab[i];            
            }
            else{
                if (OnestoComplete){
                    OnestoComplete--;
                    posCur-=3;
                }
                else{
                    TwostoComplete++;
                }
                tot++;
                posCur+=tab[i];
            }
            i++;
            int reste2=posCur%3;
            if (reste2) posCur+=3-reste2;
        }
        if (OnestoComplete>=2){
            posCur-=3;
            OnestoComplete-=2;
        }
    }
    // on peut tout translater de 1
    cout<<tot;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}