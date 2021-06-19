//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
#define int                 long long
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define PB                  push_back
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
#define M2 998244353
#define M 998244353
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define V(ll)               vector<ll>


auto time0 = curtime;
const int MX = 2e5 + 2,G=3;
const int maxn=(1<<18);
int iv[maxn+1];


// NTT -Credits :tmwilliam && EnEm
ll powM(ll b, int p) {
    ll r=1;
    while(p) {
        if(p&1)
            r=r*b%M;
        b=b*b%M;
        p>>=1;
    }
    return r;
}
ll modI(ll a)
{
    return (a>maxn)?powM(a,M-2):iv[a];   
}
struct ntt {
    ll rt[maxn];
    void fi(int n) {
        rt[n>>1]=1;
        rt[(n>>1)+1]=powM(G, (M-1)/n);
        for(int i=(n>>1)+2; i<n; ++i)
            rt[i]=rt[i-1]*rt[(n>>1)+1]%M;
        for(int i=(n>>1); --i; )
            rt[i]=rt[i<<1];
    }
    void ac(vector<ll> &a) {
        int n=a.size();
        for(int i=0, j=0; i<n; ++i) {
            if(i>j)
                swap(a[i], a[j]);
            for(int k=(n>>1); (j^=k)<k; (k>>=1));
        }
        for(int st=1; (st<<1)<=n; st<<=1) {
            for(int i=0; i<n; i+=(st<<1)) {
                for(int j=i; j<i+st; ++j) {
                    ll z=rt[j-i+st]*a[j+st]%M;
                    a[j+st]=a[j]-z;
                    if(a[j+st]<0)
                        a[j+st]+=M;
                    a[j]+=z;
                    if(a[j]>=M)
                        a[j]-=M;
                }
            }
        }
    }
};
ntt nt;
void mult2(vector<ll>& v, vector<ll>& w) {
    int s=v.size()+w.size()-1, t=1;
    while(t<s)
        t<<=1;
    v.resize(t);
    w.resize(t);
    nt.ac(v);
    nt.ac(w);
    for(int i=0; i<t; ++i)
        v[i]=v[i]*w[i]%M*modI(t)%M;
    reverse(v.begin()+1, v.end());
    nt.ac(v);
    while(v.back()==0)
        v.pop_back();
  
}

void mult(vector<ll>& v, vector<ll>& w,vector<int>& res) {
    int s=v.size()+w.size()-1, t=1;
    while(t<s)
        t<<=1;
    res=v;
    vector<int>b=w;
    res.resize(t);
    b.resize(t);
    nt.ac(res);
    nt.ac(b);
    for(int i=0; i<t; ++i)
        res[i]=res[i]*b[i]%M*modI(t)%M;
    reverse(res.begin()+1, res.end());
    nt.ac(res);
    // cout<<res.size()<<'\n';
    while(res.back()==0)
        res.pop_back();
 
}



void PolyInverse(V(ll) &a, V(ll) &v, ll n)
{
    v.clear();
    v.PB(modI(a[0]));
    while (((ll)v.size()) < n)
    {
        ll tmpsz = (((ll)v.size()) << 1);
        V(ll) tmpa(tmpsz, 0LL);
        REP(i, 0, min(((ll)a.size()), tmpsz))
        {
            tmpa[i] = a[i];
        }
        V(ll) tmppr;
        mult(tmpa, v, tmppr);
        tmppr.resize(tmpsz, 0LL);
        REP(i, 0, tmpsz)
        {
            tmppr[i] = ((M - tmppr[i]) % M);
        }
        tmppr[0] = ((tmppr[0] + 2) % M);
        V(ll) tmpv(v.begin(), v.end());
        mult(tmppr, tmpv, v);
        v.resize(tmpsz, 0LL);
    }
    v.resize(n, 0LL);
    return;
}

void PolyDiv(V(ll) &a, V(ll) &b, V(ll) &q, V(ll) &r)
{
    if (((ll)a.size()) < ((ll)b.size()))
    {
        r = a;
        r.resize(((ll)b.size()) - 1, 0LL);
        q.clear();
        q.PB(0LL);
        return;
    }
    V(ll) ra(((ll)a.size()) - ((ll)b.size()) + 1, 0LL);
    REP(i, 0, ((ll)a.size()) - ((ll)b.size()) + 1)
    {
        ra[i] = a[((ll)a.size()) - 1 - i];
    }
    V(ll) rb(((ll)b.size()), 0LL);
    REP(i, 0, ((ll)b.size()))
    {
        rb[i] = b[((ll)b.size()) - 1 - i];
    }
    V(ll) irb;
    PolyInverse(rb, irb, ((ll)a.size()) - ((ll)b.size()) + 1);
    V(ll) rq;
    mult(ra, irb, rq);
    rq.resize(((ll)a.size()) - ((ll)b.size()) + 1, 0LL);
    q.resize(((ll)a.size()) - ((ll)b.size()) + 1, 0LL);
    REP(i, 0, ((ll)rq.size()))
    {
        q[i] = rq[((ll)rq.size()) - 1 - i];
    }
    V(ll) tmppr;
    mult(b, q, tmppr);
    r.resize(((ll)b.size()) - 1, 0LL);
    REP(i, 0, ((ll)r.size()))
    {
        r[i] = ((a[i] + M - tmppr[i]) % M);
    }
    return;
}

int r, k,a[MX];
vector<int> segm[4*MX];
int readInt () {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

vector<int> fn2(int l,int r){
    if (l == r) {
        return { (M-a[l])%M, 1};
    }
    int mid = (l + r) / 2;
    vector<int> lef = fn2(l, mid);
    vector<int> righ = fn2(mid + 1, r);
    vector<int>res;
    mult(lef, righ, res);
    return res;
}
void buildtree(int cur,int start,int end){
    vector<int>q,b=fn2(start,end);
    PolyDiv(segm[cur>>1],b,q,segm[cur]);
    
    if(start==end){
        a[start]=segm[cur][0];
        return;
    }
    int mid=(start)+(end-start)/2;
    buildtree(cur<<1,start,mid);
    buildtree((cur<<1)^1,mid+1,end);

}

vector<int> fn(int l, int r) {
    if (l == r) {
        return { -l, 1};
    }
    int mid = (l + r) / 2;
    vector<int> lef = fn(l, mid);
    vector<int> righ = fn(mid + 1, r);
    mult2(lef, righ);
    return lef;
}
void solve() {
    r=readInt();
    k=readInt();
    // cout<<r<<" "<<k<<'\n';
    // return;
    int denm = 1;
    FOR(i, 2, r)
        denm = (denm * modI(i)) % M;
    
    segm[0] = fn(0, r - 1);
    // for (auto &el : segm[0]) {
    //     cout << el << " ";
    // }
    // // cout<<r<<" "<<k<<'\n';
    // return;
    repe(i, k){
        a[i]=readInt();
        
    }
    buildtree(1,1,k);
    repe(i,k)
        a[i] = (a[i] * denm) % M;

    int ans = 1,pi;
    repe(i, k) {
        pi=readInt();
        ans = (ans * ((((M + 1 - pi) % M ) + a[i ] * pi) % M)) % M;
    }
    cout << ans << '\n';


}


int32_t main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t = 1;
    nt.fi(maxn);
    iv[1]=1;
    for(int i=2; i<=maxn; ++i)
        iv[i]=M-M/i*iv[M%i]%M;

    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}