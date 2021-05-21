//CODED BY SUMIT KUMAR PRAJAPATI
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
#define trav(v) for(auto &el:v)
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()

const int INF=1e9;
const int MX=1e2+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
 
int a[MX]; 
int N,Q,asked=0; 
vector<int>ans;
int gl_arr[MX];

// 2,1,3,5,4

int query(int x1,int x2,int x3){

    assert(asked<=Q);
    cout<<x1<<" "<<x2<<" "<<x3<<"\n";
    asked++;
    int resp;
    cin>>resp;
    return resp;
    // int i1=a[x1],i2=a[x2],i3=a[x3];
    // if((i1<i2 && i2<i3 ) || (i1>i2 && i2>i3)) 
    //     resp=x2;
    // if((i2<i1 && i1<i3 ) || (i2>i1 && i1>i3)) 
    //     resp=x1;
    // if((i1<i3 && i3<i2 ) || (i1>i3 && i3>i2)) 
    //     resp=x3;
    //  cout<<"-> "<<resp<<'\n';
    // return resp;
}
void generate_array(){
    
    repe(i,N){
        a[gl_arr[i]]=i;
    }
}
//5 4 3 2 1

void solve(){
  
    
    // generate_array();
    ans.clear();
    int ind=query(1,2,3);
    if(ind==1){
        ans.pb(2);
        ans.pb(1);
        ans.pb(3);
    }
    else if(ind==2){
        ans.pb(1);
        ans.pb(2);
        ans.pb(3);
    }
    else{
        ans.pb(1);
        ans.pb(3);
        ans.pb(2);
    }
  
    auto it=ans.begin();
    int n=ans.size();
    FOR(i,4,N){
        
        int last=ans[n-1],sec_last=ans[n-2];
        ind=query(sec_last,last,i);
        if(ind==i){
            ans.pb(i);
            swap(ans[n-1],ans[n]);
        }
        else if(ind==last){
            ans.pb(i);
        }
        else{
            //2 3 6 4 1, 7
            int l=0,r=n-3,mid,cur=0;
            while(l<=r){
                mid=(l+r)>>1;
                ind=query(ans[mid],ans[mid+1],i);
                if(ind!=ans[mid]){
                    if(ind==ans[mid+1])
                        cur=mid+2;
                    else
                        cur=mid+1;
                    l=mid+1;
                }
                else
                    r=mid-1;
            }
            it=ans.insert(ans.begin()+cur,i);
        }
        n++;
       
       
    }
    
    // cout<<asked<<" \n";
    rep(i,N)
        cout<<ans[i]<<" ";
    cout<<"\n";
    cin>>ind;
  
 // 10 3 4 7 5 1 2 9 8 6
} 
 
 
int main() {
    
    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    cin>>t;
    cin>>N>>Q;
    // repe(i,N)
    //     cin>>gl_arr[i];
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}