//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
#define int                 long long           
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




auto time0 = curtime;
const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e9;
const int MX=1e5+5;

 
 
 
 
int solve(int a,int b,int c){
  
    
    // int a,b,c;
    // cin>>a>>>c;
    int d1=b-a,d2=c-b;

    int mid=(d1+d2)/2;
    int ans=0;
    if(d1>mid && d2<mid){
        
        ans+=abs(d1-mid);
        ans+=abs(d2-mid);
    }
    else{
        if((abs(d1)+abs(d2))%2==1){
            return 1+solve(a,b,c+1);
        }
        else{
            assert(abs(mid-d1)==abs(mid-d2));
            ans+=abs(mid-d1);
        }
    }
    return ans;

    

} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    int a,b,c;
    cin>>a>>b>>c;
    cout<<solve(a,b,c);
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}