#include<stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<assert.h>

const int N = 100;
const int L = 10;
const int INF = 1e9;
// RC:0
// R<num>: 1 to N
// S<num>: N+1 to 2N
const int n = 2 * N + 1;

typedef struct Node {
    int u;
    int w;
} Node;

int adj_mat[n][n];
int parent[n];

char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int len(int x) {
    if (x == 0)
        return 1;
    return ceil(log10(x + 1));
}
char* id_to_name(int id) {
    char* res = (char*)malloc(sizeof(char) * L);
    if (id == 0) {
        res[0] = 'R';
        res[1] = 'C';
        res[2] = '\0';
    }
    else if (id <= N)
        res[0] = 'R';

    else if (id <= 2 * N) {
        res[0] = 'S';
        id -= N;
    }
    else
        assert(0);

    int k = len(id);
    for (int i = k; i >= 1; i--) {
        res[i] = digit[id % 10];
        id /= 10;
    }
    res[k + 1] = '\0';
    return res;
}
int name_to_id(char name[]) {
    if (name[0] == 'R' && name[1] == 'C')
        return 0;
    int x = 0;
    for (int i = 1; name[i] != '\0'; i++) {

        x = (10 * x + name[i] - '0');
    }

    if (name[0] == 'S')
        x += N;
    return x;
}
int min(int x, int y) {
    return x < y ? x : y;
}
void dijkstra(int start) {

}
int main() {

    Node cur;
    cur.u = 6;
    cur.w = 5;
    Node cur2 = cur;
    cur2.u = 7;
    printf("%d %d\n", cur.u, cur.w);
    printf("%d %d\n", cur2.u, cur2.w);
    exit(0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj_mat[i][j] = INF;
    int m;
    scanf("%d", &m);
    char a[L], b[L];
    int w;
    while (m--) {
        scanf("%s", a);
        scanf("%s", b);
        scanf("%d", &w);
        int a_id = name_to_id(a), b_id = name_to_id(b);
        adj_mat[a_id][b_id] = min(adj_mat[a_id][b_id], w);
        printf("%s %s %d\n", a, b, w);
    }
    dijkstra(0);

    char s[L];
    while (true) {
        scanf("%s", s);
        if (s[0] == 'T')
            break;
        int u = name_to_id(s);
        printf("%d\n", u);
    }
    return 0;
}