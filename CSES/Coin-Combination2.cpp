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
#define MX                  100'0001


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?

void fastscan(int &x){

    int c;
    x =0;
    c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
}


void solve(){



    int n,x;
    fastscan(n);
    fastscan(x);

    int a[n];

    rep(i,n)
    fastscan(a[i]);
    int dp[n][x+1];



    for( int i=0;i<n;i++){
        for(int xx=0;xx<=x;xx++){

            if(xx==0)
                dp[i][xx]=1;

            else{
                int op1= (i==0)     ? 0 :   dp[i-1][xx];
                int op2= (a[i]>xx)  ? 0 :   dp[i][xx-a[i]];
                dp[i][xx]=( op1 + op2 )%MD;
            }
        }
    }
    cout<<dp[n-1][x];


}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    // cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }

    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}