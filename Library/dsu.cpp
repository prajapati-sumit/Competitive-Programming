
#warning works on array from 1...n
// with path compression and union by rank.
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