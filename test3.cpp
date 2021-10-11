//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                     unsigned long long
#define ll                      long long
#define int                     long long
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
const int MX = 3e5 + 5;


// 1-base indexing
void combine(int& x,int& y,int& res){
    res=(x+y)%MDL;
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
            segm[cur] = (segm[cur]+val)%MDL;
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
        segm = new T[4*(N + 1)]();
        merge = fun;

    }
    SegmentTree(int a[], int n,void (*fun)(T&, T&, T&) = &combine) {
        N = n;
        segm = new T[4*(N + 1)]();
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
int pow2[MX];
int invpow2[MX];
ll bin_power(ll a,ll b,ll md){
    ll res=1;
    while (b){
        if (b&1)
            res=(res*a)%md;
        a=(a*a)%md;
        b>>=1;
    }
    return res;
}
void solve() {

    int n;
    cin>>n;
    int nax=1;
    int a[n+1];
    map<int,int>mp;
    repe(i,n){
        cin>>a[i];
        mp[a[i]];
    }    
    for(auto& el:mp)
        el.ss=nax++;
    repe(i,n)
        a[i]=mp[a[i]];

    SegmentTree<int>ST(nax);
    int ans=0;
    repe(i,n){
        int x=a[i];
        int qu=ST.query(1,x);
        ans=(ans+qu*pow2[i])%MDL;
        ST.update(x,invpow2[i+1]);
    }
    cout<<ans<<"\n";



}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    // cin >> t;
    pow2[0]=1;
    invpow2[0]=1;
    repe(i,MX-1){
        pow2[i]=(2*pow2[i-1])%MDL;
        invpow2[i]=bin_power(pow2[i],MDL-2,MDL);
    }
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}