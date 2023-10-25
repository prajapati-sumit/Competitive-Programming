const int MX = 505;
int n;
int dist[MX][MX];
int temp[MX][MX];
// O(n^3)
// dist array should contain the intial distance .
void floyd_warshall() {
    for (int turn = 1; turn <= n; turn++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j || i == turn || j == turn)
                    temp[i][j] = dist[i][j];
                else
                    temp[i][j] = min(dist[i][j], dist[i][turn] + dist[turn][j]);

            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = temp[i][j];
    }
}
