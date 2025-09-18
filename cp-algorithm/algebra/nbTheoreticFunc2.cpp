#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1LL)
        result -= result / n;
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    while (n>0){
        cout<<phi(n)<<endl;
        cin>>n;
    }
}