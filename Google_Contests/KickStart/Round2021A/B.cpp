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
const int MX=1e3+1;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
 
 
 
int a[MX][MX];
int r,c; 

void solve(){
  
    cin>>r>>c;
    repe(i,r)
        repe(j,c){
            cin>>a[i][j];
        }
    


    ll ans=0;
    repe(i,r){
        repe(j,c){
            if(a[i][j]==0)
                continue;
            int it1=i,it2=j,up=0,down=0,right=0,left=0;
            // cout<<neigh[i][j].up<<"\n";
            while(it1<=r && a[it1][j])
                down++,it1++;
            it1=i;
            while(it1>0 && a[it1][j])
                up++,it1--;

            while(it2<=r && a[i][it2])
                right++,it2++;
            it2=j;
            while(it2>0 && a[i][it2])
                left++,it2--;
            // if(i==1 && j==1){
            //     cout<<up<<" "<<down<<" "<<right<<" "<<left<<"\n";
            // }
            if(up!=1 && left!=1)
                ans+=min(up,left/2)+min(up/2,left)-2;
            if(up!=1 && right!=1)
                ans+=min(up,right/2)+min(up/2,right)-2;
            if(down!=1 && left!=1)
                ans+=min(down,left/2)+min(down/2,left)-2;
            if(down!=1 && right!=1)
                ans+=min(down,right/2)+min(down/2,right)-2;
        }
    }
    cout<<ans<<'\n';
    
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    cin>>t;
    repe(tt,t){
        cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}