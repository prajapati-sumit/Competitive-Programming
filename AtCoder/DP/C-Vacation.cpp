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
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()

const int INF=1e9;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
 
 
int n;
int A[MX][4]; 
int dp[MX][4];

int fn(int n,int last){
    if(n<=0)
        return 0;
    if(dp[n][last]!=-1)
        return dp[n][last];
    int res=-1;
    repe(i,3){
        if(i!=last){
            res=max(res,A[n][i]+fn(n-1,i));
        }
    }
    return dp[n][last]=res;
}
 
void solve(){
  
    cin>>n;
    memset(dp,-1,sizeof dp);
    repe(i,n){
        cin>>A[i][1]>>A[i][2]>>A[i][3];
    }
    int ans=max(fn(n,1),max(fn(n,2),fn(n,3)));
    cout<<ans;
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    //cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}