#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<1<<n;i++){
        int tmp=i^(i>>1);
        for (int j=0;j<n;j++){
            cout<<((tmp>>(n-1-j))&1);
        }
        cout<<endl;
    }
}