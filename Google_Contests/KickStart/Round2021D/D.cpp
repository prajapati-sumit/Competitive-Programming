//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
#define int                 long long
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




auto time0 = curtime;
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 5e5 + 5;
struct Node {
    int ze, nz, cnt;
};
struct Node2{
    int def,amb,apb,cnt;
};
int n, q, p;
int a[MX];
Node segm[4 * MX];
Node2 segm2[4*MX];
int V(int x,int pr=p) {
    // return 0;
    if(x==0)
        return 0;
    int res = 0;
    while (x % pr == 0){
        res++, x /= pr;
    }

    return res;
}
void buildtree(int cur, int start, int end) {
    if (start == end) {
        //BASE CASE
        if (a[start] % p == 0) {
            segm[cur] = {V(a[start]), 0, 0,};
        }
        else {
            segm[cur] = {0, V(a[start] - (a[start] % p)), a[start]>p};
        }
        if(a[start]%2==0){
            segm2[cur]={V(a[start],2),0,0,0};
        }

        else{
            segm2[cur]={0,V(a[start]-(a[start]%2),2),V(a[start]+(a[start]%2),2),a[start]>2};
        }

        return;
    }
    int mid = (start + end) >> 1;
    buildtree(cur << 1, start, mid);
    buildtree((cur << 1) + 1, mid + 1, end);
    //MERGING STEP
    segm[cur].ze = segm[2 * cur].ze + segm[2 * cur + 1].ze;
    segm[cur].nz = segm[2 * cur].nz + segm[2 * cur + 1].nz;
    segm[cur].cnt = segm[2 * cur].cnt + segm[2 * cur + 1].cnt;

    segm2[cur].def = segm2[2 * cur].def + segm2[2 * cur + 1].def;
    segm2[cur].amb = segm2[2 * cur].amb + segm2[2 * cur + 1].amb;
    segm2[cur].apb = segm2[2 * cur].apb + segm2[2 * cur + 1].apb;
    segm2[cur].cnt = segm2[2 * cur].cnt + segm2[2 * cur + 1].cnt;

}
Node query(int cur, int start, int end, int qs, int qe) {
    if (start >= qs && end <= qe)
        return segm[cur];
    if (start > qe || end < qs)
        return {0,0,0};         //INVALID RETURN
    int mid = (start + end) >> 1;
    Node A = query(2 * cur, start, mid, qs, qe);
    Node B = query(2 * cur + 1, mid + 1, end, qs, qe);
    //MERGING STEP
    Node res = {A.ze + B.ze, A.nz + B.nz,A.cnt+B.cnt};
    return res;
}
Node2 query2(int cur, int start, int end, int qs, int qe) {
    if (start >= qs && end <= qe)
        return segm2[cur];
    if (start > qe || end < qs)
        return {0,0,0,0};         //INVALID RETURN
    int mid = (start + end) >> 1;
    Node2 A = query2(2 * cur, start, mid, qs, qe);
    Node2 B = query2(2 * cur + 1, mid + 1, end, qs, qe);
    //MERGING STEP
    Node2 res = {A.def+B.def,A.amb + B.amb, A.apb + B.apb,A.cnt+B.cnt};
    return res;
}
void update(int cur, int start, int end, int ind, int val) {
    if (start == ind && start == end) {
        //DO UPDATE
        if (a[start] % p == 0) {
            segm[cur] = {V(a[start]), 0, 0};
        }
        else {
            segm[cur] = {0, V(a[start] - (a[start] % p)), a[start]>p};
        }
        if(a[start]%2==0){
            segm2[cur]={V(a[start],2),0,0,0};
        }

        else{
            segm2[cur]={0,V(a[start]-(a[start]%2),2),V(a[start]+(a[start]%2),2),a[start]>2};
        }
        return;
    }
    if (start > ind || end < ind)
        return;          //OUT OF RANGE
    int mid = (start + end) >> 1;
    update(cur << 1, start, mid, ind, val);
    update((cur << 1) ^ 1, mid + 1, end, ind, val);
    //MERGING STEP
    segm[cur].ze = segm[2 * cur].ze + segm[2 * cur + 1].ze;
    segm[cur].nz = segm[2 * cur].nz + segm[2 * cur + 1].nz;
    segm[cur].cnt = segm[2 * cur].cnt + segm[2 * cur + 1].cnt;

    segm2[cur].def = segm2[2 * cur].def + segm2[2 * cur + 1].def;
    segm2[cur].amb = segm2[2 * cur].amb + segm2[2 * cur + 1].amb;
    segm2[cur].apb = segm2[2 * cur].apb + segm2[2 * cur + 1].apb;
    segm2[cur].cnt = segm2[2 * cur].cnt + segm2[2 * cur + 1].cnt;
}




void solve() {

    cin >> n >> q >> p;
    repe(i, n)
        cin >> a[i];

    buildtree(1, 1, n);

    repe(i, q) {
        int ty;
        cin >> ty;
        if (ty == 1) {
            int x, y;
            cin >> x >> y;
            a[x] = y;
            update(1, 1, n, x, y);
        }
        else {
            int s, l, r;
            cin >> s >> l >> r;
            if(p==2 && s%2==0){
                Node2 res=query2(1,1,n,l,r);
                // cout<<res.def<<" "<<res.amb<<" "<<res.amb<<" "<<res.cnt<<'\n';
                int ans=s*res.def+res.amb+res.apb+(res.cnt)*(V(s)-1);
                cout<<ans<<' ';
            }
            else{
                Node res = query(1, 1, n, l, r);
                int ans = (s * res.ze) + (res.cnt * V(s) + res.nz);
                cout << ans << ' ';
            }
        }
    }
    cout<<'\n';

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t = 1;
    cin >> t;
    repe(tt, t) {
        cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}