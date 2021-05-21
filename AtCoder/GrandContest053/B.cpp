// AUTHOR: SUMIT PRAJAPATI      
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;

#define PI 3.1415926535897932384626
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define trav(v) for(auto &el:v)
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(int i=0;i<n;i++)
#define repe(i,n) for(int i=1;i<=n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()


const int INF=1e9;
const int MX=4e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
#define TESTCASES 0 
 
int n, segm[4*MX],a[MX];
void buildtree(int cur,int start,int end){
     if(start==end){
        //BASE CASE
        segm[cur]=start;
         return;
     }
     int mid=(start+end)>>1;
     buildtree(cur<<1,start,mid);
     buildtree((cur<<1)+1,mid+1,end);
     //MERGING STEP
     segm[cur]=a[segm[2*cur]]>a[segm[2*cur+1]]?segm[2*cur]:segm[2*cur+1];
 
 
}
int query(int cur,int start,int end,int qs,int qe){
     if(start>=qs && end<=qe)
         return segm[cur];
     if(start>qe || end<qs)
         return -1;          //INVALID RETURN 
     int mid=(start+end)>>1;
     int A=query(2*cur,start,mid,qs,qe);
     int B=query(2*cur+1,mid+1,end,qs,qe);
 
     return a[A]>A[B]?A:B;
}
void update(int cur,int start,int end,int ind){
    if(start==ind && start==end){
        segm[ind]=ind;                  //DO UPDATE
    }
    if(start>ind|| end<ind)
        return;          //OUT OF RANGE 
    int mid=(start+end)>>1;
    update(cur<<1,start,mid,ind);
    update((cur<<1)^1,mid+1,end,ind);
    //MERGING STEP
    segm[cur]=a[segm[2*cur]]>a[segm[2*cur+1]]?segm[2*cur]:segm[2*cur+1];

}
   
 
 
void solve(){
  
    
    cin>>n;
    repe(i,2*n)    
        cin>>a[i];
    int li=n,ri=n+1;
    ll ans=0;
    repe(i,n){
        assert(li>=1 && ri<=2*n);
        if(a[li]>a[ri]){    
            int ind=query(1,1,2*n,1,li);
            ans+=a[ind];
            a[ind]=-1;
            update()

        }
        else if(a[li]<a[ri]){

        }
        else if(a[li]==a[ri]){

        }
        else
            assert(false);
    }
    assert(query(1,1,2*n,1,2*n)==-1);

    cout<<ans<<'\n';
    }
/*
1 4 5 8 7 6 3 2
    

8 5 4 1 2 3 6 7
*/
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    if(TESTCASES)cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}