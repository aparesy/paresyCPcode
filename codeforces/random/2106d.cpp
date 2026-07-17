#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool passage(vector<int>& a, vector<int>& b, int n, int m, int joker){
    bool utilise = false;
    int i=n-1;
    int j=m-1;
    while (i<n && j<m){
        if (b[j]<=a[i]){
            j++;
        }
        else if (b[j]==joker && !utilise){
            utilise=true;
            j++;
        }
    }
}

int main(){
    int t; 
    cin >> t;
    while (t--){
        int n,m;
        cin  >>n>>m;
        int dp[n][m];
        vector<ll> a(n);
        vector<ll> b(m);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
        vector<int> dp0(m);
        int cur=0;
        for (int i=0;cur<m && i<n;i++){
            if (a[i]>=b[cur]){
                dp0[cur]=i;
                cur++;
            }
        }
        while (cur<m){
            dp0[cur]=-1;
            cur++;
        }
    }
}