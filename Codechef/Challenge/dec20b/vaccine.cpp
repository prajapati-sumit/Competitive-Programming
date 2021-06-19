#include <bits/stdc++.h>
using namespace std;
 
//CODED BY SUMIT KUMAR PRAJAPATI
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef long double ld;

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
 
 
 
 
 
 
void solve(){
    ll d1,v1,d2,v2,p,D1,D2,V1,V2;
    cin>>d1>>v1>>d2>>v2>>p;
    if(d1<d2){
        D1=d1;
        D2=d2;
        V1=v1;
        V2=v2;
    }
    else{
        D2=d1;
        D1=d2;
        V2=v1;
        V1=v2;
    }
    ll ansalone=(p+D1*V1-V1);
    p=(p+d1*v1+d2*v2-v1-v2);
    //cout<<ansalone<<'\n';
    ansalone=ceil(ld((1.0*ansalone)/(V1)));
    if(ansalone<D2){
        cout<<ansalone;
        return;
    }
    ll ans=ceil(ld((1.0*p)/(v1+v2)));
    cout<<ans;
 
} 
 
 
 int main() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
     #else
         ios_base::sync_with_stdio(false);
        cin.tie(NULL);
          cout.tie(NULL);
     #endif

    srand(time(0));	

    time0 = curtime;
    ll t=1;
  //  cin>>t;
    while(t--)
        solve();
 
    return 0;
 
}
