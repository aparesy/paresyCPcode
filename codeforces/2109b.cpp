#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    int t;
    cin >> t;
    while (t--){
        ll n,m,a,b;
        cin>>n>>m>>a>>b;
        a--;b--;
        if (max(n,m)==1) cout << 0;
        else{
            ll coutA1 = ceil(log2(min(n-1-a,a)+1));
            ll coutA2 = ceil(log2(n));
            ll coutB1 = ceil(log2(min(m-1-b,b)+1));
            ll coutB2 = ceil(log2(m));
      //      cout << coutA1 << " " << coutA2<<endl;
            cout << min(coutA1+coutB2, coutA2+coutB1)+1;
        }
        cout << endl;
    }
}