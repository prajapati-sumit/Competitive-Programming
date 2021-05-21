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
 
 
 
 
 
ll pow10a[MX],pow10s[MX];
void solve(){
  
    ll k;
    string S,A;
    cin>>k>>S>>A;
    ll score_s=0,score_a=0;
    
    ll freqs[10],freqa[10];
    FOR(i,1,9){
        freqs[i]=0;
        freqa[i]=0;
    }
    repe(i,9){
        pow10a[freqa[i]]+=i;
        pow10s[freqs[i]]+=i;
    }
    ll num=0;
    repe(s,9){
        repe(a,9){
            vector<int>aa(pow10a,pow10a+MX),ss(pow10s,pow10s+MX);
            if((freqs[s]+freqa[s])<k && ((freqs[a]+freqa[a])<k)){
                
            }
        }
    }
    cout<<num<<"\n";
    double ans=(1.0*num)/81;
    printf("%0.6f",ans );
  
 
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
    
    cerr<<"\nExecution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}