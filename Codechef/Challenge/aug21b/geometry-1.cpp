//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
// #define ll                  long long
#define ld                  long double
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
const int MX = 1e4 + 5;

const ld PI = acos(-1);
const ld infsm = 1e-9;
struct Point {
    ld x;
    ld y;
};

ld dist(const Point& A, const Point& B) {
    ld d = (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
    d = sqrtl(d);
    return d;
}

int n, q;

// cp-algorithms.com
ld calc_area(const vector<Point>& fig) {
    ld res = 0;
    for (int i = 0; i < n; i++) {
        Point p = fig[(i + n - 1) % n];
        Point q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return fabs(res) / 2.0;
}
ld calc_perimeter(const vector<Point>& fig) {
    ld res = 0;
    for (int i = 0; i < fig.size(); i++) {
        Point p = fig[(i + n - 1) % n];
        Point q = fig[i];
        res += dist(p, q);
    }
    return res;
}
ld addcothalf( Point& A,  Point& B,  Point& C) {

    A.x-=B.x;
    A.y-=B.y;
    C.x-=B.x;
    C.y-=B.y;
    ld dot=A.x*C.x+A.y*C.y;
    dot/=(dist(A,{0,0})*dist(C,{0,0}));
    dot=max(dot,(ld)-1.0);
    dot=min(dot,(ld)1.0);
    // assert(dot>=-1.0 && dot<=1.0);
    ld angle=acos(dot);
    angle=max((ld)0.0,angle);
    angle=min(PI,angle);
    // assert(angle>=0 && angle<=PI);
    return 1/tan(angle/2.0);    
}
ld sum_of_cotangles(const vector<Point>& fig) {
    ld res = 0;
    for (int i = 0; i < n; i++) {
        Point pr = fig[(i + n - 1) % n];
        Point cr = fig[i];
        Point nx = fig[(i + n + 1) % n];
        res += addcothalf(pr, cr, nx);
    }
    return fabs(res);
}
void solve() {

    cin >> n >> q;
    vector<Point> P(n);
    rep(i, n)
    cin >> P[i].x >> P[i].y;
    ld area = calc_area(P);
    ld perimeter = calc_perimeter(P);
    ld cothalf = sum_of_cotangles(P);
    ld ans;
    repe(i, q) {
        ld t, v;
        cin >> t >> v;
        ld r = t * v;
        ld ans = area + r * perimeter + r * r * cothalf;
        cout << ans << '\n';
    }

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(10) << fixed;
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