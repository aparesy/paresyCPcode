#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

ll w[7];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll tmp;
    for (int i=0;i<7;i++){
        cin>>tmp;
        w[i]=tmp;
    }

    //On fait un dp
    // Pour 1 : dp(n+1)=dp(n-1)+dp(n)
    // Garder en mémoire dpn et dpn-1
}