#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int m;
    cin>>m;
    vl a(n);
    for (auto& x : a) cin>>x;
    vl b(m);
    for (auto& x : b) cin>>x;
    unordered_map<ll,int> h;
    for (auto x : a){
        h[x]++;
    }
    for (auto x : b){
        h[x]--;
    }
    for (auto x : a){
        if (h[x]>0){
            cout << x << " ";
            h[x]--;
        }
    }
}