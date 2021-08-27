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
const int MX = 3e5 + 5;



vector<pii>v[MX];

pii segm[8*MX];
pii lazy[8*MX];

void merge(pii &A,pii &B,pii &res){

    res=max(A,B);
}
void lazyUpdate(int cur,int start,int end){
    if(lazy[cur].ff==0)
        return;

    int mx=lazy[cur].ff,ind=lazy[cur].ss;
    if(mx>segm[cur].ff){
        segm[cur]=lazy[cur];    
    }
    lazy[cur]={0,0};
    if(start!=end){
        if(mx>lazy[2*cur].ff)
            lazy[2*cur]={mx,ind};
        if(mx>lazy[2*cur+1].ff)
            lazy[2*cur+1]={mx,ind};
    }


}
pii query(int cur,int start,int end,int qs,int qe){

    lazyUpdate(cur,start,end);
    if(start>=qs && end<=qe)
        return segm[cur];
    if(start>qe || end<qs)
        return {-1,0};          //INVALID RETURN 
    int mid=(start+end)>>1;
    pii A=query(2*cur,start,mid,qs,qe);
    pii B=query(2*cur+1,mid+1,end,qs,qe);
    //MERGING STEP
    pii res;
    merge(A,B,res);  

    return res;
}
void update(int cur,int start,int end,int qs,int qe,int val,int i){
    lazyUpdate(cur,start,end);
    if(start>=qs && end<=qe){
        //DO UPDATE
        lazy[cur]={val,i};
        lazyUpdate(cur,start,end);
        return;
    }
    if(start>qe || end<qs)
        return;          //OUT OF RANGE 
    int mid=(start+end)>>1;
    update(cur<<1,start,mid,qs,qe,val,i);
    update((cur<<1)^1,mid+1,end,qs,qe,val,i);
    //MERGING STEP
    merge(segm[2*cur],segm[2*cur+1],segm[cur]);

}
 

void solve() {

    int n,m;
    cin>>n>>m;
    map<int,int>mp;
    repe(i,m){
        int idx,l,r;
        cin>>idx>>l>>r;
        mp[l];
        mp[r];
        v[idx].pb({l,r});
    }
    // coordinate compress
    int cnt=1;
    for(auto &el:mp)
        el.ss=cnt++;
    int nax=cnt;
    repe(i,n)
        for(auto &el:v[i]){
            el.ff=mp[el.ff];
            el.ss=mp[el.ss];
        }

    pii dp[n+1];
    pii ans={-1,0};
    int where=-1;
    for(int i=1;i<=n;i++){
        pii tmp={-1,0};
        for(auto &el:v[i]){
            pii qu=query(1,1,nax,el.ff,el.ss);
            tmp=max(tmp,qu);
        }
        for(auto &el:v[i]){
            update(1,1,nax,el.ff,el.ss,tmp.ff+1,i);
        }
        dp[i]={tmp.ff+1,tmp.ss};
        // cout<<i<<" "<<dp[i].ff<<" "<<dp[i].ss<<'\n';
        if(ans<dp[i]){
            ans=dp[i];
            where=i;
        }
    }
    int num=n-ans.ff;
    // cout<<ans.ff<<" "<<ans.ss<<'\n';
    // return;
    int cur=n;
    vector<int>res;
    while(cur>where)
        res.pb(cur),cur--;
    while(cur>=1){
        cur=where-1;
        where=ans.ss;
        ans=dp[ans.ss];
        while(cur>=1 && cur>where)
            res.pb(cur),cur--;
    }
    assert(SZ(res)==(num));
    cout<<num<<"\n";
    for(auto &el:res)
            cout<<el<<" ";

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