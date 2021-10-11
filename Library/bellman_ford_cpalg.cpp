
const int INF=1e16;

int n,m;
struct Edge{
    int a,b,cost;
};
vector<Edge>e;
// warning works on 0-base indexing
void bellman_ford(vector<int>& d)
{
    d.resize(n, 0);
    vector<int> p (n ,- 1);
    int x;
    for (int i=0; i<n; ++i)
    {
        x = -1;
        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
    }
    if (x == -1)
        cout << "NO\n";
    else
    {
        int y = x;
        for (int i=0; i<n; ++i)
            y = p[y];
        vector<int> path;
        for (int cur=y; ; cur=p[cur])
        {   
            path.push_back (cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse (path.begin(), path.end());

        cout << "YES\n";
        for (size_t i=0; i<path.size(); ++i)
            cout << path[i]+1 << ' ';
    }
}
 