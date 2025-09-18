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

int nbChemins(vector<vector<bool>>& vu, pii& pos, string s, int n){
    if (n==48 && pos.F==6 && pos.S==0) return 1;
    if (s[n]!='?'){
        switch (s[n])
        {
        case 'U':
            if (pos.F>0 && !vu[pos.first-1][pos.second]){
                vu[pos.first-1][pos.second]=true;
            }
            break;
        case 'R':
            break;
        case 'L':
            break;
        default:
            break;
        }
    }
}

void solve(){
    string s;
    cin>>s;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}