#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int t = opt<int>("t", 10000); // number of test cases
    cout << t << '\n';

    for (int i = 0; i < t; i++) {
        long long n = rnd.next(1LL, (long long)1e18);
        cout << n << '\n';
    }

    return 0;
}