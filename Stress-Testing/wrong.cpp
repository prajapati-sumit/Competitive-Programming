//~ author      : Sumit Prajapati


#include <bits/stdc++.h>
using namespace std;



const int dx[4] {1, 0, -1, 0}, dy[4] {0, 1, 0, -1};
const int MX = 1e5 + 5;
vector<pair<int, int>>v[MX];
int a[101][101];
int n, m;
int  vis[101][101];
int sentinel = 0;
bool check(int x1, int y1, int x2, int y2, int d) {
    if (x1 < 0 || x1 > n || y1 < 0 || y1 > m )
        return false;
    if (vis[x1][y1] == sentinel)
        return false;
    if (d > 4)
        return false;
    if (x1 == x2 && y1 == y2) {
        return true;
    }
    vis[x1][y1] = sentinel;
    // (x1, y1, d);
    bool res = false;
    for (int i = 0; !res && i < 4; i++) {
        res |= check(x1 + dx[i], y1 + dy[i], x2, y2, d + 1);
    }
    for (int i = 1; !res && i * i <= a[x1][y1]; i++) {
        if (a[x1][y1] % i == 0) {
            int other = a[x1][y1] / i;
            for (int j = 0; !res && j < v[i].size(); j++) {
                res |= check(v[i][j].first, v[i][j].second, x2, y2, d + 1);
            }
            if (other != i) {
                for (int j = 0; !res && j < v[other].size(); j++) {
                    res |= check(v[other][j].first, v[other][j].second, x2, y2, d + 1);
                }
            }
        }
    }
    return res;
}
void solve() {

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            a[i][j] = x;
            v[x].push_back({i, j});
        }

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        sentinel++;
        if (check(x1, y1, x2, y2, 0)) {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }

}



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;

}