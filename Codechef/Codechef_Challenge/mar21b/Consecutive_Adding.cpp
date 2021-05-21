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

const ll INF=1e9;
const ll MX=1e3+2;
const ll MD=1e9+7;
const ll MDL=998244353;
auto time0 = curtime;
 
 
 
ll R,C,X,A[MX][MX],B[MX][MX],dif[MX][MX]; 
void printdif(){
    repe(i,R){
        repe(j,C)
            cout<<dif[i][j]<<" ";
        cout<<'\n';
    }
    cout<<'\n';
}
void fastscan(ll &x)
{
    bool neg=false;
    ll c;
    x =0;
    c=getchar();
    if(c=='-')
    {
        neg = true;
        c=getchar();
    }
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *=-1;
}
void solve(){

    fastscan(R);
    fastscan(C);
    fastscan(X);
    repe(i,R)
        repe(j,C)
            fastscan(A[i][j]);
    ll totalSum=0;
    repe(i,R)
        repe(j,C){
            fastscan(B[i][j]);
            dif[i][j]=A[i][j]-B[i][j];
            totalSum+=dif[i][j]; 
        }
    if(abs(totalSum)%X) {
        cout<<"No\n";
        return;
    }

    repe(i,R){
        repe(j,C-X+1){
            if(dif[i][j]!=0){
                for(int k=1;k<X;k++)
                    dif[i][j+k]-=dif[i][j];
                dif[i][j]=0;
            }
        }
    }

    repe(j,C){
        repe(i,R-X+1){
            if(dif[i][j]!=0){
                for(int k=1;k<X;k++)
                    dif[i+k][j]-=dif[i][j];
                dif[i][j]=0;
            }
        }
    }
    repe(i,R)
        repe(j,C)
            if(dif[i][j]!=0){
                cout<<"No\n";
                return;
            }
    cout<<"Yes\n";
    //------------------
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    fastscan(t);
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}