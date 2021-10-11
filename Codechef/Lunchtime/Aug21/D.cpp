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

int segm[8*MX];
int segm2[8*MX];
const int inv2=(MD+1)/2;
void merge(int &A,int &B,int &res){
    res=(A+B)%MD;
}
int query(int cur,int start,int end,int qs,int qe,bool one){
    if(start>=qs && end<=qe)
        return (one?segm[cur]:segm2[cur]);
    if(start>qe || end<qs)
        return 0;          //INVALID RETURN 
    int mid=(start+end)>>1;
    int A=query(2*cur,start,mid,qs,qe,one);
    int B=query(2*cur+1,mid+1,end,qs,qe,one);
    //MERGING STEP
    int res;
    merge(A,B,res);  

    return res;
}
void update(int cur,int start,int end,int ind,int val,bool one){
    if(start==ind && start==end){
        //DO UPDATE
        if(one)
            segm[cur]=val;
        else
            segm2[cur]=val;
        return;
    }
    if(start>ind|| end<ind)
        return;          //OUT OF RANGE 
    int mid=(start+end)>>1;
    update(cur<<1,start,mid,ind,val,one);
    update((cur<<1)^1,mid+1,end,ind,val,one);
    //MERGING STEP
    if(one)
        merge(segm[2*cur],segm[2*cur+1],segm[cur]);
    else
        merge(segm2[2*cur],segm2[2*cur+1],segm2[cur]);

}
 
vector<int>v[MX];
int in[MX];
int out[MX];
pii cost[MX];

int timer;
void dfs(int cur){

    in[cur]=timer;
    timer++;
    for(auto &el:v[cur])
        dfs(el);
    out[cur]=timer;
    timer++;
}


void solve() {

    int n;
    cin>>n;
    
    timer=1;
    repe(i,n)
        v[i].clear();
    repe(i,8*n)
        segm[i]=0,segm2[i]=0;

    repe(i,n){
        if(i==1){
            continue;
        }
        int x;
        cin>>x;
        v[x].pb(i);
    }
    repe(i,n)
        cin>>cost[i].ff,cost[i].ss=i;
    sort(cost+1,cost+n+1,greater<pii>());

    dfs(1);
    int N=timer;
    int res=0;
    // segm:+-(1),segm2:++(0)
    repe(i,n){
        int here=1;
        int x=cost[i].ss;
        int in_time=in[x],out_time=out[x];
        int qu=query(1,1,N,1,in_time,1);
        int qu2=query(1,1,N,in_time,out_time,0);
        qu2=(qu2*inv2)%MD;
        here=(here+qu+qu2)%MD;
        res=(res+here)%MD;
        update(1,1,N,in_time,here,1);
        update(1,1,N,out_time,MD-here,1);

        update(1,1,N,in_time,here,0);
        update(1,1,N,out_time,here,0);
        // cout<<x<<"->"<<here<<": ["<<in_time<<" "<<out_time<<"]\n";
    }
    res=(res+MD-n)%MD;
    cout<<res<<'\n';

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