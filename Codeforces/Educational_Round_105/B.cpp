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
 
 
int wall[4]; 
bool fn(int n,int U,int R,int D,int L){
    if(U<n && R<n && D<n && L<n)
        return true;
    int cnt=(U==n)+(R==n)+(D==n)+(L==n);
    if(cnt>=3){
        rep(i,4){
            if(wall[i]!=n){
                return (wall[i]>=2);
            }
            
        }
        return true;
    }
    if(cnt==2){

        bool flag=false;
        rep(i,3)
            if(wall[i]==wall[i+1]){
                flag=true;
                break;
            }
        if(wall[0]==wall[3])
            flag=true;
        //cout<<flag<<"&\n";
        if(flag){
            rep(i,4){
                if(wall[i]!=n){
                    if(wall[i]<1)
                        return false;
                }
                
            }
            return true;
        }
        else{
            rep(i,4){
                if(wall[i]!=n){
                    if(wall[i]<2)
                        return false;
                }
                
            }
            return true;
        }
    }
    if(cnt==1){
         rep(i,4){
            if(wall[i]!=n){
                if(wall[i]==0 && (wall[(i+1)%4]!=n &&wall[((i-1)%4+4)%4]!=n))
                    return false;
            }
            
        }
        return true;

    }
    return true;
}

void solve(){
  
    int n,U,R,D,L;
    cin>>n>>U>>R>>D>>L;
    wall[0]=U;
    wall[1]=R;
    wall[2]=D;
    wall[3]=L;
    bool flag=fn(n,U,R,D,L);

    if(flag)
        cout<<"YES\n";
    else
        cout<<"NO\n";
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