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
 
int ncr[21][21];
void init(){
    ncr[0][0]=1;
    for(int i=1;i<=20;i++){
        for(int j=0;j<=i;j++){
            if(j==0 || j==i)
                ncr[i][j]=1;
            else
                ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
        }
    }
}


void solve(){
  
    int A,B;
    cin>>A>>B;
    init();
    int f=2;
    int what=1;
    pii res;
    int till_now=INF;
    for(int i=0;i<=f;i++){
        for(int j=0;j<=i;j++){
            int a=i-j,b=j;
            if(ncr[i][j]>=f && (a*A+b*B)<till_now){
                till_now=a*A+b*B;
                res=mk(a,b);
            }
        }
    }
    cout<<res.ff<<" "<<res.ss<<' '<<till_now+what<<'\n';
 
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