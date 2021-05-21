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
ll MD=(1LL<<63);
const int MDL=998244353;
auto time0 = curtime;
 
 
 
int w; 
ll hidden[]={0,89,95,54,3,1,21};
ll dayn=195;
ll R[7];


ll exp(ll total,ll i){
    if(i==0 || (total/i)>=63)
        return 0;
    return 1LL<<(total/i);  
}

ll query(ll day){
    cout<<day<<" \n";
    ll resp;
    cin>>resp;
    return resp;
    // resp=0;
    // for(int i=1;i<=6;i++)
    //     resp=(resp+hidden[i]*exp(day,i))%MD;
    

    // return resp;
} 

void decode1(ll x,ll day){
  
    ll cur=6;
    while(cur>3){
        ll en=exp(day,cur-1);
        ll eh=exp(day,cur);
        ll temp=x;
        if(en!=0)
            temp%=en;
        x-=temp;
        temp/=eh;
        R[cur]=temp;
        cur-=1;
    }
}
void decode2(ll x,ll day){
    ll cur=3;
    while(cur>0){
        ll en=exp(day,cur-1);
        ll eh=exp(day,cur);
        ll temp=x;
        if(en!=0)
            temp%=en;
        x-=temp;
        temp/=eh;
        R[cur]=temp;
        cur-=1;
    }

}
void solve(){
    dayn=195;
    ll key=query(dayn);
    decode1(key,dayn);
 
    dayn=50;
    key=query(dayn);
    for(ll i=4;i<=6;i++)
        key-=(R[i]*exp(dayn,i));
    decode2(key,dayn);
    repe(i,6)
        cout<<R[i]<<" \n"[i==6];
    cin>>key;
    assert(key==1);  
 
} 
 
 
int main() {
    
    srand(time(0)); 
    time0 = curtime;

    int t=1;
    cin>>t>>w;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}