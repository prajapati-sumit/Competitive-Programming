vector<pii> G[MX];
int n;
int dist[MX];
#warning fill the distance array with infinity
void dijkstra(int start)
{
    
 
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
        {
            if(dist[u]+x.second<dist[x.first])
            {
                dist[x.first]=dist[u]+x.second;
                pq.push(pii(dist[x.first],x.first));
            }
        }
 
 
    }
 
} 