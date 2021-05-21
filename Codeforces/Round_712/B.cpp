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
 
 
 
 
 
 
void solve(){
  
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    bool flag=true;
    bool equal=0;
    int zeroa=0,onea=0,zerob=0,oneb=0;
    rep(i,n){
        // cout<<equal<<" "<<a[i]<<" "<<b[i]<<" "<<onea<<" "<<zeroa<<" "<<oneb<<" "<<zerob<<"\n";
        if(!equal){
            if(a[i]==b[i]){
                equal^=1;
                if(onea!=oneb || zeroa!=zerob){
                    flag=false;
                    break;
                }
            }
            if(a[i]=='0')
                zeroa++;
            else 
                onea++;
            if(b[i]=='0')
                zerob++;
            else
                oneb++;
        }
        else{
            if(a[i]!=b[i]){
                equal^=1;
                if(onea!=oneb || zeroa!=zerob){
                    flag=false;
                    break;
                }
            }
            if(a[i]=='0')
                zeroa++;
            else 
                onea++;
            if(b[i]=='0')
                zerob++;
            else
                oneb++;
            
        }
    } 
    if(onea!=oneb || zeroa!=zerob){
        flag=false;
    } 
    cout<<(flag?"YES\n":"NO\n");  
  
 
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