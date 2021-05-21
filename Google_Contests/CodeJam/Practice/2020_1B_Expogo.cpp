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
 
 
string res;
pair<int,int> whichDirection(int x,int y){
    if(x>=0 && y>=0){
        if(abs(x)>abs(y)){
            res.pb('E');
            return {-1,0};
        }
        else{
            res.pb('N');
            return {0,-1};
        }
    }
    else if(x<0 && y>=0){
        if(abs(x)>abs(y)){
            res.pb('W');
            return {1,0};
        }
        else{
            res.pb('N');
            return {0,-1};
        }
    }
    else if(x<0 && y<0){
        if(abs(x)>abs(y)){
            res.pb('W');
            return {1,0};
        }
        else{
            res.pb('S');
            return {0,1};
        }

    }
    else{
        if(abs(x)>abs(y)){
            res.pb('E');
            return {-1,0};
        }
        else{
            res.pb('S');
            return {0,1};
        }
    }
} 
 
void solve(){
  
    int x=3,y=4;
    
    // for(int x1=-4;x1<=4;x1++){
    //     for(int y1=-4;y1<=4;y1++){
    //         x=x1;y=y1;
     
    // cout<<x<<" "<<y<<"-> ";
    cin>>x>>y;
    if((abs(x)+abs(y))%2==0){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    int cur_p=(abs(x)+abs(y))+1;
    cur_p=ceil(1.0*log2(cur_p));
    res.clear();
    for(int cur=cur_p-1;cur>=0;cur--){
        // cout<<x<<" "<<y<<" \n";
        pair<int,int>dir=whichDirection(x,y);

        x=(x+dir.ff*(1<<cur));
        y=(y+dir.ss*(1<<cur));

    }
    // cout<<x<<" "<<y<<" \n";
    reverse(res.begin(),res.end());
    assert(x==0 && y==0);
    // if(x!=0 || y!=0){
    //     cout<<"Problem\n";
    //     return;
    // }
    cout<<res<<'\n';
    //    }
    // }
    
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