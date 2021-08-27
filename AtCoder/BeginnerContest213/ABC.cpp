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
const int MX = 1e5 + 5;



struct Node{
    int r;
    int c;
    int i;
};

void solve() {

    int h,w;
    cin>>h>>w;
    int n;
    cin>>n;
    Node a[n+1];
    Node ans[n+1];
    repe(i,n){
        cin>>a[i].r>>a[i].c;
        a[i].i=i;
        ans[i]=a[i];
    }
    sort(a+1,a+n+1,[&](auto p,auto q){
        if (p.r==q.r)
            return p.c<q.c;
        return p.r<q.r;
    });
    int spaces=0,pre=0;
    repe(i,n){
        spaces+=max(0LL,a[i].r-pre-1);
        // if(a[i].r==3 && a[i].c==5){
        //     cout<<spaces<<" "<<pre<<'\n';
        // }
        // cout<<spaces<<" "<<pre<<"&\n";
        ans[a[i].i].r=(a[i].r-spaces);
        pre=a[i].r;
    }
    sort(a+1,a+n+1,[&](auto p,auto q){
        if (p.c==q.c)
            return p.r<q.r;
        return p.c<q.c;
    });
    spaces=0;
    pre=0;
    repe(i,n){
        spaces+=max(0LL,(a[i].c-pre-1));
        // cout<<spaces<<" "<<pre<<"\n";
        ans[a[i].i].c=(a[i].c-spaces);
        pre=a[i].c;
    }
    repe(i,n)
        cout<<ans[i].r<<" "<<ans[i].c<<'\n';

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    // cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}