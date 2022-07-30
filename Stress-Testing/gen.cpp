// generating a tree in a not-so-stupid way
#include <bits/stdc++.h>
using namespace std;

#define rep(i,n)            for(int i=0;i<n;i++)
#define int                 long long
#define repe(i,n)           for(int i=1;i<=n;i++)
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define pb                  push_back
#define all(a)              a.begin(),a.end()
#define mtrand(a,b)         uniform_int_distribution<int>(a, b)(rng)
#define shuffle(a)              shuffle(a.begin(), a.end(), rng)
#define SZ(x)               ((int)x.size())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MD = 1e9 + 7;
const int INF = 1e9;

int rand(int a, int b) {
    if (a > b)
        return 0;
    return mtrand(a, b);
}
int randprime() {
    vector<int>primes{2, 3, 5, 7, 11, 13, 17, 19, 23};
    int ind = mtrand(0, (int)primes.size() - 1);
    return primes[ind];
}
void print_array(int n, int L = 1, int R = 10) {
    repe(i, n)
    cout << mtrand(L, R) << " \n"[i == n];
}
void print_queries(int q, int n) {
    while (q--) {
        int ty = (mtrand(0, 2)) + 1;
        cout << ty << " ";
        if (ty == 1) {
            int l = mtrand(1, n);
            int r = mtrand(l, n);
            int x = mtrand(1, 9);
            cout << l << " " << r << " " << x << "\n";
        }
        else if (ty == 2) {
            int l = mtrand(1, n);
            int r = mtrand(l, n);
            int x = mtrand(1, 9);
            cout << l << " " << r << " " << x << "\n";
        }
        else {
            int l = mtrand(1, n);
            int r = mtrand(l, n);
            cout << l << " " << r << "\n";
        }
    }
}
void print_string(int n) {
    rep(i, n)
    cout << char('a' + mtrand(0, 25));
    cout << '\n';
}
void print_distinct(int n, int l = 1, int r = 10) {
    set<int>st;
    while (SZ(st) < n)
        st.insert(mtrand(l, r));
    for (auto &el : st)
        cout << el << " ";
    cout << "\n";
}
void print_tree(int n) {
    vector<pair<int, int>> edges;
    for (int i = 2; i <= n; ++i) {
        edges.emplace_back(mtrand(1, i - 1), i);
    }

    vector<int> perm(n + 1); // re-naming vertices
    for (int i = 1; i <= n; ++i) {
        perm[i] = i;
    }
    random_shuffle(perm.begin() + 1, perm.end());

    random_shuffle(edges.begin(), edges.end()); // random order of edges

    for (pair<int, int> edge : edges) {
        int a = edge.first, b = edge.second;
        if (mtrand(0, 1)) {
            swap(a, b); // random order of two vertices
        }
        cout << perm[a] << " " << perm[b] << "\n";
    }
}

int32_t main(int32_t argc, char* argv[]) {
    srand(time(NULL));
    int t = mtrand(1, 20);
    cout << t << "\n";
    for (int i = 0; i < t; i++) {
        int n = mtrand(1, 15);
        cout << n << "\n";
        print_array(n);
    }



}