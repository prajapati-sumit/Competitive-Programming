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
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()


const ll INF=1e9;
const ll MX=1e5+5;
const ll MD=1e9+7;
const ll MDL=998244353;
const ll MAXLOG=18;

auto time0 = curtime;
#define TESTCASES 1 
 
 
struct Person{
    ll e;
    ll x;
    ll y; 
    bool operator < (Person const &Q) {
        return x+y>Q.x+Q.y;
    }  
};
 

Person P[MX];
ll n,m,k,q;
ll sparse[MX][MAXLOG];

void fill(){
    for(ll i=1;i<=k;i++){
        sparse[i][0]=P[i].e;
    }
    for(ll j=1;j<=MAXLOG;j++){
        for(ll i=1;(i+(1<<j)-1)<=k && i<=k;i++){
            sparse[i][j]=max(sparse[i][j-1],sparse[i+(1<<(j-1))][j-1]);
        }
    }
}
ll getmax(ll x,ll y){
    if(x>y)
        return 0;
    ll h=(ll)log2(y-x+1);
    return max(sparse[x][h],sparse[y-(1<<h)+1][h]);
}
void solve(){
  
    cin>>n>>m>>k;
    repe(i,k)
        cin>>P[i].e>>P[i].x>>P[i].y;

    sort(P+1,P+k+1);
    fill();
    cin>>q;
    ll t;
    repe(i,q){
        cin>>t;
        ll l=1,r=k,mid,ans=0;
        while(l<=r){
            mid=(l+r)>>1;
            // cout<<mid<<" "<<P[mid].x<<" "<<P[mid].y<<" "<<n<<'\n';
            if((n+m-P[mid].x-P[mid].y)<=t){
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        // cout<<ans<<"----";
        ll rmax=getmax(1,ans);
        // cout<<rmax<<"----";
        ll res=ans*rmax;
        cout<<res<<'\n';
    

    }
  
 
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