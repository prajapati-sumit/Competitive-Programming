#include<bits/stdc++.h>
using namespace std;


vector<int>G[1001];
int parent[1001];
bool bonus[1001];
int n, p;
void solve() {

    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        parent[i] = x;
    }
    for (int i = 1; i <= p; i++) {
        int x;
        cin >> x;
        // cerr << x << ": ";
        while (parent[x] > 0 && !bonus[parent[x]])
            x = parent[x];
        // cerr << x << "\n";
        bonus[x] = true;
    }
    for (int i = 1; i <= n; i++)
        if (!bonus[i])
            cout << i << " ";


}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    solve();

    return 0;

}