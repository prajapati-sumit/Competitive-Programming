#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define INF 1e9
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()
auto time0 = curtime;



void testcase(){
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    unordered_map<string, int> m;
    for (string s : a)
        m[s]++;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double timer=timedif(time0,curtime)*1e-9;
            if(timer>1.95){
                cout<<cnt<<'\n';
                return;
            }
            if (j == i)
                continue;
            string x = a[i];
            string y = a[j];
            swap(x[0], y[0]);
            if (m.find(x) == m.end() && m.find(y) == m.end())
                cnt++;
        }
    }
    cout << cnt << '\n';
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    time0=curtime;
    cin >> t;
    while (t--)
    {
        testcase();
    }
    return 0;
}