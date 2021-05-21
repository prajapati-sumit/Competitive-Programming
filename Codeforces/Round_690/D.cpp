#include <bits/stdc++.h>
using namespace std;
 
//CODED BY SUMIT KUMAR PRAJAPATI
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;

#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
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
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
 
 
int n; 
 
int binary(int ar[],int l,int r,int key){
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        if(ar[mid]==key)
            return mid;
        else if(ar[mid]>key)
            r=mid-1;
        else 
            l=mid+1;
    }
    return -1;
}
bool fn(int pref[],int op,int sum){

    if(sum%(n-op)!=0)
        return false;
    int each=sum/(n-op);
    int val=each;
    int cnt=0,start=1,end=n;
    while(cnt<(n-op)){
        cnt++;
        
        int fl=binary(pref,start,end,val);
       
        if(fl==-1)
            return false;
        start=fl+1;
        val+=each;

        

    }
    return true;
} 
 
void solve(){
 
    
    cin>>n;
    int a[n+1];
    a[0]=0;
    int sum=0;
    repe(i,n)
        cin>>a[i],sum+=a[i];
    int pref[n+1];
    pref[0]=0;
    repe(i,n)
        pref[i]=pref[i-1]+a[i];
    
    
    int ans=-1;
    rep(mid,n){
        
        bool dd=fn(pref,mid,sum);
       // cout<<dd<<" "<<mid<<"\n";
        if(dd){
            
            ans=mid;
           break;
        }
       
    }
    cout<<ans<<'\n';


} 
 
 
 int main() {

    
         ios_base::sync_with_stdio(false);
        cin.tie(NULL);
          cout.tie(NULL);
    

    srand(time(0));	

    time0 = curtime;
    ll t=1;
    cin>>t;
    while(t--)
        solve();
 
    return 0;
 
}
