// AUTHOR: SUMIT PRAJAPATI      
#include "bits/stdc++.h"
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
#define TESTCASES 1

const int INF=1e9;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
 
 
 
 
 
int k,n;
int a[20];
bool isvalid(int x){
    int res=0;
    repe(i,k)
        res+=(x%a[i]==0);
    return res==1;
}
 
void solve(){
  
    cin>>k>>n;
    repe(i,k)
        cin>>a[i];
    sort(a+1,a+k+1);
    int ind[k+1];
    repe(i,k)
        ind[i]=1;
    int cur_active=1;
    vector<int>v;
    bool flag=true;
    while(flag){
        // int cur_val=;

        while(a[cur_active]*ind[cur_active]<=a[cur_active<k?cur_active+1:1]*ind[cur_active<k?cur_active+1:1]){
            if(v.size()>n+50){
                flag=false;
                break;
            }
            if(isvalid(a[cur_active]*ind[cur_active]))
                v.pb(a[cur_active]*ind[cur_active]);
            ind[cur_active]++;
        }
        cur_active=cur_active<k?cur_active+1:1; 
    }    
    sort(v.begin(), v.end());
    int ans=v[n-1];
    // trav(v)
    //     cout<<el<<" ";
    // cout<<'\n';
    cout<<ans<<'\n';
  
 
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