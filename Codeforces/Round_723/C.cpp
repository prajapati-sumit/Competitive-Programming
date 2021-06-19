// AUTHOR: Sumit Prajapati      
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long           
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
#define endl                '\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()
const ll INF=1e16;
#define MD                  1'000'000'007
#define MDL                 998244353
#define MX                  200'005


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
 
 
ll n;
ll a[MX];
ll segm[4*MX];
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
ll query(int cur,int start,int end,int qs,int qe){
    if(start>=qs && end<=qe)
        return segm[cur];
    if(start>qe || end<qs)
        return 0;          //INVALID RETURN 
    int mid=(start+end)>>1;
    ll A=query(2*cur,start,mid,qs,qe);
    ll B=query(2*cur+1,mid+1,end,qs,qe);
    //MERGING STEP
    ll res=A+B;  

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
  
    cin>>n;
    //RANGE UPDATES POINT QUERY...
    vector<pll>neg;
    repe(i,n){   
        cin>>a[i];
        if(a[i]<0){
            neg.pb({a[i],i});
            a[i]=0;
        }
        
    }
    
    ll sz=neg.size();
    sort(all(neg),[&](auto x,auto y){
        if(x.ff==y.ff)
            return x.ss<y.ss;
        return x.ff>y.ff;
    });
    buildtree(1,1,n);
    ll ans=n-sz;
    // cout<<ans<<'\n';
    rep(i,sz){
        ll ind=neg[i].ss;
        ll sum_till_here=query(1,1,n,1,ind);
        ll sum_after=query(1,1,n,ind,n);
        // cout<<sum_till_here<<" ";
        //     cout<<neg[i].ff<<" "<<neg[i].ss<<'\n';
        if(sum_till_here+neg[i].ff>=0 && sum_after+sum_till_here+neg[i].ff>=0){
            ans++;
            a[ind]=neg[i].ff;
            update(1,1,n,ind,a[ind]);
        }
    }
    cout<<ans<<'\n';
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    // cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}