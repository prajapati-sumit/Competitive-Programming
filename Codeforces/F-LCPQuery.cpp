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
#define INF                 1'000'000'000
#define MD                  1'000'000'007
#define MDL                 998244353
#define MX                  100'005


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
struct Node{
    int least;
    int value;
};

Node segm[4*MX];
string s[MX];

// Node query(int cur,int start,int end,int qs,int qe){
//     if(start>=qs && end<=qe)
//         return segm[cur];
//     if(start>qe || end<qs)
//         return -1;          //INVALID RETURN
//     int mid=(start+end)>>1;
//     int A=query(2*cur,start,mid,qs,qe);
//     int B=query(2*cur+1,mid+1,end,qs,qe);
//     int res=                //MERGING STEP

//         return res;
// }
// void update(int cur,int start,int end,int ind,Node val){
//     if(start==ind && start==end){
//         //DO UPDATE
//         segm[cur]=val;
//         return;
//     }
//     if(start>ind|| end<ind)
//         return;          //OUT OF RANGE
//     int mid=(start+end)>>1;
//     update(cur<<1,start,mid,ind,val);
//     update((cur<<1)^1,mid+1,end,ind,val);
//     //MERGING STEP
//     segm[cur].value=max(segm[2*cur].value,segm[2*cur+1].value);
//     segm[cur].least=min(segm[2*cur].least,segm[2*cur+1].least)
// }

// int lcp(int i, int j){
//     int it=0;
//     for(;it<s[i].length()&&it<s[j].length()&&s[i][it]==s[j][it];it++);

//     return it;
// }




void solve(){

    cout<<"Hi From Sublime\n";
    cout<<"Hi From Sublime\n";
    return;
    // int n,q;
    // cin>>n>>q;

    // rep(i,n)
    // cin>>s[i];
    // int N=n-1;
    // int LCP[N];
    // rep(i,N){
    //     LCP[i]=lcp(i,i+1);
    // }
    // rep(i,q){
    //     int type;
    //     cin>>type;
    //     if(type==1){
    //         int l,r;
    //         cin>>l>>r;
    //         int ans=query(1,1,N,l,r);
    //     }
    //     else{
    //         int ind;
    //         string st;
    //         cin>>ind>>st;
    //         ind--;
    //         s[ind]=st;
    //         if(ind==0){

    //             int lcp1=lcp(ind,ind+1);
    //             LCP[ind]=lcp1;

    //         }
    //         else if(ind==n-1){

    //             int lcp4=lcp(ind,ind-1);
    //             LCP[ind-1]=lcp4;

    //         }
    //         else{

    //             int lcp2=lcp(ind,ind+1);
    //             LCP[ind]=lcp2;
    //             int lcp3=lcp(ind,ind-1);
    //             LCP[ind-1]=lcp3;

    //         }
    //     }
    // }



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