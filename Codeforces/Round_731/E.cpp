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

#define left flkjf
#define right afjlkf


auto time0 = curtime;
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e15;
const int MX = 3e5 + 5;

int segm1[4*MX];
int segm2[4*MX];

int query1(int cur,int start,int end,int qs,int qe){
    if(qs>qe)
        return INF;
    if(start>=qs && end<=qe)
        return segm1[cur];
    if(start>qe || end<qs)
        return INF;          //INVALID RETURN 
    int mid=(start+end)>>1;
    int A=query1(2*cur,start,mid,qs,qe);
    int B=query1(2*cur+1,mid+1,end,qs,qe);
    //MERGING STEP
    int res=min(A,B);  

    return res;
}
void update1(int cur,int start,int end,int ind,int val){
    if(start==ind && start==end){
        //DO UPDATE
        segm1[cur]=val;
        return;
    }
    if(start>ind|| end<ind)
        return;          //OUT OF RANGE 
    int mid=(start+end)>>1;
    update1(cur<<1,start,mid,ind,val);
    update1((cur<<1)^1,mid+1,end,ind,val);
    //MERGING STEP
    segm1[cur]=min(segm1[2*cur],segm1[2*cur+1]);
    
}
int query2(int cur,int start,int end,int qs,int qe){
    if(qs>qe)
        return INF;
    if(start>=qs && end<=qe)
        return segm2[cur];
    if(start>qe || end<qs)
        return INF;          //INVALID RETURN 
    int mid=(start+end)>>1;
    int A=query2(2*cur,start,mid,qs,qe);
    int B=query2(2*cur+1,mid+1,end,qs,qe);
    //MERGING STEP
    int res=min(A,B);  

    return res;
}
void update2(int cur,int start,int end,int ind,int val){
    if(start==ind && start==end){
        //DO UPDATE
        segm2[cur]=val;
        return;
    }
    if(start>ind|| end<ind)
        return;          //OUT OF RANGE 
    int mid=(start+end)>>1;
    update2(cur<<1,start,mid,ind,val);
    update2((cur<<1)^1,mid+1,end,ind,val);
    //MERGING STEP
    segm2[cur]=min(segm2[2*cur],segm2[2*cur+1]);
    
}
 



void solve() {

    int n, k;
    cin >> n >> k;
    int t[k + 1],a[k+1];
    repe(i, k)
        cin >> a[i];
    repe(i,k)
        cin>>t[i];
    repe(i,4*n)
        segm1[i]=INF,segm2[i]=INF;
    vector<int>ans(n+1);
    repe(i,n)
        ans[i]=INF;
    repe(i,k)
        ans[a[i]]=t[i];
    repe(i,k){
        update1(1,1,n,a[i],t[i]-a[i]);
    }
    repe(i,k){
        update2(1,1,n,a[i],t[i]+a[i]);
    }

    repe(i,n){
        int lef_ans=query1(1,1,n,1,i-1),rig_ans=query2(1,1,n,i+1,n);
        // cout<<lef_ans<<" "<<rig_ans<<'\n';
        ans[i]=min({ans[i],lef_ans+i,rig_ans-i});
    }
    repe(i,n)
        cout<<ans[i]<<" ";
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
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}