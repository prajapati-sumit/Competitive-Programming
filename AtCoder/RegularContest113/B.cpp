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
 
 
ll A,B,C,phi=4; 
 
ll bin_power(ll a,ll b,ll md){
    ll res=1;
    while(b){
        if (b&1)
            res=(res*a)%md;
        a=(a*a)%md;
        b>>=1;
    }
    return res;
}
 
void solve(){
  
   cin>>A>>B>>C;

   
   
   A%=10;
   if (A==0){
    cout<<"0";
   }
   else if(A==1){
    cout<<"1";
   }
   else if (A==2){
        ll x=bin_power(B,C,4);
        ll m[4]={6,2,4,8};
        cout<<m[x];

   }
   else if (A==3){
        ll x=bin_power(B,C,4);
        ll m[4]={1,3,9,7};
        cout<<m[x];

   }
   else if (A==4){
        ll x=bin_power(B,C,2);
        ll m[2]={6,4};
        cout<<m[x];

   }
   else if(A==5){
    cout<<"5";

   }
   else if (A==6){
       cout<<6;

   }
   else if (A==7){
        ll x=bin_power(B,C,4);
        ll m[4]={1,7,9,3};
        cout<<m[x];

   }
   else if (A==8){
        ll x=bin_power(B,C,4);
        ll m[4]={6,8,4,2};
        cout<<m[x];

   }
   else if(A==9){
        ll x=bin_power(B,C,2);
        ll m[2]={1,9};
        cout<<m[x];
   }

  
 
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