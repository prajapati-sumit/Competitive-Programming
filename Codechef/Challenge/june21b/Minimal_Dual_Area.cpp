//~ author      : Sumit Prajapati
//~ mail ID     : sumitprajapati821@gmail.com
//~ codefoces   : sumitprajapati81, codechef: sumit141
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define int                 long long
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define debug(x)            cerr<<#x<<" = "<<x<<'\n'
#define llrand()            distribution(generator)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define left                lef
#define right               righ


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0, 0xFFFFFFFFFFFFFFFF);

const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e18 + 5;
const int MX = 1e5 + 5;


struct Point {
    int x;
    int y;

} a[MX];

int n;
int segmmax[4 * MX];
int segmmin[4 * MX];
int ans;
int query(int cur, int start, int end, int qs, int qe, bool flag) {
    if (start >= qs && end <= qe)
        return flag ? segmmin[cur] : segmmax[cur];
    if (start > qe || end < qs)
        return flag ? INF : -1;      //INVALID RETURN
    int mid = (start + end) >> 1;
    int A = query(2 * cur, start, mid, qs, qe, flag);
    int B = query(2 * cur + 1, mid + 1, end, qs, qe, flag);
    //MERGING STEP
    int res = flag ? min(A, B) : max(A, B);

    return res;
}
void update(int cur, int start, int end, int ind, int val, bool flag) {
    if (start == ind && start == end) {
        //DO UPDATE
        if (flag)
            segmmin[cur] = val;
        else
            segmmax[cur] = val;
        return;
    }
    if (start > ind || end < ind)
        return;          //OUT OF RANGE
    int mid = (start + end) >> 1;
    update(cur << 1, start, mid, ind, val, flag);
    update((cur << 1) ^ 1, mid + 1, end, ind, val, flag);
    if (flag)
        segmmin[cur] = min(segmmin[2 * cur], segmmin[2 * cur+1] );
    else
        segmmax[cur] = max(segmmax[2 * cur], segmmax[2 * cur+1] );
    //MERGING STEP

}


void forX() {
    sort(a + 1, a + n + 1, [&](auto p, auto q) {
        return p.x == q.x ? p.y < q.y : p.x < q.x;
    });
    repe(i, n) {
        update(1, 1, n, i, a[i].y, 0);
        update(1, 1, n, i, a[i].y, 1);
    }
    for (int i = 1; i <= n - 1; i++) {
        int x1 = a[i].x, x2 = a[i + 1].x;
        int ftop = query(1, 1, n, 1, i, 0);
        int fbottom = query(1, 1, n, 1, i, 1);
        int stop = query(1, 1, n, i + 1, n, 0);
        int sbottom = query(1, 1, n, i + 1, n, 1);
        int here = (x1 - a[1].x) * (ftop - fbottom) + (a[n].x - x2) * (stop - sbottom);
            

        ans = min(ans, here);
    }

}
void forY() {
    sort(a + 1, a + n + 1, [&](auto p, auto q) {
        return p.y == q.y ? p.x < q.x : p.y < q.y;
    });
    repe(i, n) {
        update(1, 1, n, i, a[i].x, 0);
        update(1, 1, n, i, a[i].x, 1);
    }
    for (int i = 1; i <= n - 1; i++) {
        int y1 = a[i].y, y2 = a[i + 1].y;
        int ftop = query(1, 1, n, 1, i, 0);
        int fbottom = query(1, 1, n, 1, i, 1);
        int stop = query(1, 1, n, i + 1, n, 0);
        int sbottom = query(1, 1, n, i + 1, n, 1);
        int here = (y1 - a[1].y) * (ftop - fbottom) + (a[n].y - y2) * (stop - sbottom);
        // cout<<y1<<" "<<a[i].x<<"-> ";
        // cout<<ftop<<" "<<fbottom<<" "<<stop<<" "<<sbottom<<" :"<<here<<'\n';  
        ans = min(ans, here);
    }
}



void solve() {


    cin >> n;
    int x, y, here;
    repe(i, n) {
        cin >> a[i].x >> a[i].y;
    }
    if (n == 1) {
        cout << "0\n";
        return;
    }
    ans = INF;
    forX();
    forY();
    cout << ans << '\n';

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t = 1;
    cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}