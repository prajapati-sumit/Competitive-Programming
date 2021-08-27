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
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




auto time0 = curtime;
const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e9;
const int MX=1e5+5;

 
 
int freq[26]; 

bool update(int &x){
    // assert(freq[x]<=0);
    FOR(i,x+1,25){
        if(freq[i]){
            x=i;
            return true;
        }
    }
    return false;
}
void solve(){
  
    // aaaabbccc
    // a bab ac ac acc 
    // aababaccc       
    string s;
    cin>>s;
    int n=s.length();
    rep(i,26)
        freq[i]=0;
    bool ok=true;
    rep(i,n){
        if(s[i]!=s[0])
            ok=false;
        freq[s[i]-'a']++;
    }
    if(ok){
        cout<<s<<"\n";
        return;
    }
    ok=false;
    char ch='$';
    rep(i,26){
        if(freq[i]==1){
            ok=true;
            ch=i+'a';
            break;
        }
    }

    if(ok){
        sort(all(s),[&](auto p ,auto q){
            if(p==ch)
                return true;
            else 
                return p<q;
        });
        cout<<s<<'\n';
        return;
    }
    int sm=-1,next=-1;
    rep(i,26){
        if(freq[i] && sm!=-1 && next==-1){
            next=i;
        }
        if(freq[i] && sm==-1){
            sm=i;
        }
        
    }
    if(sm==-1 || next==-1){
        cout<<"Failed\n";
        return;
    }
    string res;
    int lim=n/2 + 1;
    if(freq[sm]<=lim){
        res.pb(sm+'a');
        res.pb(sm+'a');
        freq[sm]-=2;
        while(true){
            // cerr<<sm<<": "<<freq[sm]<<" "<<next<<": "<<freq[next]<<'\n';
            if(freq[next]==0){
                if(!update(next))
                    break;
            }
            if(res.back()==(sm+'a')){
                res.pb((next+'a'));
                freq[next]--;
            }
            else{
                if(freq[sm]>0){
                    res.pb((sm+'a'));
                    freq[sm]--;
                }
                else {
                    res.pb((next+'a'));
                    freq[next]--;
                }

            }
            // cout<<res<<'\n';
        }
        // assert(freq[sm]<=1);
        if(freq[sm])
            res.pb('a');

    }
    else{
        if(freq[sm]+freq[next]==n){
            res.pb(sm+'a');
            freq[sm]--;
            while(freq[next]){
                freq[next]--;
                res.pb(next+'a');
            }
            while(freq[sm]>0){
                freq[sm]--;
                res.pb(sm+'a');
            }
        }
        else{
            res.pb(sm+'a');
            res.pb(next+'a');
            freq[sm]--;
            freq[next]--;
            while(freq[sm]>0){
                freq[sm]--;
                res.pb(sm+'a');
            }
            int sec=next;
            update(next);
            res.pb(next+'a');
            freq[next]--;
            next=sec;
            while(true){
                while(freq[next]>0){
                    freq[next]--;
                    res.pb(next+'a');
                }
                if(!update(next))
                    break;
            }
        }
    }
    // assert(res.length()==n);
    cout<<res<<'\n';
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}