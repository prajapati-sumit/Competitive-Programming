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
 
 
int forx[MX];
int fory[MX]; 
 
 
void solve(){
  
    int n,q;
    cin>>n>>q;
    int x,y;
    char ch;
    repe(i,n){
        cin>>x>>y>>ch;
        if(ch=='N'){
            fory[y+1]+=1;
        }
        else if(ch=='E'){
            forx[x+1]+=1;

        }
        else if(ch=='W'){
            forx[0]+=1;
            forx[x]-=1;

        }
        else if(ch=='S'){
            fory[0]+=1;
            fory[y]-=1;

        }
        else assert(false);
    }
    int x_best=0,y_best=0;
    FOR(i,0,q){

        if(i>0){
            forx[i]+=forx[i-1];
            fory[i]+=fory[i-1];
        }
        if(forx[i]>forx[x_best])
            x_best=i;
        if(fory[i]>fory[y_best])
            y_best=i;
    }
    cout<<x_best<<" "<<y_best<<'\n';

    repe(i,MX){
        forx[i]=0;
        fory[i]=0;
    }

  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    if(TESTCASES)cin>>t;
    repe(tt,t){
        cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}