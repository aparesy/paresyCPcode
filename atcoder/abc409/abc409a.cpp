#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

int main(){
    int n;
    string t,a;
    cin>>n;
    cin>>t;
    cin>>a;
    bool ok=false;
    for (int i=0;i<n;i++){
        if (a[i]=='o' && t[i]=='o'){
            ok=true;
        }
    }
    if (ok)cout<<"Yes\n";
    else cout<<"No\n";
}