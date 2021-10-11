// 1-base indexing
void combine(int& x, int& y, int& res) {
    res = x + y;
}
template <typename T>
class LazySegTree {
private:
    T* segm;
    int* lazy;
    int N;
    void (*merge)(T&, T&, T&);
    void buildtree(int cur, int start, int end, T a[]) {
        if (start == end) {
            //BASE CASE
            segm[cur] = a[start];
            return;
        }
        int mid = (start + end) >> 1;
        buildtree(cur << 1, start, mid, a);
        buildtree((cur << 1) ^ 1, mid + 1, end, a);
        //MERGING STEP
        (*merge)(segm[(cur << 1)], segm[(cur << 1) ^ 1], segm[cur]);

    }
    void lazyUpdate(int cur, int start , int end) {
        if (!lazy[cur])
            return;
        int dx = lazy[cur];
        lazy[cur] = 0;
        segm[cur]+=dx*(end-start+1);
        if (start != end) {
            lazy[(cur << 1)] += dx;
            lazy[(cur << 1) ^ 1] += dx;

        }
    }
    T query(int cur, int start, int end, int qs, int qe) {
        lazyUpdate(cur, start, end);
        if (start >= qs && end <= qe)
            return segm[cur];
        if (start > qe || end < qs)
            return T(0);          //INVALID RETURN
        int mid = (start + end) >> 1;
        T A = query((cur << 1) , start, mid, qs, qe);
        T B = query((cur << 1) ^ 1, mid + 1, end, qs, qe);
        //MERGING STEP
        T res;
        (*merge)(A, B, res);

        return res;
    }
    void update(int cur, int start, int end, int qs, int qe, int val) {
        lazyUpdate(cur, start, end);
        if (start >= qs && end <= qe) {
            //DO UPDATE
            lazy[cur] = val;
            lazyUpdate(cur, start, end);
            return;
        }
        if (start > qe || end < qs)
            return;          //OUT OF RANGE
        int mid = (start + end) >> 1;
        update((cur << 1), start, mid, qs, qe,val);
        update((cur << 1) ^ 1, mid + 1, end, qs, qe,val);
        //MERGING STEP
        (*merge)(segm[(cur << 1)], segm[(cur << 1) ^ 1], segm[cur]);
    }

public:

    LazySegTree(int n, void (*fun)(T&, T&, T&) = &combine) {
        N = n;
        segm = new T[4 * (N + 1)]();
        lazy = new T[4 * (N + 1)]();
        merge = fun;

    }
    LazySegTree(int a[], int n, void (*fun)(T&, T&, T&) = &combine) {
        N = n;
        segm = new T[4 * (N + 1)]();
        lazy = new T[4 * (N + 1)]();
        merge = fun;
        buildtree(1, 1, N, a);
    }
    T query(int l, int r) {
        return query(1, 1, N, l, r);
    }
    void update(int l, int r, T val) {
        update(1, 1, N, l, r, val);
    }

};