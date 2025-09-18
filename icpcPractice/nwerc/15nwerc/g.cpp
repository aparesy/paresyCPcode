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


int nbInv(vi& perm, int i, int j){
    int n=j-i;
    if (n<=1) return 0;
    if (n==2) return perm[j]>perm[i];
    int m=(j-i)/2;
    pii tmp={0,0};
    int parite=0;
    n/=2;
    while (tmp.first<n && tmp.second<n){
        if (parite){
            while (tmp.second<n && perm[m+])
        }
    }
    return nbInv(perm, i,m)+nbInv(perm, m,j)+tot;
}

void solve(){
    int n;
    cin>>n;
    vi tab1(n);
    input(tab1);
    vi tab2(n);
    input(tab2);
    vi tab3(n);
    input(tab3);    
    cout<<dnc(tab1,tab2,tab3,0,n);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}