#include <bits/stdc++.h>
using namespace std;
 
//CODED BY SUMIT KUMAR PRAJAPATI
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pl;

#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(s)   scanf("%s",s)
#define pi(x)   printf("%d\n",x)
#define pl(x)   printf("%lld\n",x)
#define ps(s)   printf("%s\n",s)
#define PI 3.1415926535897932384626
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()
const int MX=1e5+5;
const ll range=1e9;
const int MDL=99824453;
auto time0 = curtime;
ll R=999999995;
ll X=-1,Y=3; 
ll T,A,B;
ll exch=0;
bool test_flag;
string JUDGE(ll x,ll y){
    
    assert(exch<=300);
    exch++;

    string s;
    cout<<x<<" "<<y<<'\n';
    cin>>s;
    assert(s!="WRONG");

    if(s=="CENTER")
        test_flag=true;

    
    return s;
    
    
    
    // ll ans=(x-X)*(x-X)+(y-Y)*(y-Y);
    // if(ans==0){
    //     test_flag=1;
    //     // cout<<x<<" "<<y<<" "<<X<<" "<<Y<<'\n';
    //     return "CENTER";
    // }
    // if(ans<(R*R)){
    //     return "HIT";
    // }
    // return "MISS";
}
 
long long llrand() {
    long long r = 0;

    for (int i = 0; i < 5; ++i) {
        r = (r << 15) | (rand() & 0x7FFF);
    }

    return r & 0xFFFFFFFFFFFFFFFFULL;
} 
 
 
ll goleft(ll l, ll r,ll fixed){
    ll res=range,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(test_flag)
            return 0;

        if(JUDGE(mid,fixed)!="MISS"){
            res=min(res,mid);
            r=mid-1;
        }
        else l=mid+1;


    }
    return res;
}
ll goright(ll l,ll r,ll fixed){
    ll res=-range,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(test_flag)
            return 0;

        if(JUDGE(mid,fixed)!="MISS"){
            res=max(res,mid);
            l=mid+1;
        }
        else r=mid-1;


    }
    return res;
}
ll goup(ll l,ll r,ll fixed){
    ll res=-range,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(JUDGE(fixed,mid)!="MISS"){
            res=max(res,mid);
            l=mid+1;
        }
        else r=mid-1;


    }
    return res;
}
ll godown(ll l,ll r,ll fixed){
    ll res=range,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(test_flag)
            return 0;
        if(JUDGE(fixed,mid)!="MISS"){
            res=min(res,mid);
            r=mid-1;
        }
        else l=mid+1;


    }
    return res;
}
void solve(){
 
    ll x,y;
    test_flag=0;
    string resp;
    while(true){
        if(test_flag)
            return;
        x=(llrand()%(2*range+1))-range;
        y=(llrand()%(2*range+1))-range;
        
        resp=JUDGE(x,y);
        if(resp!="MISS")
            break; 
    }
    
    
    ll pu=goup(y,range,x);
    if(test_flag)
        return;

    ll pd=godown(-range,y,x);
    if(test_flag)
        return;
    ll pl=goleft(-range,x,y);
    if(test_flag)
        return;
    ll pr=goright(x,range,y);
    if(test_flag)
        return;
    x=(pl+pr)/2;
    y=(pu+pd)/2;
   
   
    resp=JUDGE(x,y);
    if(test_flag)
        return;
    

 
} 
 
 
 int main() {

   
    
     

    srand(time(0)); 

 
    
    cin>>T>>A>>B;
    while(T--)
        solve();
 
    return 0;
 
}
