// AUTHOR: Sumit Prajapati      
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define int                 long long           
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define debug(x)            cerr<<#x<<" = "<<x<<'\n'
#define llrand()            distribution(generator)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()



auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e9;
const int MX=1e5+5;

 
int n,k;
int a[MX]; 
int segm[4*MX];

void buildtree(int cur,int start,int end){
    if(start==end){
       //BASE CASE
        segm[cur]=a[start];
        return;
    }
    int mid=(start+end)>>1;
    buildtree(cur<<1,start,mid);
    buildtree((cur<<1)+1,mid+1,end);
    //MERGING STEP
    segm[cur]=segm[2*cur]+segm[2*cur+1];

}
int query(int cur,int start,int end,int qs,int qe){
    if(start>=qs && end<=qe)
        return segm[cur];
    if(start>qe || end<qs)
        return 0;          //INVALID RETURN 
    int mid=(start+end)>>1;
    int A=query(2*cur,start,mid,qs,qe);
    int B=query(2*cur+1,mid+1,end,qs,qe);
    //MERGING STEP
    int res=A+B;  

    return res;
}
void update(int cur,int start,int end,int ind,int val){
    if(start==ind && start==end){
        //DO UPDATE
        segm[cur]=val;
        return;
    }
    if(start>ind|| end<ind)
        return;          //OUT OF RANGE 
    int mid=(start+end)>>1;
    update(cur<<1,start,mid,ind,val);
    update((cur<<1)^1,mid+1,end,ind,val);
    //MERGING STEP
    segm[cur]=segm[2*cur]+segm[2*cur+1];
}
 
 
void solve(){
  
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1])
            a[i+1]=1;
        else
            a[i+1]=2;
    }
    n--;
    int ind;
    if(n!=0)
        buildtree(1,1,n);
    repe(i,k){
        cin>>ind;
        if(n==0){
            cout<<"0\n"; 
            continue;
        }
        ind--;
        s[ind]=(s[ind]=='1')?'0':'1';
        if(ind==0){
            if(s[ind]==s[ind+1]){
                a[ind+1]=2;
                update(1,1,n,ind+1,2);
            }
            else{
                a[ind+1]=1;
                update(1,1,n,ind+1,1);
            }
        }   
        else if(ind==n){
            if(s[ind]==s[ind-1]){
                a[ind]=2;
                update(1,1,n,ind,2);
            }
            else{
                a[ind]=1;
                update(1,1,n,ind,1);
            }
        }
        else{
            if(s[ind]==s[ind-1]){
                a[ind]=2;
                update(1,1,n,ind,2);
            }
            else{
                a[ind]=1;
                update(1,1,n,ind,1);
            }
            if(s[ind]==s[ind+1]){
                a[ind+1]=2;
                update(1,1,n,ind+1,2);
            }
            else{
                a[ind+1]=1;
                update(1,1,n,ind+1,1);
            }
        }
        int res=query(1,1,n,1,n);
        cout<<res<<'\n';
    }
  
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}