// works on 1-base indexing
// merge function should be idempotent
class SparseTable {
    vector<vector<int>>sparse;
    int n;
    int LOG_MAX;
    vector<int>LOG2;


    void merge(int& A, int& B, int& res) {
        res = min(A, B);
    }
    void init(vector<int>& a) {

        for (int i = 1; i <= n; i++) {
            sparse[i][0] = a[i];
        }
        for (int j = 1; j <= LOG_MAX; j++) {
            for (int i = 1; (i + (1 << j) - 1) <= n && i <= n; i++) {
                merge(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1], sparse[i][j]);
            }
        }
    }

public:
    SparseTable(vector<int>& a, int n) {
        this->n = n;
        LOG2.resize(n + 1);
        LOG2[1] = 0;
        for (int i = 2; i <= n; i++) {
            LOG2[i] = 1 + LOG2[i / 2];
        }

        LOG_MAX = LOG2[n];
        sparse.resize(n + 1, vector<int>(LOG_MAX + 1));

        init(a);
    }
    int query(int x, int y) {
#warning check this condition
        if (x > y)
            return INF;

        int h = LOG2[y - x + 1];
        int res;
        merge(sparse[x][h], sparse[y - (1 << h) + 1][h], res);
        return res;
    }
};


