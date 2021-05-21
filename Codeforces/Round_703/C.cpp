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
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()

const int INF=1e9;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
 
 
 
int n,qcnt;

int query(int l,int r){
    assert(qcnt<=20);
    qcnt++;
    cout<<"? "<<l<<" "<<r<<'\n';
    int x;
    cin>>x;
    return x;
} 
void solve(){
  
    cin>>n;
    int ind=query(1,n),l=1,r=n,mid,next;
    if(ind==1)
        l=ind+1;
    else if(ind==n)
        r=ind-1;
    else{
        next=query(ind,n);
        if(next==ind){
            l=ind+1;
        }
        else
            r=ind-1;
    }
    while(l<=r){
        cout<<"L,R: "<<l<<" "<<r<<'\n';

        if(r-l==1){
            next=query(l,r);
            if(next==l)
                cout<<"! "<<r<<'\n';
            else
                cout<<"! "<<l<<'\n';
            break;
        }
        if(l==r){
            cout<<"! "<<r<<'\n';
            break;
        }
        mid=(l+r)>>1;
        if(mid<ind){
            next=query(mid,ind);
            if(next==ind){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        else{
            next=query(ind,mid);
            if(next==ind){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
         
        
    }
    
    
} 
//1 2 3 4 5 6 7  8 9 10
//8 6 2 3 7 5 10 9 1 4 
 
int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    srand(time(0)); 
    time0 = curtime;

    solve();
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}