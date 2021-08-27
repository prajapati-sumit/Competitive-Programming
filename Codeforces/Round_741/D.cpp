//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
// #define int                 long long
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
const int MX = 3e5 + 5;




int f(char ch){
    if(ch=='+')
        return 1;
    return -1;
}
string s;

map<int,vector<int>>mp;
int pref[MX];
void for_odd(int l,int r){
    if(l==r){
        cout<<l<<" \n";
        return; 
    }
    int c=pref[r]-pref[l-1];
    // p[x-1]-p[l-1]=p[r]-p[x]
    // p[x-1]+p[x]=p[r]-p[l-1];
    auto it=lower_bound(all(mp[c]),l);
    cout<<*it<<'\n';

}

void solve() {

    int n,q;
    cin>>n>>q;
    cin>>s;
    mp.clear();
    pref[0]=0;
    int mul=1;

    repe(i,n){
        pref[i]=pref[i-1]+mul*f(s[i-1]);
        mul*=-1;
        cout<<pref[i]<<" \n"[i==n];
    }
    mp[pref[1]].pb(1);
    FOR(i,2,n){
        mp[pref[i]+pref[i-1]].pb(i);
    }

    repe(i,q){
        int l,r;
        cin>>l>>r;
        int sum=pref[r]-pref[l-1];
        if(!(l&1))
            sum*=-1;
        cout<<sum<<'\n';
        
        if(sum==0){
            cout<<"0\n";
        }
        else if((r-l+1)&1){
            cout<<"1\n";
            for_odd(l,r);

        }
        else{
            cout<<"2\n";
            cout<<r<<" ";
            for_odd(l,r-1);
        }

    }


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