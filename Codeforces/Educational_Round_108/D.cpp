// AUTHOR: Sumit Prajapati      
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define int                 long long          
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
 
 
int n;

void solve(){
  
    cin>>n;
    
    int a[n+1],b[n+1]; 
    int max_p=0;
    repe(i,n)
        cin>>a[i];
    repe(i,n){
        cin>>b[i];
        max_p+=a[i]*b[i];
    }
    int origin=max_p;
    for(int i=1;i<=n;i++){
        int l=i,r=i;
        int temp=origin;
        while(l>=1 && r<=n){
            temp+=a[l]*b[r];
            temp+=a[r]*b[l];
            temp-=a[l]*b[l];
            temp-=a[r]*b[r];
            max_p=max(temp,max_p);
            l--;r++;
        }
    }
    for(int i=1;i<=n-1;i++){
        int l=i,r=i+1;
        int temp=origin;
        while(l>=1 && r<=n){
            temp+=a[l]*b[r];
            temp+=a[r]*b[l];
            temp-=a[l]*b[l];
            temp-=a[r]*b[r];
            max_p=max(temp,max_p);
            l--;r++;
        }
    }    
    cout<<max_p;
 
} 
 

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    // cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}