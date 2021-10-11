const int MX=1e5+5;

vector<int>v[MX];   // given graph
vector<int>tr[MX];  // transposed graph
bool vis[MX];
int id[MX];
int scc;
vector<int>order;
int n,m;

void dfs1(int u){
    vis[u]=1;
    for(auto& c:v[u]){
        if(!vis[c])
            dfs1(c);
    }
    order.pb(u);
}
void dfs2(int u,int par){

    vis[u]=1;
    id[u]=par;
    for(auto& c:tr[u]){
        if(!vis[c])
            dfs2(c,par);
    }
}

void kosaraju(){

    for(int i=1;i<=n;i++)
        vis[i]=0;
    repe(i,n)
        if(!vis[i])
            dfs1(i);
        
    for(int i=1;i<=n;i++)
        vis[i]=0;

    while((int)order.size()){
        int b=order.back();
        order.pop_back();
        if(!vis[b])
            dfs2(b,++scc);
    }
    cout<<scc<<"\n";
}
void solve() {

    cin>>n>>m;
    repe(i,m){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        tr[y].pb(x);
    }              
    kosaraju();      
}