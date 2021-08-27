
// One-base indexing.
// don't query outside range [1,n]
struct FenwickTree{
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    FenwickTree(vector<int> &a,int n):FenwickTree(a.size()) {
        for (int i = 1; i <= n; i++)
            add(i, a[i]);
    }

    int sum(int idx) {
        int ret = 0;
        for (; idx >=1; idx -= idx & -idx){
            ret += bit[idx];
        }
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }
};