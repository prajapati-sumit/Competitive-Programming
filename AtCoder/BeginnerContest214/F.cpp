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
const int MX = 2e5 + 5;


int segm[4*MX];

void merge(int &A,int &B,int &res){
    res=(A+B)%MD;
}

int query(int cur,int start,int end,int qs,int qe){
    if(start>=qs && end<=qe)
        return segm[cur];
    if(start>qe || end<qs)
        return 0;          //INVALID RETURN 
    int mid=(start+end)>>1;
    int A=query(2*cur,start,mid,qs,qe);
    int B=query(2*cur+1,mid+1,end,qs,qe);
    //MERGING STEP
    int res;
    merge(A,B,res);  

    return res;
}
void update(int cur,int start,int end,int ind,int val){
    if(start==ind && start==end){
        //DO UPDATE
        segm[cur]=val;
        return;
    }
    if(start>ind|| end<ind)
        return;          //OUT OF RANGE 
    int mid=(start+end)>>1;
    update(cur<<1,start,mid,ind,val);
    update((cur<<1)^1,mid+1,end,ind,val);
    //MERGING STEP
    merge(segm[2*cur],segm[2*cur+1],segm[cur]);

}
 



void solve() {

    string s;
    cin>>s;
    int n=s.length();
    vector<int>last(26,0);
    // dp[0]=1;
    update(1,0,n,0,1);
    update(1,0,n,1,1);
    last[s[0]-'a']=1;
    FOR(i,1,n){
        int k=last[s[i-1+1]-'a'];
        int here=query(1,0,n,k,i-1);
        last[s[i-1+1]-'a']=i;
        update(1,0,n,i+1,here);
    }
    // FOR(i,0,n)
    //     cout<<i<<" "<<query(1,0,n,i,i)<<'\n';
    int ans=query(1,0,n,1,n);
    cout<<ans<<'\n';


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