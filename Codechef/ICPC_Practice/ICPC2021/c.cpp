//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
// #define ll                  long long
#define ld                  long double
#define int                 long long
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

vector<int> segm[4 * MX];

string s;
int n;

void merge(vector<int> &A, vector<int> &B, vector<int> &res) {
    rep(i, 26)
    res[i] = A[i] | B[i];

}
void buildtree(int cur, int start, int end) {
    if (start == end) {
        //BASE CASE
        segm[cur].resize(26, 0);
        segm[cur][s[start] - 'a'] = 1;
        return;
    }
    int mid = (start + end) >> 1;
    buildtree(cur << 1, start, mid);
    buildtree((cur << 1) + 1, mid + 1, end);
    //MERGING STEP
    segm[cur].resize(26, 0);
    merge(segm[2 * cur], segm[2 * cur + 1], segm[cur]);

}
vector<int> query(int cur, int start, int end, int qs, int qe) {
    if (start >= qs && end <= qe)
        return segm[cur];
    if (start > qe || end < qs) {
        vector<int>fake(26, 0);
        return fake;          //INVALID RETURN
    }
    int mid = (start + end) >> 1;
    vector<int> A = query(2 * cur, start, mid, qs, qe);
    vector<int> B = query(2 * cur + 1, mid + 1, end, qs, qe);
    //MERGING STEP
    vector<int> res(26, 0);
    merge(A, B, res);

    return res;
}
void update(int cur, int start, int end, int ind, int val) {
    if (start == ind && start == end) {
        //DO UPDATE
        segm[cur][s[ind] - 'a'] += val;
        return;
    }
    if (start > ind || end < ind)
        return;          //OUT OF RANGE
    int mid = (start + end) >> 1;
    update(cur << 1, start, mid, ind, val);
    update((cur << 1) ^ 1, mid + 1, end, ind, val);
    //MERGING STEP
    merge(segm[2 * cur], segm[2 * cur + 1], segm[cur]);

}





void solve() {

    cin >> s;
    n = s.length();
    repe(i, 4 * n)
    segm[i].clear();
    vector<int>v[26];
    vector<int>done(26, -1);
    for (int i = n - 1; i >= 0; i--) {
        int x = s[i] - 'a';
        v[x].pb(i);
        done[x] = 0;
    }

    buildtree(1, 0, n - 1);
    string res;
    while (true) {
        bool alldone = true;
        rep(i, 26)
        if (done[i] == 0) {
            alldone = false;
            break;
        }
        if (alldone)
            break;
        rep(j, 26) {
            if (!v[j].empty()) {
                int fir = v[j].back();
                vector<int>here = query(1, 0, n - 1, fir + 1, n - 1);
                bool ok = true;
                rep(k, 26) {
                    if (k != j && done[k] != -1 && done[k] == 0 && here[k] == 0) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    res.pb(j + 'a');
                    rep(k, 26)
                    while (!v[k].empty() && v[k].back() <= fir)
                        v[k].pop_back();

                    update(1, 0, n - 1, fir, -1);
                    done[j] = 1;
                    break;
                }
            }
        }


    }
    cout << res << '\n';

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