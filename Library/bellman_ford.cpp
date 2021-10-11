const int MX = 2500 + 5;

struct Edge {
    int a, b, w;
};
int n;
int dist[MX];
vector<Edge>E;
//single source shortest path with detection of negative
//cycle
void bellman_ford(int start) {

    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[start] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto &edge : E) {
            int a = edge.a, b = edge.b, w = edge.w;
            if(dist[a]==INF)
                continue;
            if (dist[b] > dist[a] + w){
                dist[b] = dist[a] + w;
                dist[b] = max(dist[b],-INF);
            }
        }
    }
    // check if any node can be relaxed 
    // if you just want to detect negative cycle.
    // following also marks the affected node.
    for (int i = 1; i <= n - 1; i++) {
        for (auto &edge : E) {
            int a = edge.a, b = edge.b, w = edge.w;
            if(dist[a]==INF)
                continue;
            dist[b] = max(dist[b],-INF);
            if (dist[b] > dist[a] + w){
                dist[b] = -INF;
            }
        }
    }

}