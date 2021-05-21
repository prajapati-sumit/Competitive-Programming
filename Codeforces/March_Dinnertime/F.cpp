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
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()

const int INF=1e9;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
 
 
 
 
int M,N; 
int D[MX],H[MX];
ll bin_power(ll a,ll b,ll md){
    ll res=1;
    while (b){
        if (b&1)
            res=(res*a)%md;
        a=(a*a)%md;
        b>>=1;
    }
    return res;
}
void solve(){
  
    cin>>M>>N;
    repe(i,N)
        cin>>D[i];
    repe(i,M)
        cin>>H[i];
    int p[]={1,2,3};
    int temp[5],tot=0,c=0;
    int cnt=0;
    do {

        repe(i,3)
            temp[i]=H[i];
        
        repe(i,3){
            repe(j,3){
                repe(k,3){
                    temp[i]-=D[p[0]];
                    temp[j]-=D[p[1]];
                    temp[k]-=D[p[2]];
                    if(temp[1]>0)
                        cnt++;
                    if(temp[2]>0)
                        cnt++;
                    if(temp[3]>0)
                        cnt++;
                    tot++;
                }
            }
        }
        
    } while (next_permutation(p, p + 3));       
    cout<<tot<<" "<<cnt<<" "<<__gcd(tot,cnt)<<'\n';
    ll Fd=(cnt*bin_power(tot,MD-2,MD))%MD;

    cout<<Fd<<'\n';
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