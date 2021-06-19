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
const int MX = 2e5 + 5;



// vector<int> segm[4 * MX];

// int query(int cur, int start, int end, int qs, int qe, int l, int r) {
//     if(qs>qe)
//         return 0;    
//     if (start >= qs && end <= qe) {
        
//     }
//     if (start > qe || end < qs)
//         return 0;          //INVALID RETURN
//     int mid = (start + end) >> 1;
//     int A = query(2 * cur, start, mid, qs, qe,l,r);
//     int B = query(2 * cur + 1, mid + 1, end, qs, qe,l,r);
//     //MERGING STEP
//     int res = A + B;

//     return res;
// }
// void buildtree(int cur, int start, int end) {
//     if (start == end) {
//         //DO UPDATE
//         segm[cur].pb(a[start]);
//         return;
//     }
    
//     int mid = (start + end) >> 1;
//     buildtree(cur << 1, start, mid);
//     buildtree((cur << 1) ^ 1, mid + 1,end);
//     int i=0,j=0;
//     int sz1=segm[2*cur].size(),sz2=segm[2*cur+1].size();
//     while(i<sz1 && j<sz2){
//         if(segm[2*cur][i]<=segm[2*cur+1][j])
//             segm[cur].pb(segm[2*cur][i]),i++;
//         else
//             segm[cur].pb(segm[2*cur+1][j]),j++;

//     }
//     while(i<sz1)
//         segm[cur].pb(segm[2*cur][i]),i++;
//     while(j<sz2)
//         segm[cur].pb(segm[2*cur+1][j]),j++;
//     //MERGING STEP

// }


void solve() {

    int n, l, r;
    cin >> n >> l >> r;
    int a[n+1];
    // repe(i,4*n)
    //     segm[i].clear();
    repe(i, n)
        cin >> a[i];
    // repe(i,n)
    //     cout<<a[i]<<" \n"[i==n];
    sort(a+1,a+n+1);
    // buildtree(1,1,n);
    int ans=0;
    repe(i,n){
        int lb = i;
        int ub = i;
        int L=i+1,R=n;
        int mid;
        while(L<=R){
            mid=(L+R)>>1;
            if(a[mid]>=(l-a[i]))
                lb=mid,R=mid-1;
            else
                L=mid+1;
        }
        L=i+1;
        R=n;
        while(L<=R){
            mid=(L+R)>>1;
            if(a[mid]<=(r-a[i]))

                ub=mid,L=mid+1;
            else
                R=mid-1;
        }
        if(lb==i || ub==i)
            continue;
        ans+= ub - lb+1;
    }
    cout<<ans<<'\n';

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