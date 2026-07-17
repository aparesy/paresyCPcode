#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = opt<int>("n",100000);
    int m = rnd.next(1, 100000);

    cout << n << " " << m << "\n";

    for (int i = 0; i < n; i++) {
        int ai = rnd.next(0, m);
        cout << ai << "\n";
    }

    return 0;
}