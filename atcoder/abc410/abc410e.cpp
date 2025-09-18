#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>
#define gros 3500LL*3500LL

int monstres(ll h, ll m, int i, vl& a, vl& b, int n, unordered_map<ll,int>& dp){
    if (i==n){
        return 0;
    }
    if (dp.find(gros*h+3500LL*m+i) != dp.end()){
        return dp[gros*h+3500LL*m+i];
    }
    else{
        if (m<b[i]){
            if (h<a[i]){
                return 0;
            }
            ll tmp = 1+monstres(h-a[i],m,i+1,a,b,n,dp);
            dp[gros*h+3500LL*m+i] = tmp;
            return tmp;
        }
        if (h<a[i]){
            ll tmp = 1+monstres(h,m-b[i],i+1,a,b,n,dp);
            dp[gros*h+3500LL*m+i] = tmp;
            return tmp;
        }
        ll tmp = 1+max(monstres(h-a[i],m,i+1,a,b,n,dp), monstres(h,m-b[i],i+1,a,b,n,dp));
        dp[gros*h+3500LL*m+i] = tmp;
        return tmp;
    }
}

int main(){
    ll n,h,m;
    cin>>n>>h>>m;
    vl a(n);
    vl b(n);
    ll tmp1,tmp2;
    for (int i=0;i<n;i++){
        cin>>tmp1>>tmp2;
        a[i]=tmp1;
        b[i]=tmp2;
    }
    unordered_map<ll,int> dp;
    cout<<monstres(h,m,0,a,b,n,dp);

}