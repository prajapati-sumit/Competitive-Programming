// don't use 'int' as long long
template<const int& MOD>
struct Mint {
    using T = typename decay<decltype(MOD)>::type; T v;
    Mint(int64_t v = 0) { if (v < 0) v = v % MOD + MOD; if (v >= MOD) v %= MOD; this->v = T(v); }
    Mint(uint64_t v) { if (v >= MOD) v %= MOD; this->v = T(v); }
    Mint(int v): Mint(int64_t(v)) {}
    Mint(unsigned v): Mint(uint64_t(v)) {}
    explicit operator int() const { return v; }
    explicit operator int64_t() const { return v; }
    explicit operator uint64_t() const { return v; }
    friend istream& operator>>(istream& in, Mint& m) { int64_t v_; in >> v_; m = Mint(v_); return in; }
    friend ostream& operator<<(ostream& os, const Mint& m) { return os << m.v; }

    static T inv(T a, T m) {
        T g = m, x = 0, y = 1;
        while (a != 0) {
            T q = g / a;
            g %= a; swap(g, a);
            x -= q * y; swap(x, y);
        } return x < 0 ? x + m : x;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif // x must be less than 2^32 * m
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x), quot, rem;
        asm("divl %4\n" : "=a" (quot), "=d" (rem) : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    Mint inv() const { return Mint(inv(v, MOD)); }
    Mint operator-() const { return Mint(v ? MOD - v : 0); }
    Mint& operator++() { v++; if (v == MOD) v = 0; return *this; }
    Mint& operator--() { if (v == 0) v = MOD; v--; return *this; }
    Mint operator++(int) { Mint a = *this; ++*this; return a; }
    Mint operator--(int) { Mint a = *this; --*this; return a; }
    Mint& operator+=(const Mint& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    Mint& operator-=(const Mint& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    Mint& operator*=(const Mint& o) { v = fast_mod(uint64_t(v) * o.v); return *this; }
    Mint& operator/=(const Mint& o) { return *this *= o.inv(); }
    friend Mint operator+(const Mint& a, const Mint& b) { return Mint(a) += b; }
    friend Mint operator-(const Mint& a, const Mint& b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint& a, const Mint& b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint& a, const Mint& b) { return Mint(a) /= b; }
    friend bool operator==(const Mint& a, const Mint& b) { return a.v == b.v; }
    friend bool operator!=(const Mint& a, const Mint& b) { return a.v != b.v; }
    friend bool operator<(const Mint& a, const Mint& b) { return a.v < b.v; }
    friend bool operator>(const Mint& a, const Mint& b) { return a.v > b.v; }
    friend bool operator<=(const Mint& a, const Mint& b) { return a.v <= b.v; }
    friend bool operator>=(const Mint& a, const Mint& b) { return a.v >= b.v; }
    Mint operator^(int64_t p) {
        if (p < 0) return inv() ^ -p;
        Mint a = *this, res{1}; while (p > 0) {
            if (p & 1) res *= a;
            p >>= 1; if (p > 0) a *= a;
        } return res;
    }
};

const int MOD = 998244353;
using mint = Mint<MOD>;

namespace NTT {
const int FFT_CUTOFF = 150;
vector<mint> roots = {0, 1};
vector<int> bit_order;
int max_size = 1;       // MOD = c?2^k + 1, maxsize = 2^k
mint root = 2;          // n must not exceed maxsize

auto find_root = []() {
    int order = MOD - 1;
    while (~order & 1) order >>= 1, max_size <<= 1;
    while ((root ^ max_size) != 1 or (root ^ max_size / 2) == 1)
        root++;
    return 'W';
}();

void prepare_roots(int n) {
    if (roots.size() >= n) return;
    int len = __builtin_ctz(roots.size());
    roots.resize(n);
    while (n > 1 << len) {
        mint z = root ^ max_size >> len + 1;
        for (int i = 1 << len - 1; i < 1 << len; i++) {
            roots[i << 1] = roots[i];
            roots[i << 1 | 1] = roots[i] * z;
        } len++;
    }
}

void reorder_bits(int n, vector<mint>& a) {
    if (bit_order.size() != n) {
        bit_order.assign(n, 0);
        int len = __builtin_ctz(n);
        for (int i = 0; i < n; i++)
            bit_order[i] = (bit_order[i >> 1] >> 1) + ((i & 1) << len - 1);
    }
    for (int i = 0; i < n; i++)
        if (i < bit_order[i]) swap(a[i], a[bit_order[i]]);
}

void fft(int n, vector<mint>& a) {
    assert(n <= max_size);
    prepare_roots(n); reorder_bits(n, a);
    for (int len = 1; len < n; len <<= 1)
        for (int i = 0; i < n; i += len << 1)
            for (int j = 0; j < len; j++) {
                const mint& even = a[i + j];
                mint odd = a[i + len + j] * roots[len + j];
                a[i + len + j] = even - odd; a[i + j] = even + odd;
            }
}

template<typename T>
vector<mint> multiply(const vector<T>& a, const vector<T>& b, bool trim = false) {
    int n = a.size(), m = b.size();
    if (n == 0 or m == 0)
        return vector<mint> {0};

    if (min(n, m) < FFT_CUTOFF) {
        vector<mint> res(n + m - 1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                res[i + j] += mint(a[i]) * mint(b[j]);

        if (trim) {
            while (!res.empty() && res.back() == 0)
                res.pop_back();
        }

        return res;
    }

    int N = [](int x) { while (x & x - 1) x = (x | x - 1) + 1; return x; }(n + m - 1);
    vector<mint> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    fa.resize(N); fb.resize(N);

    bool equal = fa == fb;
    fft(N, fa);

    if (equal) fb = fa;
    else fft(N, fb);

    mint inv_N = mint(N) ^ -1;
    for (int i = 0; i < N; i++)
        fa[i] *= fb[i] * inv_N;
    reverse(fa.begin() + 1, fa.end());

    fft(N, fa);
    fa.resize(n + m - 1);

    if (trim) {
        while (!fa.empty() && fa.back() == 0)
            fa.pop_back();
    }

    return fa;
}

template<typename T>
vector<mint> expo(const vector<T>& a, int e, bool trim = false) {
    int n = a.size();
    int N = [](int x) { while (x & x - 1) x = (x | x - 1) + 1; return x; }((n - 1) * e + 1);
    vector<mint> fa(a.begin(), a.end()); fa.resize(N);

    fft(N, fa);

    mint inv_N = mint(N) ^ -1;
    for (int i = 0; i < N; i++)
        fa[i] = (fa[i] ^ e) * inv_N;
    reverse(fa.begin() + 1, fa.end());

    fft(N, fa);
    fa.resize((n - 1) * e + 1);

    if (trim) {
        while (!fa.empty() && fa.back() == 0)
            fa.pop_back();
    }

    return fa;
}

} // namespace NTT