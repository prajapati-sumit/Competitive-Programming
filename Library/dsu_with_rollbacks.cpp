
// #warning works on array from 1...n
// with path compression and union by rank.
// Disjoint Set Union
class DSU{
 
public:
    vector<int>parent;
    vector<pii>stk;
    int cc;
    DSU(int n){
        parent.resize(n+1);
        for(int i=1;i<=n;i++)
            parent[i]=-1;
    }
    int find_set(int x){
        return parent[x]<0?x:find_set(parent[x]);
    } 
    void union_set(int a,int b){
        int pa=find_set(a);
        int pb=find_set(b);
        if(pa==pb){
            stk.push_back({-1,parent[pb]});
            return;
        }
        if(parent[pa]>parent[pb])
            swap(pa,pb);
        stk.push_back({pb,parent[pb]});
        parent[pa]+=parent[pb];
        parent[pb]=pa;
        cc--;
    } 
    int getCC(){
        return cc;
    }
    void rollback(){
 
        assert(stk.size());
        pii last = stk.back();
        stk.pop_back();
        if(last.ff==-1)
            return;
        parent[parent[last.ff]] -=last.ss; 
        parent[last.ff] = last.ss;
        cc++;
    }
    bool same_set(int a,int b){
        return find_set(a)==find_set(b);
    }
 
};