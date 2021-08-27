//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
#define int                 long long
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define SZ(x)               ((int)x.size())
#define set_bits            __builtin_popcountll
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;





void solve() {

    int n;
    cin>>n;
    int L[n+1],R[n+1];
    map<int,int>mp;
    map<int,int>rev;
    repe(i,n){
        cin>>L[i]>>R[i];
        mp[L[i]];
        mp[R[i]];
    }
    int nax=1;
    for(auto &el:mp){
        rev[nax]=el.ff;
        el.ss=nax++;
    }
    repe(i,n){
        L[i]=mp[L[i]];R[i]=mp[R[i]];
    }

    vector<int>arr(nax+2,0);
    repe(i,n)
        arr[L[i]]++,arr[R[i]+1]--;

    repe(i,nax)
        arr[i]+=arr[i-1];
    repe(i,nax)
        arr[i]+=arr[i-1];
    // repe(i,nax)
    //     cout<<arr[i]<<" \n"[i==nax];
    // return;

    repe(i,n){
        int sum=arr[R[i]]-arr[L[i]-1];
        int len=rev[R[i]]-rev[L[i]]+1;
        cout<<L[i]<<" "<<R[i]<<" "<<sum<<" "<<len<<'\n';
        // if(sum>len){
        //     cout<<"No\n";
        //     return;
        // }
    }
    cout<<"Yes\n";


}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}