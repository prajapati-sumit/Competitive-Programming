// AUTHOR: Sumit Prajapati      
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long           
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define debug(x)            cerr<<#x<<" = "<<x<<'\n'
#define llrand()            distribution(generator)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define endl                '\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define INF                 1'000'000'000
#define MD                  1'000'000'007
#define MDL                 998244353
#define MX                  100'005


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
 
 
int a[101][101]; 
int cand[10001];

bool check(int n){
    repe(i,n){
        repe(j,n){
            
            if(i-1>0 && abs(a[i-1][j]-a[i][j])==1){
                // cout<<a[i][j]<<" ";
                return false;
            }
            if(j-1>0 && abs(a[i][j-1]-a[i][j])==1){
                // cout<<a[i][j]<<" ";

                return false;
            }
            if(i+1<=n && abs(a[i+1][j]-a[i][j])==1){
                // cout<<a[i][j]<<" ";

                return false;
            }
            if(j+1<=n && abs(a[i][j+1]-a[i][j])==1)
            {
                // cout<<a[i][j]<<" ";

                return false;
            }
        }
    }
    return true;
}

void solve(){
  
    int n;
    cin>>n;

    int cnt=1;
    repe(i,n)
        a[i][i]=cnt++;
    repe(dif,n-1){
        int start=1+dif,j=1;
        FOR(i,start,n){
            a[i][j++]=cnt++;
        }
        j=1;
        FOR(i,start,n){
            a[j++][i]=cnt++;
        }
    }
    assert(cnt==n*n+1);
    if(!check(n)){cout<<"-1\n";return;}
    repe(i,n)
        repe(j,n)
            cout<<a[i][j]<<" \n"[j==n];
  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    repe(i,10001)
        cand[i]=i;
    time0 = curtime;

    int t=1;
    cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}