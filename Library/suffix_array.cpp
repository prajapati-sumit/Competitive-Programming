/**
 * Author: Lukas Polacek
 * Date: 2009-10-27
 * License: CC0
 * Source: folklore and Linear-time longest-common-prefix
 * computation in suffix arrays and its applications (2001).
 * Description: Builds suffix array for a string. $a[i]$ is
 * the starting index of the suffix which is $i$-th in the
 * sorted suffix array. The returned vector is of size $n+1$,
 * and $a[0] = n$. The {\tt lcp} function calculates longest
 * common prefixes for neighbouring strings in suffix array.
 * The returned vector is of size $n+1$, and $ret[0] = 0$.
 * Time: $O(N \log^2 N)$ where $N$ is the length of the string
 * for creation of the SA. $O(N)$ for longest common prefixes.
 * Memory: $O(N)$
 * Status: Tested on UVa Live 4513
 */
typedef pair<ll, int> pli;
void count_sort(vector<pli> &b, int bits) { // (optional)
    //this is just 3 times faster than stl sort for N=10^6
    int mask = (1 << bits) - 1;
    rep(it,2) {
        int move = it * bits;
        vector<int> q(1 << bits), w(SZ(q) + 1);
        rep(i,SZ(b))
            q[(b[i].first >> move) & mask]++;
        partial_sum(q.begin(), q.end(), w.begin() + 1);
        vector<pli> res(b.size());
        rep(i,SZ(b))
            res[w[(b[i].first >> move) & mask]++] = b[i];
        swap(b, res);
    }
}
struct SuffixArray {
    vector<int> a;
    string s;
    SuffixArray(const string& _s) : s(_s + '$') {
        int N = SZ(s);
        vector<pli> b(N);
        a.resize(N);
        rep(i,N) {
            b[i].first = s[i];
            b[i].second = i;
        }

        int q = 8;
        while ((1 << q) < N) q++;
        for (int moc = 0;; moc++) {
            count_sort(b, q); // sort(all(b)) can be used as well
            a[b[0].second] = 0;
            for(int i=1;i<N;i++)
                a[b[i].second] = a[b[i - 1].second] +
                    (b[i - 1].first != b[i].first);

            if ((1 << moc) >= N) break;
            rep(i,N) {
                b[i].first = (ll)a[i] << q;
                if (i + (1 << moc) < N)
                    b[i].first += a[i + (1 << moc)];
                b[i].second = i;
            }
        }
        rep(i,SZ(a)) a[i] = b[i].second;
        a.erase(a.begin());
    }
    vector<int> LCP() {
        // longest common prefixes: res[i] = lcp(a[i], a[i-1])
        int n = SZ(a), h = 0;
        vector<int> inv(n), res(n);
        rep(i,n) inv[a[i]] = i;
        rep(i,n) if (inv[i] > 0) {
            int p0 = a[inv[i] - 1];
            while (s[i + h] == s[p0 + h]) h++;
            res[inv[i]] = h;
            if(h > 0) h--;
        }
        return res;
    }
};