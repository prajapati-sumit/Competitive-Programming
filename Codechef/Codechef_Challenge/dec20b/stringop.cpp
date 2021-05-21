#include <bits/stdc++.h>
using namespace std;
 
//CODED BY SUMIT KUMAR PRAJAPATI
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;

#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define PI 3.1415926535897932384626
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
 
 
 
 
string s;

//BRUTE FORCE APPROACH TO CALCULATE THE 'RES' VALUE OF SUBSTRING FROM 'START' TO 'END'
int fn(int start,int end,int par){
    int res=0;
    
    if(par&1){
        int cur=0;
        for(int i=start;i<=end;i++){
            if(s[i]=='1')
                cur++;
            if(cur%2==0){
                res++;
            }
        }
    }
    else{
        int cur=0;
        for(int i=start;i<=end;i++){
            if(s[i]=='1')
                cur++;
            if(cur&1){
                res++;
            }
        }

    }
    return res;

}

void solve(){
    
    cin>>s;
    int n=s.length();
    int one[n+1];
    
    //FILLING PREFIX ARRAY 
    one[0]=0;
      repe(i,n){
       one[i]=one[i-1]+s[i-1]-'0';
    }
    
    //BASE CASE
    if(one[n]==0){
        cout<<n<<'\n';
        return;
    }
    
    
    //SET OF TRIPLETS
    set<pair<int,pair<int,int>>>C;
    int ans=0;
    int odd,eve;
    bool iseven;
    for(int i=0;i<n;i++){
        odd=0;
        eve=0;
        iseven=true;
        for(int j=i;j<n;j++){
            
            int len=j-i+1;
            int n_one=one[j+1]-one[i];
            int res;
            if(s[j]=='0'){
                if(iseven)
                    eve++;
                else odd++;
            }
            else{
                iseven^=1;
            }

            if(n_one&1)
                res=eve;
            else res=odd;

            pair<int,pair<int,int>> temp;
            temp.first=len;
            temp.second.first=res;
            temp.second.second=n_one;
            if(C.find(temp)==C.end()){
                C.insert(temp);
                ans++;
            }
                
       
        }
    }
    
    cout<<ans<<'\n';
    
} 
 
 
 int main() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
     #else
         ios_base::sync_with_stdio(false);
        cin.tie(NULL);
          cout.tie(NULL);
     #endif

    srand(time(0));	

    time0 = curtime;
    int t=1;
    cin>>t;
    while(t--)
        solve();
    
    
    return 0;
 
}
