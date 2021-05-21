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
 
 
 
 
 
void solve(){
  
    int r,c;
    cin>>r>>c;
    char a[r+1][c+1];
    repe(i,r)
        repe(j,c)
            cin>>a[i][j];
    // repe(i,r){
    //     repe(j,c)
    //         cout<<a[i][j];
    //     cout<<'\n';
    // }
    repe(i,r){
        repe(j,c){
            if(a[i][j]=='?' && j!=1)
                a[i][j]=a[i][j-1];
        }
    }
    //  repe(i,r){
    //     repe(j,c)
    //         cout<<a[i][j];
    //     cout<<'\n';
    // }
    repe(i,r){
        for(int j=c;j>=1;j--){
            if(a[i][j]=='?' && j<c)
                a[i][j]=a[i][j+1];
        }
    }
    //  repe(i,r){
    //     repe(j,c)
    //         cout<<a[i][j];
    //     cout<<'\n';
    // }

    while(true){
        bool flag=true;
        repe(i,r){
            repe(j,c){
                if(a[i][j]=='?'){
                    flag=false;
                    if(i==1){
                        a[i][j]=a[i+1][j];
                    }
                    else if (i==r){
                        a[i][j]=a[i-1][j];
                    }
                    else
                        a[i][j]=a[i-1][j]!='?'?a[i-1][j]:a[i+1][j];
                  
                }
            }
        }
   
        if(flag)
            break;
    }
    repe(i,r){
        repe(j,c)
            cout<<a[i][j];
        cout<<'\n';
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
        cout<<"Case #"<<tt<<": \n";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}