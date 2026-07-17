#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 100000, "n");
    inf.readSpace();
    int m = inf.readInt(1, 100000, "m");
    inf.readEoln();

    for (int i = 0; i < n; i++) {
        inf.readInt(0, m, "a_i");
        inf.readEoln();
    }

    inf.readEof();
}