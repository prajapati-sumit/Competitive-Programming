#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int testCount = inf.readInt(1, 100000, "testCount");
    inf.readEoln();
    int tot = 2e5;

    for (int i = 0; i < testCount; i++) {
        int mx = tot - (testCount - i - 1);
        if (mx > 100000)mx = 100000;
        int n = inf.readInt(1, mx, "n");
        inf.readSpace();
        int k = inf.readInt(1, 40, "k");
        tot -= n;
        inf.readEoln();
    }

    inf.readEof();
}