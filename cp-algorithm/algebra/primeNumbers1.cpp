#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

ll count_primes(ll n) {
    const int S = 10000;

    vector<ll> primes;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 2, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    int result = 0;
    vector<char> block(S);
    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primes) {
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i]){
                if (result%100==0){
                    cout<<i+S*k<<"\n";
                }
                result++;
            }
        }
    }
    return result;
}

int main(){
    ll n = 1e8;
    count_primes(n);
}