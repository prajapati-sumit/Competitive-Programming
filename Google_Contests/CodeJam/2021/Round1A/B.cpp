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
#define repe(i,n) for(ll i=1;i<=n;i++)
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
 
 
ll M,totalsum;
ll P[100],N[100];
ll best_ans=0;

ll bin_power(ll a,ll b){
     ll res=1;
     while (b){
         if (b&1)
             res=(res*a);
         a=(a*a);
         b>>=1;
     }
     return res;
} 

void helper(ll cur,ll theproduct,ll thesum){
    // cout<<cur<<" "<<theproduct<<" "<<thesum<<" "<<totalsum<<'\n';
    if(theproduct>totalsum)
        return;
    if(cur>M){
        // cout<<theproduct<<'\n';
        if(thesum+theproduct==totalsum)
            best_ans=max(best_ans,theproduct);
        return;
    }
    FOR(i,0,N[cur]){

        ll nowproduct=theproduct*bin_power(P[cur],i),nowsum=thesum+P[cur]*i;
        // cout<<i<<"-> "<<nowproduct<<" "<<nowsum<<'\n';
        if(nowproduct>totalsum || nowsum>totalsum)
            break;
        helper(cur+1,nowproduct,nowsum);
    }


}
void solve(){
  
    cin>>M;
    totalsum=0;
    repe(i,M){
        cin>>P[i]>>N[i];
        totalsum+=(P[i]*N[i]);
    }
    best_ans=0;
    helper(1,1,0);
    cout<<best_ans<<'\n';

  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    if(TESTCASES)cin>>t;
    repe(tt,t){
        cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}