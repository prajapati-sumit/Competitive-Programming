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


const int INF=15e8+7;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
#define TESTCASES 1 
 
 
ll L,R;

ll fn(ll x){
    return (x*(x+1))/2;
}
ll helper(ll x){
    ll l=0,r=INF,mid,ans;
    while(l<=r){
        mid=(l+r)>>1;
        ll cur=fn(mid);
        if(cur<=x)
            ans=mid,l=mid+1;
        else 
            r=mid-1;
    }
    return ans;

}
ll fn2(ll s,ll x){
    return x*(x+s-1);
}
ll helper2(ll s,ll x){
    ll l=0,r=INF,mid,ans=-1;
    while(l<=r){
        mid=(l+r)>>1;
        ll cur=fn2(s,mid);
        if(cur<=x){
            ans=mid;
            l=mid+1;
        }
        else 
            r=mid-1;
    }
    return ans;

}
void solve(){
  
    
    cin>>L>>R;
    ll can_max=helper(abs(R-L));
    if(R>L)
        R-=fn(can_max);
    else
        L-=fn(can_max);
    ll s_R,s_L;
    if(R>L){
        s_R=can_max+1;
        s_L=can_max+2;
    }
    else{
        s_R=can_max+2;
        s_L=can_max+1;
    }
    ll A=helper2(s_L,L);
    ll B=helper2(s_R,R);
    L-=fn2(s_L,A);
    R-=fn2(s_R,B);
    can_max+=A+B;
    cout<<can_max<<" "<<L<<" "<<R<<"\n";


 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    if(TESTCASES)cin>>t;
    repe(tt,t){
        cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}