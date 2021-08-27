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




string res;
void solve() {


    string s;
    cin>>s;
    int n=s.length();
    vector<int>freq(26,0);
    rep(i,n)
        freq[s[i]-'a']++;
    bool ok=true;
    rep(i,26)
        if(freq[i]>n/2){
            ok=false;
            break;
        }
    if(!ok){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    res.clear();
    rep(i,n)
        res.pb('$');

    vector<pii>v;
    rep(i,26)
        v.pb({freq[i],i});
    sort(all(v),[](auto p,auto q){
        if(p.ff==q.ff)
            return p.ss>q.ss;
        
        return p.ff>q.ff;
    });
    int last=-1;
    char c='$';
    rep(i,26){
        int freq=v[i].ff;
        char ch=v[i].ss+'a';
        if(!freq)
            continue;
        // cout<<freq<<" "<<ch<<'\n';
        for(int j=0;j<n;j++){
            if(res[j]=='$' && s[j]!=ch && freq){
                last=j;
                res[j]=ch;
                freq--;
            }
        }
        if(freq){
            c=ch;
        }
    }
    if(res[n-1]=='$'){
        res[n-1]=c;
        swap(res[last],res[n-1]);
    }
    rep(i,n)
        assert(res[i]!='$' && s[i]!=res[i]);
    
    cout<<res<<'\n';

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    cin >> t;
    repe(tt, t) {
        cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}