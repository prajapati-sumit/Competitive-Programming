struct StringHash {
    ll p;
    const ll m = 1e9 + 7;
    const ll m2 = 1e9 + 7;
    const int start = 'a';
    int len;

    pair<ll, ll>hashes;
    StringHash(int _p = 31) {
        p = _p;
        hashes = {0, 0};
        len = 0;
    }

    StringHash(string s, int _p = 31) {
        p = _p;
        len = s.length();
        compute_hash(s);
    }
    ll bin_power(ll a, ll b, ll md) {
        ll res = 1;
        while (b) {
            if (b & 1)
                res = (res * a) % md;
            a = (a * a) % md;
            b >>= 1;
        }
        return res;
    }
    void push_back(char c) {
        hashes.ff = ((hashes.ff * p) % m + (c - start + 1) ) % m;
        hashes.ss = ((hashes.ss * p) % m2 + (c - start + 1) ) % m2;
        len++;
    }
    void push_front(char c) {
        int pow = bin_power(p, len, m);
        int pow2 = bin_power(p, len, m2);
        hashes.ff = (hashes.ff + pow * (c - start + 1) % m) % m;
        hashes.ss = (hashes.ss + pow2 * (c - start + 1) % m2) % m2;
        len++;
    }
    void pop_front(char c) {
        int pow = bin_power(p, len - 1, m);
        int pow2 = bin_power(p, len - 1, m2);
        hashes.ff = (hashes.ff + m - pow * (c - start + 1) % m) % m;
        hashes.ss = (hashes.ss + m2 - pow2 * (c - start + 1) % m2) % m2;
        len--;
    }
    bool operator == (const StringHash other) {
        return len == other.len && hashes == other.hashes ;

    }
    bool operator <(const StringHash& other) const {
        return hashes < other.hashes;
    }

    void append(const StringHash other) {
        assert(m == other.m);
        assert(m2 == other.m2);
        assert(p == other.p);
        assert(start == other.start);
        len += other.len;

        int mul = bin_power(p, other.len, m);
        int mul2 = bin_power(p, other.len, m2);

        hashes.ff = (mul * hashes.ff + other.hashes.ff) % m;
        hashes.ss = (mul2 * hashes.ss + other.hashes.ss) % m;
    }
    bool isempty() {
        return len == 0;
    }
    // credits:cp-algorithms.com

    pair<ll, ll> compute_hash(string s) {
        hashes = {0, 0};
        for (char c : s) {
            hashes.ff = (p * hashes.ff + (c - start + 1) ) % m;
            hashes.ss = (p * hashes.ss + (c - start + 1) ) % m2;

        }
    }
};