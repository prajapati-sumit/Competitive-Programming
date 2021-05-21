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
 
 
 
 
int n;
int a[MX]; 


ll brute(){

    int temp[n+1];
    repe(i,n)
        temp[i]=a[i];
    ll cost=0;
    repe(i,n-1){
        int mn=i;
        FOR(j,i,n){
            if(temp[mn]>temp[j])
                mn=j;
        }
        cost+=(mn-i+1);
        FOR(k,i,i+((mn-i)/2)){
            swap(temp[k],temp[mn-k+i]);
        }
    } 
    return cost;  
  
}
vector<int> helper(int c){
    vector<int>res;
    // cout<<c<<" "<<n<<" -\n";
    for(int i=n-1;i>=1;i--){
        if(c>=i){
            c-=i;
            res.pb(i);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

void shift(int &where,int who){

    for(int i=where;i<who;i++)
        swap(a[i],a[who]);
    if(a[where]%2==0)
        where++;
}
void solve(){
    int c;
    cin>>n>>c;
    // n=2+rand()%99;

    int lowest=(n-1),highest=(n*n+n-2)/2;
    // c=(n-1)+rand()%(highest-lowest);
    if(c<lowest || c>highest){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    c-=(n-1);
    repe(i,n)
        a[i]=i;

    if(c==0){
        repe(i,n)
            cout<<a[i]<<" ";
        // cout<<":-> "<<(c+n-1)<<" "<<brute();
        cout<<'\n';

        return;
    }
    int cur_start=1;
    vector<int>v=helper(c);
    // cout<<v.size()<<'\n';
    trav(v){
        shift(cur_start,el+1);
    }
    repe(i,n)
        cout<<a[i]<<" ";
     // cout<<":-> "<<(c+n-1)<<" "<<brute();
    cout<<'\n';
}

void solve2(){
  
    cin>>n;
    repe(i,n)
        a[i]=i;

    map<int,vector<vector<int>> >mp;
    map<int,vector<vector<int>> >mp2;
    int mn=INF,mx=-1;
    do{
        int cost=brute();
        
        // repe(i,n)
        //     cout<<a[i]<<" ";
        // cout<<"-> "<<cost;
        // cout<<'\n';
        vector<int> temp;
        repe(i,n)
            temp.pb(a[i]);
        mp[cost].pb(temp);
        mn=min(mn,cost);
        mx=max(mx,cost);

    } while (next_permutation(a+1, a + n+1));
    cout<<n<<": "<<mn<<" "<<mx<<'\n';
    // int pred=(n*n-n+2)/2;
    // cout<<st.size()<<" "<<pred<<'\n';

    // int lowest=n-1,highest=(n*n-n+2)/2;
    // if(c>=lowest && c<=highest)
    // for(auto el:mp){
    //     cout<<el.ff<<"-> ";
    //     for(auto x:el.ss){
            
    //             cout<<"{ ";
    //             for(auto y:x)
    //                 cout<<y<<" ";
    //             cout<<"} ";
             

    //     }
    //     cout<<el.ss.size();
    //     cout<<'\n';
    // }
    // cout<<'\n';
    
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    cin>>t;
    repe(tt,t){
        cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}