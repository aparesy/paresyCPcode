#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,a,b;
    string s;
    cin>>n>>a>>b;
    cin>>s;
    for (int i=a;i<n-b;i++){
        cout<<s[i];
    }
}