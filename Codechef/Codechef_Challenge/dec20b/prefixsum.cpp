#include <bits/stdc++.h>
using namespace std;

//CODED BY SUMIT KUMAR PRAJAPATI
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;

#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define PI 3.1415926535897932384626
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repe(i, n) for (ll i = 1; i <= n; i++)
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define curtime chrono::high_resolution_clock::now()
#define timedif(start, end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()
const int MX = 1e5 + 5;
const int MD = 1e9 + 7;
const int MDL = 99824453;
auto time0 = curtime;


int n,k;
int a[MX];

int fn(int n){

    int pref=0;
    int cnt=0;
    repe(i,n)
    {
        pref+=a[i];
        if(pref>0)
            cnt++;
    }
    return cnt;
}

void solve(){
    cin>>n>>k;
    a[0]=-1;
    repe(i,n){
        if(a[i-1]<0)
            a[i]=i;
        else a[i]=-i;
    }
        
    
    int cur=n/2;
    if(n&1)
        cur++;
    if(cur>k){
        int ind=n;
        while(cur!=k){
            
            if(a[ind]>0){
                a[ind]*=-1;
                cur--;
            }
            ind--;
        }
    }
    else if(cur<k){
        int ind=n;
        while(cur!=k){
            
            if(a[ind]<0){
                a[ind]*=-1;
                cur++;
            }
            ind--;
        }
    }
   
    repe(i,n)
        cout<<a[i]<<" ";
    cout<<'\n';
}



int main()
{

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
    ll t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
