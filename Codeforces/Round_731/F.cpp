//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
// #define int                 long long           
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
const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e9;
const int MX=2e5+5;

 
int segm[4*MX];
int a[MX];
int gcd(int a,int b){
    if(a==0)
        return b;
    if(b==0)
        return a;
    return gcd(b,a%b);
} 
void buildtree(int cur,int start,int end){
    if(start==end){
       //BASE CASE
        segm[cur]=a[start];
        return;
    }
    int mid=(start+end)>>1;
    buildtree(cur<<1,start,mid);
    buildtree((cur<<1)+1,mid+1,end);
    //MERGING STEP
    segm[cur]=gcd(segm[2*cur],segm[2*cur+1]);

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
    int res=gcd(A,B);  

    return res;
}

 
void solve(){
  
    int n;
    cin>>n;
    
    repe(i,n)
        cin>>a[i];
    buildtree(1,1,n);
    int l=0,r=n;
    int mid,ans=0;
    while(l<=r){
        mid=(l+r)>>1;
        int prev=0;
        int R=min(n,mid+1);
        prev=query(1,1,n,1,R);
        bool ok=true;
        FOR(i,2,n){
            int cur;
            if(mid+i>n)
                cur=gcd(query(1,1,n,i,n),query(1,1,n,1,(mid+i)%n));
            else
                cur=query(1,1,n,i,mid+i);
            if(prev!=cur){
                ok=false;
                break;
            }
        }
        if(ok)
            r=mid-1,ans=mid;
        else
            l=mid+1;
    }
    cout<<ans<<'\n';


  
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}