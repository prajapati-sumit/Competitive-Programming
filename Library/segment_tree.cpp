// 1-base indexing
void combine(int& x,int& y,int& res){
    res=x+y;
}
template <typename T>
class SegmentTree {
private:
    T* segm;
    int N;
    void (*merge)(T&, T&, T&);
    void buildtree(int cur, int start, int end, int a[]) {
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
    T query(int cur, int start, int end, int qs, int qe) {
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
    void update(int cur, int start, int end, int ind, T val) {
        if (start == ind && start == end) {
            //DO UPDATE
            segm[cur] = val;
            return;
        }
        if (start > ind || end < ind)
            return;          //OUT OF RANGE
        int mid = (start + end) >> 1;
        update(cur << 1, start, mid, ind, val);
        update((cur << 1) ^ 1, mid + 1, end, ind, val);
        //MERGING STEP
        (*merge)(segm[(cur << 1)], segm[(cur << 1) ^ 1], segm[cur]);

    }
public:

    SegmentTree(int n, void (*fun)(T&, T&, T&) = &combine) {
        N = n;
        segm = new T[4*(N + 1)]();
        merge = fun;

    }
    SegmentTree(int a[], int n,void (*fun)(T&, T&, T&) = &combine) {
        N = n;
        segm = new T[4*(N + 1)]();
        merge = fun;
        buildtree(1, 1, N, a);
    }
    T query(int l, int r) {
        return query(1, 1, N, l, r);
    }
    void update(int ind, T val) {
        update(1, 1, N, ind, val);
    }

};