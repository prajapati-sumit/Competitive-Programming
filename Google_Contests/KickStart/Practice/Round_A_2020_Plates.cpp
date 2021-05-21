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
 
 
int n,k,p; 
int a[51][31]; 
int pref[51][31]; 
int dp[51][1582];
int fn(int cur,int left){
    
    
    if(left<0){
        return -MD;
    }
    if(left==0){
        return 0;
    }
    if(cur==n+1 && left>0){
        return -MD;
    }
    if(dp[cur][left]!=-1){
        return dp[cur][left];
    }
    
    int ans=-MD;
    FOR(i,0,k){
        int temp=fn(cur+1,left-i);
       // cout<<(cur+1)<<" "<<(left-i)<<" : "<<temp<<'\n';
        ans=max(ans,pref[cur][i]+temp);
    } 
    
    return dp[cur][left]=ans;
}
void solve(){
  
    
    cin>>n>>k>>p;
    memset(dp,-1,sizeof(dp));
    repe(i,n){
        repe(j,k){
            cin>>a[i][j];
            pref[i][j]=0;
            if(j==1)
                pref[i][j]=a[i][j];
        }
    }
    repe(i,n){
        FOR(j,2,k)
            pref[i][j]=a[i][j]+pref[i][j-1];
    }
    // cout<<pref[1][0]<<'\n';
    int ans=-1;
    FOR(i,0,k){
        ans=max(ans,pref[1][i]+fn(2,p-i));
        //cout<<fn(1,i,p-i)<<'\n';
    }   
    // repe(i,n){
    //     repe(j,k){
    //         repe(l,p){
    //             cout<<dp[i][j][l]<<" ";
    //         }
    //         cout<<'\n';
    //     }
    //     cout<<'\n';
    // }
    cout<<ans<<'\n';

  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;
    cout<<sizeof(11.8)<<"\n";
    cout<<sizeof(11.8f)<<"\n";
    cout<<sizeof(11.8l)<<"\n";
    cout<<sizeof(11.8L)<<"\n";
    ll t=1;
    cin>>t;
    repe(tt,t){
        cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}