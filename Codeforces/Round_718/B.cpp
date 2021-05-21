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
const int MX=1e2+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
#define TESTCASES 1 
 
 
 
 
int n,m;
int b[MX][MX]; 

void helper(vector<int>& temp,int ind){

    pair<int,int>here[m+1];
    repe(i,m)
        here[i]={temp[i-1],i};
    int next[m+1];
    sort(here+1,here+m+1,[&](auto x,auto y){return x.ff>x.ss;});
    // if(ind==2){
    //     repe(i,m)
    //         cout<<here[i].ff<<" "<<here[i].ss<<"\n";
    //     cout<<"\n";
    // }
    for(int i=1;i<=m;i++){
        next[i]=b[ind][here[i].ss];
        temp[i-1]=min(temp[i-1],b[ind][here[i].ss]);
    }
    repe(i,m)
        cout<<next[i]<<" ";
    cout<<'\n';

}
void solve(){
  
    cin>>n>>m;
    repe(i,n){
        repe(j,m)
            cin>>b[i][j];
        sort(b[i]+1,b[i]+m+1);
    }

    vector<int>temp(b[1]+1,b[1]+m+1);
    trav(temp)
        cout<<el<<" ";
    cout<<'\n';
    for(int i=2;i<=n;i++){
        helper(temp,i);
        // rep(i,m)
        //     cout<<temp[i]<<" \n"[i==m-1];

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
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}