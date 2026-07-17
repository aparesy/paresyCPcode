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
    ll n,k;
    cin>>n>>k;
    vl tabA(n);
    input(tabA);
    vl tabH(n);
    input(tabH);
    // sliding window, keep curAval, keep gcd? no n cubed
    // strong condition on h, foreach h, check the max previous while divisible, continue while sum less than k. Two pointers
    int j=0; // pointer to move
    int i=0;
    int curA=tabA[0];
    int curL=1;
    int maxL=1;
    while (j<n-1){
        j++;
        if ((tabH[j-1]%tabH[j])==0){
            // is divisible
            curL++;
            curA+=tabA[j];
            while(curA>k){ // Normally i shouldnt exceed j+1
                curL--;
                curA-=tabA[i];
                i++;
            }
            maxL=max(maxL, curL);
        }
        else{
            curL=1;
            curA=tabA[j];
            i=j;
        }
    }
    if (*min_element(all(tabA))>k){
        cout<<0<<"\n";
    }
    else cout<<maxL<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=get();
    rep(i,0,t)
    solve();
}