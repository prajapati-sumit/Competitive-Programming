struct Edges{
    int x;
    int y;
    int w;
    bool operator < (const Edges& other){
        return w<other.w;
    }
};

// #warning works on array from 1...n
// with path compression and union by rank.
// DisJoing Set Union
class DSU{

public:
    vector<int>parent;

    DSU(int n){
        parent.resize(n+1);
        for(int i=1;i<=n;i++)
            parent[i]=-1;
    }
    int find_set(int x){
        return parent[x]<0?x:parent[x]=find_set(parent[x]);
    } 
    void union_set(int a,int b){
        int pa=find_set(a);
        int pb=find_set(b);
        if(pa==pb)
            return;
        if(parent[pa]>parent[pb])
            swap(pa,pb);

        parent[pa]+=parent[pb];
        parent[pb]=pa;
    } 
    bool same_set(int a,int b){
        return find_set(a)==find_set(b);
    }

};
int mst_kruskal(int n,int m,Edges E[]){
    DSU D(n);
    int cost=0;
    sort(E,E+m);
    int cnt_edges=0;
    for(int i=0;i<m && cnt_edges<n-1;i++){
        Edges cur=E[i];
        if(!D.same_set(cur.x,cur.y)){
            D.union_set(cur.x,cur.y);
            cost+=cur.w;
            cnt_edges++;
        }
    }
    return cost;
}
void solve() {
 
    int n,m;
    cin>>n>>m;
    Edges E[m+1];
    int ans=0;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        E[i].x=x;
        E[i].y=y;
        E[i].w=w;
    }
    cout<<mst_kruskal(n,m,E)<<"\n";
}
