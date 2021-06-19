//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define int                 long long           
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()
auto time0=curtime;
 
ll bin_power(ll a,ll b,ll md){
    ll res=1;
    while (b){
        if (b&1)
            res=(res*a)%md;
        a=(a*a)%md;
        b>>=1;
    }
    return res;
}
 
void solve(){
  
    int a,b,k;
    cin>>a>>b>>k;
    if(k==1){
        if(a==b)
            cout<<"NO\n";
        else if(a%b==0 || b%a==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        return;
    }
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    int a_sum=0,b_sum=0;
    int A=a,B=b;
    for(int i=2;i*i<=a;i++){
        if(a%i==0){
            int cnt=0;
            while(a%i==0)
                a/=i,cnt++;
            a_sum+=cnt;
        }
    }  
    if(a>1)
        a_sum+=1;

    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    for(int i=2;i*i<=b;i++){
        if(b%i==0){
            int cnt=0;
            while(b%i==0)
                b/=i,cnt++;
            b_sum+=cnt;
        }
    }  
    if(b>1)
        b_sum+=1;
    cout<<((a_sum+b_sum)>=k?"YES\n":"NO\n");
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    cin>>t;
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    while(t--){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}