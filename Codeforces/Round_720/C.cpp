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
 
 
int hidden[]={0,2,5,3,4,1}; 
int n;


int query(int type,int i,int j,int x){
    cout<<"? "<<type<<" "<<i<<" "<<j<<" "<<x<<'\n';
    int resp;
    cin>>resp;
    // if(type==1)
    //     resp=max(min(x,hidden[i]),min(x+1,hidden[j]));
    // else
    //     resp=min(max(x,hidden[i]),max(x+1,hidden[j]));
    return resp;
}
void solve(){
    
    cin>>n;
    int oneis=-1;
    for(int r=1;r<n;r+=2){
        int i=r,j=r+1;
        int qu=query(2,i,j,1);
        if(qu==1){
            oneis=i;
            break;
        }
        else if(qu==2){
            qu=query(2,j,i,1);
            if(qu==1){
                oneis=j;
                break;
            }
        }
        if(r+1==n-1)
            r--;
        

    }  
    assert(oneis!=-1);
    int iknow[n+1];
    iknow[oneis]=1;
    repe(i,n){
        if(i!=oneis){
            int qu=query(1,oneis,i,n-1);
            iknow[i]=qu;
        }
    }
    cout<<"! ";
    printar(iknow,1,n);
           
  
 
} 
 
 
int main() {
    
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