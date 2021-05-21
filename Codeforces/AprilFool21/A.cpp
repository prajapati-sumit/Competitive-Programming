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
#define TESTCASES 0

const int INF=1e9;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
 
 
 
 
 
 
void solve(){
  
    int H,W;
    cin>>H>>W;
    char a[H][W];
    rep(i,H){
        rep(j,W){
            cin>>a[i][j];
        }
    }
    int res=0;
    int row=0,col=0;
    int best=0,nextR=row,nextC=col;
    while(true){
        best=INF;
        nextR=row;
        nextC=col;
        if(a[row][col]=='*')
            res++;
        for(int i=row;i<H;i++){
            for(int j=col;j<W;j++){
                int cur_dist=abs(i-row)+abs(j-col);
                if(!(i==row && j==col) && a[i][j]=='*' && cur_dist<best){
                    // cout<<i<<" "<<j<<" "<<cur_dist<<"\n";
                    nextR=i;
                    nextC=j;
                    best=cur_dist;
                }

            }
        }
        // cout<<nextR<<" "<<nextC<<"\n";
        if(nextR==row && nextC==col ){
            break;
        }
        else{
            row=nextR;
            col=nextC;
        }
    }
    cout<<res;
} 
 
 
int main() {
    

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