class Combination {

    int N;
    int* fact;
    int* ifact;
    int md;

public:
    Combination(int n, int M = 1e9 + 7) {
        N = n;
        fact = new int[N + 1];
        ifact = new int[N + 1];
        md = M;
        init();
    }
    int local_power(int a, int b, int md) {
        int res = 1;
        while (b) {
            if (b & 1)
                res = (res * 1LL * a) % md;
            a = (a * 1LL * a) % md;
            b >>= 1;
        }
        return res;
    }
    void init() {
        fact[0] = 1;
        ifact[0] = 1;
        for (int i = 1; i <= N; ++i) {
            fact[i] = i * fact[i - 1] % md;
            ifact[i] = local_power(fact[i], md - 2, md);
        }
    }
    int ncr(int n, int r) {
        if (r > n)
            return 0;
        if (r == 0 || r == n)
            return 1;
        return (fact[n] * ifact[n - r] % md) * ifact[r] % md;
    }

} NCR(MX, MD);
