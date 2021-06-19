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
 
 
 
 
 
 
void solve(){
  
    int n;
    cin>>n;
    int a[n+1];
    int freq[n+1];
    repe(i,n)
        freq[i]=0;
    repe(i,n)
        cin>>a[i],freq[a[i]]++;
    vector<int> absent,present;
    repe(i,n)
        if(freq[i]==0)
            absent.pb(i);
        else
            for(int j=1;j<freq[i];j++)
                present.pb(i);

    int sz=present.size();
    int moves=0;
    rep(i,sz){
        if(present[i]>absent[i]){
            cout<<"Second\n";
            return;
        }
        moves+=(absent[i]-present[i]);
    }
    if(moves&1)
        cout<<"First\n";
    else
        cout<<"Second\n";
    
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}