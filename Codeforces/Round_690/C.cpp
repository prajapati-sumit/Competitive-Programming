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
 
 
 
 
 
 
void solve(){
    int x;
    cin>>x;
    if(x<=9){
        cout<<x<<'\n';
        return;
    }
    if(x>45){
        cout<<"-1\n";
        return;
    }
    int cur=9;
    vector<int>res;
    while((x-cur)>0){
        res.pb(cur);
        x-=cur;
        cur--;
    }
    if(x>0)
        res.pb(x);
    sort(all(res));
    for(auto el:res)
        cout<<el;
    cout<<'\n';
    
 
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
