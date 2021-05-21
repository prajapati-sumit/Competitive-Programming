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
 
 
vector<int> xorpref(2005,0); 
 
int getxor(int l,int r){
    if(r<l)
        return 0;
    return xorpref[r]^xorpref[l-1];
}
void solve(){
  
    int n;
    cin>>n;
    int a[n+1];
    a[0]=0;
    
    repe(i,n)
        cin>>a[i],xorpref[i]=a[i]^xorpref[i-1];
    for(int i=1;i<=n;i++){
        int xorl=getxor(1,i);
        for(int j=i+1;j<=n;j++){
            int xorr=getxor(j,n);
            int xorbet=getxor(i+1,j-1);
            // cout<<i<<" "<<j<<"-> "<<xorl<<" "<<xorr<<" "<<xorbet<<"\n";
            if(xorl==xorr && (xorbet==0 || xorbet==xorl)){
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
  
 
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