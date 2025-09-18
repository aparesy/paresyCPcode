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
    double k1,k2;
    cin>>k1>>k2;
    double epsilon=1e-9;
    double m,n;
    cin>>m>>n;
    double tot=0.;
    tot+=100.*100.*k1/m;
    tot+=((100.*100.*k2/((int)n/(int)m))*((double)(((int)(-n)%(int)m)+(((int)m)-1)%(int)m)+1.))/(m*m); 
    tot+= (((100.*100.*k2)/(((int)n/(int)m)+1.))*((double)((int)n%(int)m)))/(m*m);

    double tot2=0.;
    double ratio = (int)n/(int)m;
    double bigArea = (double)(ratio*ratio) * (100.*100.*k1/n);
    double smallArea = (double) ((ratio-1)*(ratio-1)) * (100.*100.*k1/n);
    tot2+=100.*100.*k2/n; 
    int nbSmall = (int)n%(int)m; 
    tot2+= ((double)nbSmall)*smallArea; 
    int nbBig = (n-(nbSmall))/m;
    tot2+=((double)nbBig)*bigArea; 

    cout<<fixed<<setprecision(3)<<min(tot,tot2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}