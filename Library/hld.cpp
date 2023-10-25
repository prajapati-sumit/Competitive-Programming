// use 1 base indexing strictly

struct Vertex {
    Vertex *l, *r;
    int val;

    Vertex(int val) : l(nullptr), r(nullptr), val(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), val(0) {
        if (l) val = max(val,l->val);
        if (r) val = max(val,r->val);
    }
};

Vertex* build(vector<int>&a, int tl, int tr) {
    if (tl == tr)
        return new Vertex(a[tl-1]);
    int tm = (tl + tr) / 2;
    return new Vertex(build(a, tl, tm), build(a, tm+1, tr));
}

int query(Vertex* v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return v->val;
    int tm = (tl + tr) / 2;
    return max(query(v->l, tl, tm, l, min(r, tm))
         , query(v->r, tm+1, tr, max(l, tm+1), r));
}

void update(Vertex* v, int tl, int tr, int pos, int new_val) {
    if (tl == tr){
        v->val = new_val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        update(v->l, tl, tm, pos, new_val);
    else
        update(v->r, tm+1, tr, pos, new_val);
    v->val = 0;
    if (v->l) v->val = max(v->val,v->l->val);
    if (v->r) v->val = max(v->val,v->r->val);
}

int n;
const int LOG_MAX = 19;
vector<int>G[MX];
int a[MX];
int par[MX][LOG_MAX];
int heavyChild[MX];
int whichSegTree[MX];
int idInSegTree[MX];
int startFrom[MX];
int depth[MX];
vector<vector<int>>values;
vector<Vertex*>segTrees;
int id = 0;


int dfs(int u, int p = -1){
    int sz = 1;
    int heaviest = -1;
    heavyChild[u] = -1;
    for(int c:G[u]){
        if(c==p)
            continue;

        // finding LCA
        par[c][0] = u;
        depth[c] = depth[u] + 1;
        for(int j = 1;j<LOG_MAX;j++)
            par[c][j] = par[par[c][j-1]][j-1];

        int szc = dfs(c,u);
        if(szc>heaviest)
            heaviest = szc, heavyChild[u] = c;
        sz+=szc;
    }
    return sz;
}

void dfs2(int u,int s = -1){

    if(s==-1){
        startFrom[u] = u;
        whichSegTree[u] = id++;
        idInSegTree[u] = 1;
        segTrees.push_back(NULL);
        values.push_back(vector<int>{a[u]});
    }
    else{
        startFrom[u] = s;
        whichSegTree[u] = whichSegTree[s];
        idInSegTree[u] = idInSegTree[par[u][0]]+1;
        values[whichSegTree[u]].push_back(a[u]);
    }

    for(int c:G[u]){
        if(c==par[u][0])
            continue;
        if(c==heavyChild[u]){
            dfs2(c,startFrom[u]);
        }
        else{
            dfs2(c,-1);
        }
    }
}

int get_lca(int a, int b) { // O(log(N))
    if(depth[a] < depth[b]) {
        swap(a, b);
    }
    // 1) Get same depth.
    int k = depth[a] - depth[b];
    for(int j = LOG_MAX - 1; j >= 0; j--) {
        if(k & (1 << j)) {
            a = par[a][j]; // parent of a
        }
    }
    // 2) if b was ancestor of a then now a==b
    if(a == b) {
        return a;
    }
    // 3) move both a and b with powers of two
    for(int j = LOG_MAX - 1; j >= 0; j--) {
        if(par[a][j] != par[b][j]) {
            a = par[a][j];
            b = par[b][j];
        }
    }
    return par[a][0];
}

int queryLCA(int p, int u){
    int ans = -1;
    while(u!=0 && depth[u]>=depth[p]){
        int s = startFrom[u];
        if(depth[p]>depth[s]){
            s = p;
        }
        ans = max(ans, query(segTrees[whichSegTree[u]], 1, values[whichSegTree[u]].size(), idInSegTree[s], idInSegTree[u]));
        u = par[s][0];

    }
    return ans;
}
int queryHLD(int u, int v){
    int L = get_lca(u,v);
    return max(queryLCA(L,u),queryLCA(L,v));

}
void updateHLD(int u,int val){
    update(segTrees[whichSegTree[u]], 1, values[whichSegTree[u]].size(), idInSegTree[u], val);
}
void solve() {

    int q;
    cin>>n>>q;
    repe(i,n)
        cin>>a[i];
    repe(i,n-1){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1);
    dfs2(1);
    for(int i = 0;i<values.size();i++)
        segTrees[i] = build(values[i],1,values[i].size());


    repe(i,q){
        int ty,x,y;
        cin>>ty>>x>>y;
        if(ty==1){
            updateHLD(x,y);
        }
        else{
            cout<<queryHLD(x,y)<<" ";
        }
    }

}
