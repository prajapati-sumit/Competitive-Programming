const int MX=2e5+5;

vector<int>v[MX];   // given graph
vector<int>tr[MX];  // transposed graph
bool vis[MX];
int id[MX];
int scc;
vector<int>order;

// there are 2n (1 to 2n) nodes, p:i => !p:(i+n)

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

bool two_sat(vector<bool>& res,int n){

    res.resize(n/2+1);
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
    for(int i=1;i<=n/2;i++){
        if(id[i]==id[i+n/2])
            return false;
        res[i]=(id[i]>id[i+n/2]);
    }
    return true;
}
void solve() {

    int n,m;
    cin>>m>>n;
    repe(i,m){
        int x,y;
        char c1,c2;
        cin>>c1>>x>>c2>>y;
        if(c1=='+' && c2=='+'){
            // !x->y
            // !y->x
            v[x+n].pb(y);
            v[y+n].pb(x);

            tr[y].pb(x+n);
            tr[x].pb(y+n);
        }
        else if(c1=='+' && c2=='-'){
            // !x->!y
            // y->x
            v[x+n].pb(y+n);
            v[y].pb(x);

            tr[y+n].pb(x+n);
            tr[x].pb(y);
        }
        else if(c1=='-' && c2=='+'){
            // x->y
            // !y->!x
            v[x].pb(y);
            v[y+n].pb(x+n);

            tr[y].pb(x);
            tr[x+n].pb(y+n);
        }
        else if(c1=='-' && c2=='-'){
            // x->!y
            // y->!x
            v[x].pb(y+n);
            v[y].pb(x+n);

            tr[y+n].pb(x);
            tr[x+n].pb(y);
        }
        else
            assert(0);
        
    }       
    vector<bool>res;
    if(!two_sat(res,2*n)){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    repe(i,n)
        if(res[i])
            cout<<"+ ";
        else
            cout<<"- ";

}