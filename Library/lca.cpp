const int MX = 2e5+2;
const int LOG = 19;
vector<int> v[MX];
int up[MX][LOG]; // up[v][j] is 2^j-th ancestor of v
int depth[MX];
 
void dfs(int a) {
    for(int b : v[a]) {
        if(b==par)
            continue;
        depth[b] = depth[a] + 1;
        up[b][0] = a; // a is parent of b
        for(int j = 1; j < LOG; j++) {
            up[b][j] = up[up[b][j-1]][j-1];
        }
        dfs(b);
    }
}
 
int get_lca(int a, int b) { // O(log(N))
    if(depth[a] < depth[b]) {
        swap(a, b);
    }
    // 1) Get same depth.
    int k = depth[a] - depth[b];
    for(int j = LOG - 1; j >= 0; j--) {
        if(k & (1 << j)) {
            a = up[a][j]; // parent of a
        }
    }
    // 2) if b was ancestor of a then now a==b
    if(a == b) {
        return a;
    }
    // 3) move both a and b with powers of two
    for(int j = LOG - 1; j >= 0; j--) {
        if(up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}
 
int get_dist(int x,int y){
    return depth[x]+depth[y]-2*depth[get_lca(x,y)];
}



