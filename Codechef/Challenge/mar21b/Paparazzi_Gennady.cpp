//CODED BY SUMIT KUMAR PRAJAPATI
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
#define trav(v) for(auto &el:v)
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()

const int INF=1e9;
const int MX=5e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
 
 
int n;
int h[MX]; 
//int segm[4*MX];


// void buildtree(int cur,int start,int end){
//     if(start==end){
//        //BASE CASE
//         segm[cur]=start;
//         return;
//     }
//     int mid=(start+end)>>1;
//     buildtree(cur<<1,start,mid);
//     buildtree((cur<<1)^1,mid+1,end);
//     //MERGING STEP
//     if(h[segm[2*cur]]>h[segm[2*cur+1]])
//         segm[cur]=segm[2*cur];
//     else
//         segm[cur]=segm[2*cur+1];


// }
// int query(int cur,int start,int end,int qs,int qe){
//     if(start>=qs && end<=qe)
//         return segm[cur];
//     if(start>qe || end<qs)
//         return 0;          //INVALID RETURN 
//     int mid=(start+end)>>1;
//     int A=query(cur<<1,start,mid,qs,qe);
//     int B=query((cur<<1)^1,mid+1,end,qs,qe);
//     int res=(h[A]>h[B])?A:B;               //MERGING STEP  
//     return res;
// }
// void update(int cur,int start,int end,int ind){
//     if(start==ind && start==end)
//         return;                    //DO UPDATE
    
//     if(start>ind|| end<ind)
//         return;          //OUT OF RANGE 
//     int mid=(start+end)>>1;
//     update(cur<<1,start,mid,ind);
//     update((cur<<1)^1,mid+1,end,ind);
//     if(h[segm[2*cur]]>h[segm[2*cur+1]])
//         segm[cur]=segm[2*cur];
//     else
//         segm[cur]=segm[2*cur+1];
// }


void solve(){
  
    cin>>n;
    h[0]=-1;
    int curIndex=1,M=-1;
    repe(i,n){
        cin>>h[i];
        if(h[i]>M){
            M=h[i];
            curIndex=i;
        }
        
    }
    
    int ans=0;
    double m,slope;
    int next=45;

    for(int i=curIndex;i<n;){
        m=-DBL_MAX;
        for(int j=i+1;j<=n;j++){
            slope=(double)(h[j]-h[i])/(j-i);
            if(slope>=m){
                next=j;
                m=slope;
            }
        }
        ans=max(ans,next-i);
        i=next;


    }
    for(int i=curIndex;i>1;){
        m=DBL_MAX;
        for(int j=i-1;j>=1;j--){
            slope=(double)(h[j]-h[i])/(j-i);
            if(slope<=m){
                next=j;
                m=slope;
            }
        }
        ans=max(ans,i-next);
        i=next;


    }
    cout<<ans<<'\n';
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}