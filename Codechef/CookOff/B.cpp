// AUTHOR: Sumit Prajapati      
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long           
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define debug(x)            cerr<<#x<<" = "<<x<<'\n'
#define llrand()            distribution(generator)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define endl                '\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()
const ll INF=1e10;
#define MD                  1'000'000'007
#define MDL                 998244353
const ll MX= 1002;


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
 
 
ll a[MX][MX];
void solve(){
  
    
    ll x1,y1,x2, y2;
    cin>>x1>>y1>>x2>>y2;
    ll ans=0;       
    while(true){
        
        ans+=a[x1][y1];
        if(x1==x2 && y1==y2)
            break;
        ll op1=(x1==x2)?-INF:a[x1+1][y1];
        ll op2=(y1==y2)?-INF:a[x1][y1+1];
        if(op1>op2){
            x1++;
        }
        else
            y1++;
        

    }
    cout<<ans<<'\n';
   
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    repe(i,MX-1){
        ll cur=(i*(i+1))/2,inc=i;
        for(ll j=1;j<MX;j++){
            a[i][j]=cur;
            cur+=inc;
            inc++;
        }
    }
   
    ll t=1;
    cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}