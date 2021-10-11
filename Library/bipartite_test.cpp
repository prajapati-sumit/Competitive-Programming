
const int MX=1e5+5;

bool vis[MX];
bool color[MX];
vector<int>G[MX];
//returns false if the graph is not bipartite.
bool dfs(int u,int col){

    vis[u]=true;
    color[u]=col;
    for(auto &c:G[u]){
        if((!vis[c] && dfs(c,col^1)==false) || 
            (vis[c] && col[u]=col[c]))
            return false;    
    }
    return true;
}