//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                     unsigned long long
#define ll                      long long
// #define int                     long long
#define pii                     pair<int, int>
#define pll                     pair<ll, ll>
#define pb                      push_back
#define mk                      make_pair
#define ff                      first
#define ss                      second
#define SZ(x)                   ((int)x.size())
#define set_bits                __builtin_popcountll
#define all(a)                  a.begin(),a.end()
#define trav(x,v)               for(auto &x:v)
#define rep(i,n)                for(int i=0;i<n;i++)
#define repe(i,n)               for(int i=1;i<=n;i++)
#define FOR(i,a,b)              for(int i=a;i<=b;i++)
#define curtime                 chrono::high_resolution_clock::now()
#define timedif(start,end)      chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define myshuffle(a,n)          FOR(i,1,n-1) swap(a[i], a[rand() % (i + 1)])
#define shuffle(a)              shuffle(a.begin(), a.end(), rng)
#define mtrand(a,b)             uniform_int_distribution<int>(a, b)(rng)


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e6 + 5;


// 1-base indexing
void combine(int& x, int& y, int& res) {
    res = x + y;
}
template <typename T>
class SegmentTree {
private:
    T* segm;
    int N;
    void (*merge)(T&, T&, T&);
    void buildtree(int cur, int start, int end, T a[]) {
        if (start == end) {
            //BASE CASE
            segm[cur] = a[start];
            return;
        }
        int mid = (start + end) >> 1;
        buildtree(cur << 1, start, mid, a);
        buildtree((cur << 1) ^ 1, mid + 1, end, a);
        //MERGING STEP
        (*merge)(segm[(cur << 1)], segm[(cur << 1) ^ 1], segm[cur]);

    }
    T query(int cur, int start, int end, int qs, int qe) {
        if (start >= qs && end <= qe)
            return segm[cur];
        if (start > qe || end < qs)
            return T(0);          //INVALID RETURN
        int mid = (start + end) >> 1;
        T A = query((cur << 1) , start, mid, qs, qe);
        T B = query((cur << 1) ^ 1, mid + 1, end, qs, qe);
        //MERGING STEP
        T res;
        (*merge)(A, B, res);

        return res;
    }
    void update(int cur, int start, int end, int ind, T val) {
        if (start == ind && start == end) {
            //DO UPDATE
            segm[cur] = val;
            return;
        }
        if (start > ind || end < ind)
            return;          //OUT OF RANGE
        int mid = (start + end) >> 1;
        update(cur << 1, start, mid, ind, val);
        update((cur << 1) ^ 1, mid + 1, end, ind, val);
        //MERGING STEP
        (*merge)(segm[(cur << 1)], segm[(cur << 1) ^ 1], segm[cur]);

    }
public:

    SegmentTree(int n, void (*fun)(T&, T&, T&) = &combine) {
        N = n;
        segm = new T[4 * (N + 1)]();
        merge = fun;

    }
    SegmentTree(int a[], int n, void (*fun)(T&, T&, T&) = &combine) {
        N = n;
        segm = new T[4 * (N + 1)]();
        merge = fun;
        buildtree(1, 1, N, a);
    }
    T query(int l, int r) {
        return query(1, 1, N, l, r);
    }
    void update(int ind, T val) {
        update(1, 1, N, ind, val);
    }

};

SegmentTree<int>vert(MX);
SegmentTree<int>horz(MX);
int n, m, k;
void solve() {

    cin >> n >> m >> k;
    set<int>v;
    set<int>h;
    repe(i, n) {
        int x;
        cin >> x;
        v.insert(x);
    }
    repe(i, m) {
        int y;
        cin >> y;
        h.insert(y);
    }
    vector<pii>P;
    rep(i, k) {
        int x, y;
        cin >> x >> y;
        if (!(v.count(x) && h.count(y))) {
            vert.update(x, 1);
            horz.update(y, 1);
            P.pb({x, y});
        }

    }
    sort(all(P));
    int ans = 0;
    for (auto &el : P) {
        int x = el.ff;
        int y = el.ss;
        cout << x << " " << y << ": ";
        if (v.count(x)) {
            auto it = h.lower_bound(y);
            // assert(it!=h.begin());
            it--;
            auto it2 = h.upper_bound(y);
            int l = *it, r = *it2;
            int here = horz.query(l + 1, r - 1 );
            ans += here;
            cout << l << " " << r << "->";
            cout << here << "\n";

        }
        else {
            auto it = v.lower_bound(x);
            // assert(it!=v.begin());
            it--;
            auto it2 = v.upper_bound(x);
            int l = *it, r = *it2;
            int here = vert.query(l + 1, r - 1);
            ans += here;
            cout << l << " " << r << "->";
            cout << here << "\n";
        }
    }
    ans >>= 1;

    cout << ans << "\n";



}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}