#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 100000, "t");
    inf.readEoln();

    for (int i = 0; i < t; i++) {
        inf.readLong(1, (long long)1e18, "n");
        inf.readEoln();
    }

    inf.readEof();
}