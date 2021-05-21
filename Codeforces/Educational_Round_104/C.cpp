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
 
 
 
 
 
 
void solve(){
  
    int n;
    cin>>n;
    if(n==2)
    {
        cout<<"0\n";
        return;
    }    
    int wins=n/3,draws=n%3,total=wins+draws;
    int values[]={0,1,1,1,0,-1,-1,-1};
    // repe(i,n-1){
    //     if(i<=wins)
    //         values[i]=1;
    //     else if(i<=(total))
    //         values[i]=0;
    //     else values[i]=-1;
    // }
    int scores[n+1];
    repe(i,n)
        scores[i]=0;
    int f=1;
    FOR(i,1,n-1){
        int s=f+1;
        FOR(j,1,n-i){
            if(values[j]==1){
                scores[f]+=3;
            }
            else if(values[j]==0){
                scores[f]+=1;
                scores[s]+=1;
            }
            else scores[s]+=3;
            cout<<values[j]<<" ";
            s+=1;
        }
        f+=1;
        //cout<<'\n';
    }
    cout<<'\n';
    printar(scores,1,n);
 
} 
 
 
int main() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    #endif

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