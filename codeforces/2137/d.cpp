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
    vi b(n);
    input(b);
    unordered_map<int,int> compt; 
    rep(i,0,n){
        if (compt.find(b[i])==compt.end()){
            compt[b[i]]=1;
        }
        else{
            compt[b[i]]++;
        }
    }
    int cur=1;
    unordered_map<int,int> assignation;
    for (auto [cle, val] : compt){
        if (val%cle){
            cout<<-1<<"\n";
            return;
        }
        int tot=0;
     //   cout<<cle<<" "<<val<<" "<<cur;
        assignation[cle]=cur;

        cur+=(val/cle);
    }
//    cout<<"\n";
    unordered_map<int,int> compt2;
    rep(i,0,n){
        cout<<assignation[b[i]]<<" ";
        compt2[b[i]]++;
        if (compt2[b[i]]==b[i]){
            assignation[b[i]]++;
            compt2[b[i]]=0;
        }
    }


    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}