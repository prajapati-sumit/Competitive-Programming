/*
Works with 0-base
don't query wrong indices
*/

template <typename T>
class FenwickTree {
    vector<T>bit;
    int n;
public:
    FenwickTree(vector<T> &a){
        n = a.size();
        bit.assign(n,0);
        for (int i = 0; i < n; i++) {
            bit[i]+=a[i];
            int r = i | (i + 1);
            if (r < n) bit[r] += bit[i];
        }
    }
    FenwickTree(T a[], int n){
        this->n = n;
        bit.assign(n,0);
        for (int i = 0; i < n; i++) {
            bit[i]+=a[i];
            int r = i | (i + 1);
            if (r < n) bit[r] += bit[i];
        }
    }
     FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - (l?sum(l - 1):0);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }

};
