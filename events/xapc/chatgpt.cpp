#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;

long long modexp(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // We need up to m + 1 because of C(m - a + 1, a)
    int MAX = m + 1;

    vector<long long> fact(MAX + 1), invfact(MAX + 1);

    fact[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invfact[MAX] = modexp(fact[MAX], MOD - 2);
    for (int i = MAX - 1; i >= 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }

    auto C = [&](int N, int K) -> long long {
        if (K < 0 || K > N) return 0;
        return fact[N] * invfact[K] % MOD * invfact[N - K] % MOD;
    };

    long long ans = 1;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a > (m + 1) / 2) {
            cout << 0 << '\n';
            return 0;
        }

        ans = ans * C(m - a + 1, a) % MOD;
    }

    cout << ans << '\n';
    return 0;
}