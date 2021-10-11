
const int MX=1e5+5;
vector<pii> G[MX];
int n;
int dist[MX];
void dijkstra(int start){
    
    for(int i=1;i<=n;i++)
        dist[i]=INF;
    dist[start]=0;
    priority_queue< pii,vector<pii>,greater<pii> > pq;
    pq.push(pii(0,start));
    while(!pq.empty())
    {
        pii p=pq.top();
        pq.pop();
        int d=p.first;
        int u=p.second;
        if(d>dist[u])
            continue;
 
 
        for(auto x: G[u])
        {   int v=x.first,w=x.second;
            if(dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
                pq.push(pii(dist[v],v));
            }
        }
 
 
    }
 
} 