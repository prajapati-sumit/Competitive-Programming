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
#define INF                 1'000'000'000
#define MD                  1'000'000'007
#define MDL                 998244353
#define MX                  100'005


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
 
int n,t;

int query(int l, int r){

    cout<<"? "<<l<<" "<<r<<'\n';
    int resp;
    cin>>resp;
    return resp;
}
 
void solve(){

    assert(t==1);
    int k;
    cin>>k;
    int l=1,r=n;
    int ans=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        int q=query(l,mid);
        int len=mid-l+1;
        if(len-q>=k){
            r=mid-1;
            ans=mid;
        }
        else{ 
            k-=(len-q);
            l=mid+1;
        }
    }
    assert(ans!=-1);
    cout<<"! "<<ans<<'\n';
           
  
 
} 
 
 
int main() {
   

    time0 = curtime;

    cin>>n>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}