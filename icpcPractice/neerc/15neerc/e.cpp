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
    int n,k;
    cin>>n>>k;
    vi ind(n);
    int selected=0;
    int vu=0;
    vb vus(n);
    vvi problems(n);
    rep(i,0,n){
        int s;
        cin>>s;
        problems[i].resize(s);
        input(problems[i]);
    }
    int tot=0;
    int juge=0;
    while(vu<n && selected<k){
        if (ind[juge] < problems[juge].size()){
            if (problems[juge][ind[juge]]>=tot){
                tot+=problems[juge][ind[juge]];
                selected++;
            }
            ind[juge]++;
        }
        else{
            if (tot<=50){
                tot+=50;
                selected++;
            }
            if (!vus[juge]){
                vus[juge]=true;
                vu++;
            }
        }
        juge++;
        if (juge==n) juge=0;
    }
    cout<<tot+50*(k-selected);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("easy.in", "r", stdin);
    freopen("easy.out", "w", stdout);
    solve();
}