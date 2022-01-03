//~ author      : Sumit Prajapati
#include <bits/stdc++.h>

using namespace std;


template <typename T>
class List {
    T* a;
    int cur_size;
    int capacity;
public:
    List () {
        cur_size = 0;
        capacity = 1;
        a = new T[capacity];
    }
    List (int n, int def = 0) {
        cur_size = n;
        capacity = 1;
        while (capacity < n)
            capacity <<= 1;
        a = new T[capacity];
        for (int i = 0; i < cur_size; i++)
            a[i] = def;
    }
    T& operator[](int i) {
        return a[i];
    }
    void resize(int n) {
        a = new T[n];
    }
    void push_back(T x) {
        if (cur_size == capacity) {
            capacity <<= 1;
            T* b = new T[capacity];
            for (int i = 0; i < cur_size; i++)
                b[i] = a[i];
            delete a;
            a = b;
        }
        a[cur_size++] = x;
    }
    void pop_back() {
        if (cur_size > 0)
            cur_size--;
    }
    bool empty() {
        return cur_size == 0;
    }
    int size() {
        return cur_size;
    }
    T back() {
        if (cur_size > 0)
            return a[cur_size - 1];
        return T(0);
    }
    void print() {
        for (int i = 0; i < cur_size; i++)
            cout << a[i] << " \n"[i == cur_size - 1];
    }
};
// 1-base array indexing
template <typename T>
class MinHeap {
    const int max_size = 1e4 + 2;
    int cur_size;
    T* a;
    int p(int idx) {
        return idx >> 1;
    }
    int l(int idx) {
        return (idx << 1);
    }
    int r(int idx) {
        return (idx << 1) + 1;
    }
    void swap(T& A, T& B) {
        T W = A;
        A = B;
        B = W;
    }
    void up_heapify(int idx) {

        while (idx > 1 && a[idx] < a[p(idx)]) {
            swap(a[idx], a[p(idx)]);
            idx = p(idx);
        }
    }
    void down_heapify(int idx) {
        while (l(idx) <= cur_size) {
            int lc = l(idx), rc = r(idx);
            int child = (lc == cur_size || a[lc] <= a[rc] ? lc : rc);

            if (a[child] < a[idx]) {
                swap(a[child], a[idx]);
                idx = child;
            }
            else
                break;
        }
    }
public:
    MinHeap(int n) {
        a = new T[n + 1];
    }
    MinHeap() {
        cur_size = 0;
        a = new T[max_size];
    }
    MinHeap(T b[], int n) {

        a = new T[n + 1];
        cur_size = n;
        for (int i = 1; i <= n; i++)
            a[i] = b[i];
        for (int i = n / 2 + 1; i >= 1; i--)
            down_heapify(i);

        for (int i = 1; i <= n; i++)
            b[i] = a[i];
    }

    void push(T x) {

        if (cur_size >= max_size) {
            cout << "Heap Overflow\n";
            return;
        }
        cur_size++;
        a[cur_size] = x;
        up_heapify(cur_size);
    }
    void pop() {
        if (cur_size == 0) {
            cout << "Heap UnderFlow\n";
            return;
        }
        a[1] = a[cur_size];
        cur_size--;
        down_heapify(1);
    }
    T top() {
        if (cur_size == 0) {
            cout << "Heap UnderFlow\n";
            return T();
        }
        return a[1];
    }
    bool empty() {
        return cur_size == 0;
    }
    int size() {
        return cur_size;
    }
};

int mst_prim(int n, int m, List<List<pair<int, int>>>& G) {

    int cost = 0;
    // min priority queue
    // {weight,to_node}
    MinHeap<pair<int, int>>mpq;
    List<int>vis(n , 0);
    // start node
    int s = 0;
    int cnt = 0;
    mpq.push({0, s});
    while (!mpq.empty() && cnt < n ) {
        pair<int, int>cur = mpq.top();
        mpq.pop();
        int u = cur.second;
        int w = cur.first;
        if (vis[u])
            continue;
        vis[u] = 1;
        cost += w;
        // cout << u << " " << w << " \n";
        cnt++;
        for (int i = 0; i < G[u].size(); i++) {
            pair<int, int> c = G[u][i];
            // cout << u << ": " << c.first << " " << c.second << "\n";
            if (!vis[c.first])
                mpq.push({c.second, c.first});
        }
    }
    return cost;
}
// Nothing is imported from STL,all DS were implemented manually
// For eg, Lists, Minheap,etc.
void solve() {

    int n, m;
    cin >> n >> m;
    int ans = 0;
    List<List<pair<int, int>>>G;
    G.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        G[x].push_back({y, w});
        G[y].push_back({x, w});
    }
    cout << mst_prim(n, m, G) << "\n";
}

int32_t main() {


    solve();

    return 0;

}