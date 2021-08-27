//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
#define int                 long long           
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




auto time0 = curtime;
const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e9;
const int MX=1e5+5;

 
 
string s; 
int n=10; 


void solve(){
    
    s.clear();
    s.pb('$');
    repe(i,n){
        char ch;
        cin>>ch;
        s.pb(ch);
    }
    
    int maxo=0,mino=0,maxe=0,mine=0;
    repe(i,n){
        if(i&1){
            if(s[i]=='1')
                maxo++,mino++;
            else if(s[i]=='?')
                maxo++;


        }
        else{
            if(s[i]=='1')
                maxe++,mine++;
            else if(s[i]=='?')
                maxe++;
        }

        if(i&1){
            bool op1=maxo>(mine+(n-i+1)/2);
            bool op2=maxe>(mino+(n-i-1)/2);
            if(op1|op2){
                cout<<i<<"\n";
                return;
            }
        }
        else{
            bool op1=maxo>(mine+(n-i)/2);
            bool op2=maxe>(mino+(n-i)/2);
            if(op1|op2){
                cout<<i<<"\n";
                return;
            }
        }


    }
    cout<<"10\n";
    return;
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}