#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x

void solve(){
    int n;
    cin>>n;
    vi tab(n,-1);
    int traites=0;
    int curBlock=n-2;
    int targetDeux=1;
    int pasDeuxDeux=0;
    while (curBlock>=0 && !pasDeuxDeux){
        cout<<"throw "<<curBlock+1<<flush;
        int res;
        cin>>res;
        if (res==targetDeux){
            cout<<"swap "<<curBlock+1<<flush;
            tab[curBlock+1]=2;
            cout<<"throw "<<curBlock+1<<flush;
            cin>>res;
            if (res==targetDeux){
                tab[curBlock]=2;
            }
            else tab[curBlock]=1;
        }
        else{
            tab[curBlock]=1;
        }
        if (tab[curBlock]==1){
            pasDeuxDeux=(n-curBlock)/2;
        }
        targetDeux++;
        curBlock-=2;
    }
    while(curBlock>=0){
        cout<<"throw "<<curBlock+2<<flush;
        int res;
        cin>>res;
        int cur=curBlock+1;
        int totDeux=0;
        tab[cur]=2;
        while(tab[cur]!=-1){
            cur+=tab[cur];
            totDeux++;
        }
        if (res!=totDeux+1+pasDeuxDeux){
            cout<<"swap "<<curBlock+1<<flush;
            tab[curBlock+1]=1;
            cout<<"throw "<<curBlock+1<<flush;
            int res;
            cin>>res;
            int cur=curBlock+1;
            int totDeux=0;
            tab[cur]=2;
            while(tab[cur]!=-1){
                cur+=tab[cur];
                totDeux++;
            }
            if (res!=totDeux+1+pasDeuxDeux)
        }
        else{
            tab[curBlock]=1;
            curBlock-=2;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}