#define V(ll)   vector<ll>
#define ll      long long
const int M = 998244353;
const int MX = 2e5 + 2, G = 3;
const int maxn = (1 << 18);
int iv[maxn + 1];


// NTT -Credits :tmwilliam && EnEm
ll powM(ll b, int p) {
    ll r = 1;
    while (p) {
        if (p & 1)
            r = r * b % M;
        b = b * b % M;
        p >>= 1;
    }
    return r;
}
ll modI(ll a)
{
    return (a > maxn) ? powM(a, M - 2) : iv[a];
}
struct ntt {
    ll rt[maxn];
    void fi(int n) {
        rt[n >> 1] = 1;
        rt[(n >> 1) + 1] = powM(G, (M - 1) / n);
        for (int i = (n >> 1) + 2; i < n; ++i)
            rt[i] = rt[i - 1] * rt[(n >> 1) + 1] % M;
        for (int i = (n >> 1); --i; )
            rt[i] = rt[i << 1];
    }
    void ac(vector<ll> &a) {
        int n = a.size();
        for (int i = 0, j = 0; i < n; ++i) {
            if (i > j)
                swap(a[i], a[j]);
            for (int k = (n >> 1); (j ^= k) < k; (k >>= 1));
        }
        for (int st = 1; (st << 1) <= n; st <<= 1) {
            for (int i = 0; i < n; i += (st << 1)) {
                for (int j = i; j < i + st; ++j) {
                    ll z = rt[j - i + st] * a[j + st] % M;
                    a[j + st] = a[j] - z;
                    if (a[j + st] < 0)
                        a[j + st] += M;
                    a[j] += z;
                    if (a[j] >= M)
                        a[j] -= M;
                }
            }
        }
    }
};
ntt nt;
void mult2(vector<ll>& v, vector<ll>& w) {
    int s = v.size() + w.size() - 1, t = 1;
    while (t < s)
        t <<= 1;
    v.resize(t);
    w.resize(t);
    nt.ac(v);
    nt.ac(w);
    for (int i = 0; i < t; ++i)
        v[i] = v[i] * w[i] % M * modI(t) % M;
    reverse(v.begin() + 1, v.end());
    nt.ac(v);
    while (v.back() == 0)
        v.pop_back();

}

void mult(vector<ll>& v, vector<ll>& w, vector<int>& res) {
    int s = v.size() + w.size() - 1, t = 1;
    while (t < s)
        t <<= 1;
    res = v;
    vector<int>b = w;
    res.resize(t);
    b.resize(t);
    nt.ac(res);
    nt.ac(b);
    for (int i = 0; i < t; ++i)
        res[i] = res[i] * b[i] % M * modI(t) % M;
    reverse(res.begin() + 1, res.end());
    nt.ac(res);
    // cout<<res.size()<<'\n';
    while (res.back() == 0)
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

void init() {
    nt.fi(maxn);
    iv[1] = 1;
    for (int i = 2; i <= maxn; ++i)
        iv[i] = M - M / i * iv[M % i] % M;
}