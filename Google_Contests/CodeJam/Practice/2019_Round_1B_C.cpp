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
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
#define TESTCASES 1 
// #warning Change limit
 
 
int C[MX],D[MX]; 
const int MAXLOG=18;
 
 
 
 
int sparseC[MX][MAXLOG];
int sparseD[MX][MAXLOG];
int bin_log[MX];
int n,k;

void fill(){
  
    for(int i=1;i<=n;i++){
        sparseC[i][0]=C[i];
    }
    for(int j=1;j<=MAXLOG;j++){
        for(int i=1;(i+(1<<j)-1)<=n && i<=n;i++){
            sparseC[i][j]=max(sparseC[i][j-1],sparseC[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=1;i<=n;i++){
        sparseD[i][0]=D[i];
    }
    for(int j=1;j<=MAXLOG;j++){
        for(int i=1;(i+(1<<j)-1)<=n && i<=n;i++){
            sparseD[i][j]=max(sparseD[i][j-1],sparseD[i+(1<<(j-1))][j-1]);
        }
    }
}



int getmaxC(int x,int y){
    if(x>y)
        return -1;
    int h=bin_log[y-x+1];
    return max(sparseC[x][h],sparseC[y-(1<<h)+1][h]);
}
int getmaxD(int x,int y){
    if(x>y)
        return -1;
    int h=bin_log[y-x+1];
    return max(sparseD[x][h],sparseD[y-(1<<h)+1][h]);
}

ll helper(ll cur,ll limit){
    ll l=1,r=cur,mid,l_p=cur+1,r_p=cur-1;
    while(l<=r){
        mid=(l+r)>>1;
        // cerr<<mid<<" "<<cur<<" "<<getmaxC(mid,cur)<<" "<<getmaxD(mid,cur)<<"\n";
        if(getmaxC(mid,cur)==C[cur] && getmaxC(mid,cur-1)!=C[cur] && getmaxD(mid,cur)<=limit)
            l_p=mid,r=mid-1;
        else
            l=mid+1;
    }
    l=cur;
    r=n;
    while(l<=r){
        mid=(l+r)>>1;
        if(getmaxC(cur,mid)==C[cur]  && getmaxD(cur,mid)<=limit)
            r_p=mid,l=mid+1;
        else
            r=mid-1;
    }
    // cout<<l_p<<" "<<r_p<<'\n';
    ll res=(cur-l_p+1)*(r_p-cur+1);
    return res;

}
void solve(){
  
    
    cin>>n>>k;
    repe(i,n)
        cin>>C[i];
    repe(i,n)
        cin>>D[i];
    fill();

    ll ans=0;
    repe(i,n){
        ll P1P2=helper(i,C[i]+k),P1P3=helper(i,C[i]-k-1);
        ans+=(P1P2-P1P3);
        // cout<<'\n';
    }
    cout<<ans<<'\n';
  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;
    bin_log[1]=0;
    FOR(i,2,MX-1)
        bin_log[i]=bin_log[i/2]+1;
    ll t=1;
    if(TESTCASES)cin>>t;
    repe(tt,t){
        cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}