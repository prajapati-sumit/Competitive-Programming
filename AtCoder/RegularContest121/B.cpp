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
#define MD                  1'000'000'007
#define MDL                 998244353
#define MX                  100'005


const ll INF=1e16;
auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
ll minimum_dif(vector<ll>& a,vector<ll>& b){
    ll res=INF;
    if(a.size()==0)
        return INF;
    if(b.size()==0)
        return INF;
    for(auto &el:b){
        ll l=0,r=a.size()-1;
        ll mid,ind=r;
        while(l<=r){
            mid=(l+r)>>1;
            if(a[mid]>=el){
                r=mid-1;
                ind=mid;
            }
            else
                l=mid+1;
        }
        res=min(res,abs(el-a[ind]));
        if(ind>0)
            res=min(res,abs(el-a[ind-1]));
        if(ind<(a.size()-1))
            res=min(res,abs(el-a[ind+1]));
    }
    return res;
}

void solve(){
    
    ll n;cin>>n;
    vector<ll>R,G,B;
    ll x;
    char ch;
    repe(i,2*n){
        cin>>x>>ch;
        if(ch=='R')
            R.pb(x);
        else if(ch=='G')
            G.pb(x);
        else
            B.pb(x);
    }
    sort(all(R));
    sort(all(G));
    sort(all(B));
    ll sz1=R.size(),sz2=G.size(),sz3=B.size();
    if(sz1%2==0 && sz2%2==0 && sz3%2==0){
        cout<<"0";
        return;
    }
    // cout<<sz1<<" "<<sz2<<" "<<sz3<<'\n';
    // return;
    assert(((sz1%2)+(sz2%2)+(sz3%2))==2);
    ll res=INF;
    ll GB=minimum_dif(B,G),RB=minimum_dif(R,B),RG=minimum_dif(R,G);
    if(sz1%2==0){
        res=min(GB,RB+RG);
    }
    else if(sz2%2==0){
        res=min(RB,RG+GB);
    }
    else{
        res=min(RG,RB+GB);
    }

    cout<<res;
 
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