#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    cout<<2<<endl;
    for (int i=0;i<n;i++){
        cout << i+1<<" ";
    }
    cout<<endl;
    for (int i=0;i<n;i++){
        cout<<n-i<<" ";
    }
}