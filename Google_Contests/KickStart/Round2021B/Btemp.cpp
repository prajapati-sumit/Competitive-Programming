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
 
 
 const ll INF=1e17;
 const ll MX=1e5+5;
 const ll MD=1e9+7;
 const ll MDL=998244353;
 auto time0 = curtime;
 #define TESTCASES 1 
  
  
  
  
  
 void solve(){
   
    ll n;
    cin>>n;
    ll a[n+1];
    repe(i,n)
        cin>>a[i];
    a[0]=INF;
    ll dif[n];
    dif[0]=INF;
    repe(i,n-1)
        dif[i]=a[i+1]-a[i];
    
    vector<ll> ltor(n+2,1),rtol(n+2,1);
    rtol[n]=0;
    rtol[n+1]=0;
    rtol[0]=0;
    ltor[0]=0;
    ltor[n]=0;
    ltor[n+1]=0;
    for(ll i=1;i<=n-1;i++)
        if(dif[i]==dif[i-1])
            ltor[i]+=ltor[i-1];
    for(ll i=n-2;i>=1;i--)
        if(dif[i]==dif[i+1])
            rtol[i]+=rtol[i+1];
    ll best=0;
    
    best=max(best,1+rtol[2]); 
    best=max(best,1+ltor[n-2]);

    for(ll i=1;i<=n-1;i++){
        // cout<<i<<"-> ";
        
        ll here1=0,here2=0;
        ll dl=dif[i-1],x=dif[i],y=dif[i+1],dr=dif[i+2];
        ll p=dl-x;
        ll newx=x+p,newy=y-p;
        // cout<<x<<" "<<y<<" ";
        // cout<<newx<<" "<<newy<<" "<<rtol[i+2]<<" "<<ltor[i-1]<<" ";
        here1+=1+ltor[i-1];
        if(newy==dif[i-1]){
            if(newy==dif[i+2])
                here1+=1+rtol[i+2];
            else
                here1++;
        }
        
        p=dr-y;
        newx=x-p;
        newy=y+p;
        here2+=1+rtol[i+2];
        if(newx==dif[i+2]){
            if(newx==dif[i-1])
                here2+=(1+ltor[i-1]);
            else
                here2++;
        }
        // cout<<here1<<" "<<here2<<" ";
        best=max({best,here2,here1});
        // cout<<best<<"\n";
    }
    best++;
    // cerr<<best<<'\n';
    cout<<best<<'\n';
   
  
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