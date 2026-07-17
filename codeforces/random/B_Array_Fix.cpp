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

bool croissant(int n){
    int lastD=9;
    while(n){
        if (n%10 > lastD) return false;
        else{
            lastD=n%10;
            n/=10;
        }
    }
    return true;
}

vi digitDec(int n){
    vi tab;
    if (n==0) return{0};
    while(n){
        tab.push_back(n%10);
        n/=10;

}   reverse(all(tab));
 return tab;
}

bool solve(){
    int n;
    cin>>n;
    vi tab(n);
    input(tab);
    vvi tab2(n);
    rep(i,0,n){
        tab2[i]=digitDec(tab[i]);
    }
    bool lastDec=(croissant(tab[0]));
    rep(i,1,n){
        if (lastDec){
            int compa=tab[i-1]%10;
            if (tab2[i][0]>=compa) lastDec=croissant(tab[i]);
            else if(tab[i]>=compa) lastDec=false;
            else return false;
        }
        else{
            if (tab[i]<tab[i-1]) return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    {if (solve()) cout<<"YES\n"; else cout<<"NO\n";}
}