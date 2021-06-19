//~ author      : Sumit Prajapati
//~ mail ID     : sumitprajapati821@gmail.com
//~ codeforces   : sumitprajapati81, codechef: sumit141
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
// #define int                 long long
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


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0, 0xFFFFFFFFFFFFFFFF);

stringstream sst;
int gl_ans;
void fastscan(int &x)
{
    
    int c;
    x = 0;
    c = getchar();
    for (; (c > 47 && c < 58); c = getchar())
        x = (x << 1) + (x << 3) + c - 48;
}
void findIt(int n, int k, int tar) {
    // cerr<<n<<" "<<k<<" "<<tar<<'\n';

    if(k==(n-1)){
        repe(i,n)
            if(i!=tar)
                gl_ans^=i,sst<<i<<" ";
        return;
    }
    else if(k==(n-2)){
        int f=-1,s=-1;
        repe(i,n){
            f=i;
            s=tar^i;
            if(f!=0 && s!=0)
                break;
        }
        // cerr<<f<<" "<<s<<'\n';
        assert((f+s)!=-2);
        repe(i,n)
            if(i!=f && i!=s)
                gl_ans^=i,sst<<i<<" ";
        return;
    }
    assert(false);


}

void solve(int n,int k) {
    // brute2();
    // cin >> n >> k;
    
    // fastscan(n);
    // fastscan(k);
    // OP BIRRRROOOO
    int f=-1,res=0,temp_res=-1;

    if (k == 1) {
        sst << n<<" " ;
        gl_ans=n;
        return;
    }
    if (k == n) {
        repe(i, n)
            gl_ans^=i,sst << i << " ";

        return;
    }
    if(k==(n-1)){
        repe(i,n)
            res^=i;
        repe(i,n)
            if(temp_res<(res^i)){
                temp_res=res^i;
                f=i;
            }
        assert(f!=-1);
        repe(i,n)
            if(i!=f)
                gl_ans^=i,sst<<i<<" ";
        return;
    }

    int d = 0;
    while ((1 << d) <= n)
        d++;
    int center = (1 << (d - 1));
    int best = (1 << d) - 1;

    if(n==(best-1) && k==(n-2)){
        assert(n>3);
        repe(i,n)
            if(i!=2 && i!=3)
                gl_ans^=i,sst<<i<<" ";
        return;
    }



    if (k < (center)) {
        solve(center - 1, k - 1);
        gl_ans^=center;
        sst << center << " ";
        return;
    }

    // cerr<<n<<" "<<k<<"\n";
    if (k & 1) {
        int res = 0;
        int temp = k - (center - 2);

        for (int r = center; temp > 0; r++, temp--) {
            assert(r <= n);
            if(r==(best-1)){
                temp++;
                continue;
            }
            res ^= r;
            sst << r << " ";
        }
        assert(res!=best);
        gl_ans^=res;
        findIt(center - 1, center - 2, best ^ res);
    }
    else {
        int res = 0;
        int temp = k - (center - 3);

        for (int r = center; temp > 0; r++, temp--) {

            assert(r <= n);
            if(r==(best-1)){
                temp++;
                continue;
            }
            res ^= r;
            sst << r << " ";
        }
        gl_ans^=res;
        // cerr<<res<<" "<<(best^res)<<'\n';
        assert(res!=best);
        findIt(center - 1, center - 3, best ^ res);
    }



}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    time0 = curtime;
    srand(time(NULL));
    int t = 1;
    // cin >> t;
    fastscan(t);
    int n,k;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        gl_ans=0;
        fastscan(n);
        fastscan(k);
        solve(n,k);
        sst<<'\n';
        // cout<<gl_ans<<'\n';
    }

    cout<<sst.str();
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}