#include <bits/stdc++.h>
using namespace std;
 
//CODED BY SUMIT KUMAR PRAJAPATI
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;

#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
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
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
 
 
 
 
int freq[20];
 
void solve(){

    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    int distinct=0;
    for(auto ch:s){
        if(freq[ch-'a']==0)
            distinct++;
        freq[ch-'a']++;
    }
    //cout<<distinct<<'\n';
    if(distinct<=k){
        cout<<"0\n";
        return;
    }
    int n_op=distinct-k;
    int cost[20];
    rep(i,20)
        cost[i]=0;
    
    for(int i=0;i<20;i++){
        for(int j=i+1;j<20;j++){
            if(freq[j]!=0 && freq[i]!=0)
                cost[j-i]+=min(freq[j],freq[i]);
        }
    }
    int ans=0;
    rep(i,20){
        if(n_op<=cost[i]){
            ans+=(n_op)*i;
            break;
        }
        else{
            ans+=cost[i]*i;
            n_op-=cost[i];
        }

    }
    cout<<ans<<'\n';

    
  
 
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
    cin>>t;
    while(t--)
        solve();
    
    auto timeend=curtime;
    auto extime=timedif(time0,timeend)*1e-9;
    cerr<<"Execution Time: "<<extime<<" sec\n";
    return 0;
 
}