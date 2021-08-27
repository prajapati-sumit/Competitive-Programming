// ~works on tree with vertices from 1 to n
// ~make sure adjaceny matrix vector<int>v[n+1]
//  is present in global

class LCA {

    vector<int>out_time;
    vector<int>depth;
    vector<int>flatten;
    vector<int>LOG2;
    vector<vector<int>>sparse;

    int LOG_MAX;
    int timer;
    int n;
    int fl_N;

    void dfs(int cur, int par, int lev) {

        depth.pb(lev);
        flatten.pb(cur);
        timer++;
        for (auto &el : v[cur]) {
            if (el != par) {
                dfs(el, cur, lev + 1);
                depth.pb(lev);
                flatten.pb(cur);
                timer++;
            }
        }

        out_time[cur] = timer;
    }

    void merge(int& A, int& B, int& res) {
        if (depth[A] < depth[B])
            res = A;
        else
            res = B;
    }

    void init() {

        for (int i = 1; i <= fl_N; i++) {
            sparse[i][0] = i ;
        }
        for (int j = 1; j <= LOG_MAX; j++) {
            for (int i = 1; (i + (1 << j) - 1) <= fl_N && i <= fl_N; i++) {
                merge(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1], sparse[i][j]);
            }
        }
    }

public:
    LCA(int n, int root) {
        this->n = n;

        depth.pb(-1);
        flatten.pb(-1);
        out_time.resize(n + 1);
        timer = 0;
        dfs(root, -1, 0);
        fl_N = (int)depth.size();
        --fl_N;


        LOG2.resize(fl_N + 1);
        LOG2[1] = 0;
        for (int i = 2; i <= fl_N; i++)
            LOG2[i] = 1 + LOG2[i / 2];

        LOG_MAX = LOG2[fl_N];
        sparse.resize(fl_N + 1, vector<int>(LOG_MAX + 1));
        init();

    }
    
    int query(int x, int y) {
        // #warning check this condition
        if (x > y)
            return INF;

        int h = LOG2[y - x + 1];
        merge(sparse[x][h], sparse[y - (1 << h) + 1][h], h);
        return h;
    }

    int get_lca(int a, int b) {
        a = out_time[a];
        b = out_time[b];
        if(a>b)
            swap(a,b);
        return flatten[query(a, b)];
    }
    int get_dist(int a,int b){
        return depth[out_time[a]]+depth[out_time[b]]-2*depth[out_time[get_lca(a,b)]];
    }
};

