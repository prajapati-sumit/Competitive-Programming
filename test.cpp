//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
// #define int                 long long
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define SZ(x)               ((int)x.size())
#define set_bits            __builtin_popcountll
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;

char a[1000][1000];
int what[1000][1000];
int dist[1000][1000];

int n, m;
bool isvalid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
struct Node {
    int x, y;
    int d;
};
vector<pii>tmp = {{0, -1}, { -1, 0}, {0, 1}, {1, 0}};
char dir[] = {'L', 'U', 'R', 'D'};

void bfsm(int sx, int sy) {


    int cnt = 0;
    queue<Node>Q;

    Q.push({sx, sy, 0});
    dist[sx][sy] = 0;
    while (!Q.empty()) {
        Node cur = Q.front();
        Q.pop();
        int x = cur.x, y = cur.y;
        for (pii pp : tmp) {
            int nx = x + pp.ff, ny = y + pp.ss;
            bool op1 = isvalid(nx, ny);
            bool op2 = (a[nx][ny] == '.');
            bool op3 = (dist[nx][ny] > cur.d + 1);
            cerr << nx << " " << ny << " "
                << (op1 && op2 && op3) << " "
            << (isvalid(nx, ny) && (a[nx][ny] == '.') &&  (dist[nx][nx]>cur.d+1)) <<" \n";
            // if (isvalid(nx, ny) && (a[nx][ny] == '.') &&  (dist[nx][nx]>cur.d+1)) {
            //     cerr<<x<<" "<<y<<" "<<nx<<" "<<ny<<'\n';
            //     Q.push({nx, ny, cur.d+1});
            //     dist[nx][ny]=cur.d+1;
            // }
        }
    }


}
bool bfs(int sx, int sy) {


    vector<pii>tmp = {{0, -1}, { -1, 0}, {0, 1}, {1, 0}};
    int cnt = 0;
    char dir[] = {'L', 'U', 'R', 'D'};
    memset(what, -1, sizeof(what));
    queue<Node>Q;
    Q.push({sx, sy, 0});
    what[sx][sy] = 0;
    int c = 0;
    while (!Q.empty()) {
        Node cur = Q.front();
        Q.pop();
        int x = cur.x, y = cur.y;
        if (a[x][y] == 'B') {
            string res;
            while (a[x][y] != 'A') {
                assert(isvalid(x, y) && what[x][y] != -1);
                int h = what[x][y];
                res.pb(dir[h]);
                x -= tmp[h].ff;
                y -= tmp[h].ss;
            }
            reverse(all(res));
            cout << "YES\n" << res.length() << "\n" << res << '\n';
            return true;

        }

        cnt = 0;
        for (pii pp : tmp) {
            int nx = x + pp.ff, ny = y + pp.ss;
            if (isvalid(nx, ny) && what[nx][ny] == -1 &&  a[nx][ny] != '#') {
                Q.push({nx, ny, cnt});
                what[nx][ny] = cnt;
            }
            cnt++;
        }
    }
    return false;

}

void solve() {

    cin >> n >> m;
    pii start;
    rep(i, n) {
        rep(j, m) {
            cin >> a[i][j];
            if (a[i][j] == 'A')
                start = {i, j};
        }
    }
    rep(i, n)
    rep(j, m)
    dist[i][j] = INF;
    rep(i, n) {
        rep(j, m) {
            if (a[i][j] == 'M')
                bfsm(i, j);
        }
    }
    rep(i, n)
    rep(j, m)
    if (dist[i][j] < INF)
        cout << dist[i][j] << " \n"[j == m - 1];
    else
        cout << "i" << " \n"[j == m - 1];
    exit(0);
    if (!bfs(start.ff, start.ss))
        cout << "NO\n";


}



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    // cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}