
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

bool bin_search(int a, vl v, int l, int r){
    if (r<=l) return false;
    int m=r+l;
    m/=2;
    if (v[m]==a) return true;
    if (v[m]>a){
        return bin_search(a, v, l, m);
    }
    return bin_search()
}

int main(){

    int n,k;
    cin>>n>>k;
    vl v(n);
    for (auto& x : v)cin>>x;
    for (int i=0;i<k;i++){
        ll a;
        cin>>a;
        if (bin_search(a, v, 0, n)) cout << "YES\n";
        else cout<<"NO\n";
    }
}
    
