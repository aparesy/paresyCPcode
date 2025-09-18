#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (ll i=1;i<=n;i++){
        if (i==1) cout<<0;
        else if (i==2) cout << 6;
        else if (i==3) cout<<28;
        else cout<<i*i*(i*i-1LL)/2LL-((i-2)*(4+6+(i-4)*4)+2+2+(i-4)*2);
        cout<<endl;
    }
}