#include <bits/stdc++.h>

using namespace std;
#define ll long long

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER x1
 *  2. INTEGER y1
 *  3. INTEGER x2
 *  4. INTEGER y2
 */
ll  gcd(ll  a, ll  b, ll & x, ll & y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll  x1, y1;
    ll  d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(ll  a, ll  b, ll  c, ll  &x0, ll  &y0, ll  &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
ll  solve(ll  x1, ll  y1, ll  x2, ll  y2) {
    // (x2-x1)*(y-y1)-(y2-y1)*(x-x1)=0
    // -(x2-x1)*y+(y2-y1)*x=-y1*(x2-x1)+x1*(y2-y1)
    ll  a=(y2-y1);
    ll  b=-(x2-x1);
    ll  c=-y1*(x2-x1)+x1*(y2-y1);
    cout<<a<<" "<<b<<" "<<c<<'\n';
    if(a==0 && b==0)
        return 0;
    ll  x=0,y=0,g=1;
    // find_any_solution(a,b,c,x,y,g);
    // x1=x+k1*b/g
    ll k1,k2;
    if(b==0){
        k1=y1;
        k2=y2;
    }
    else if(a==0){
        k1=x1;
        k2=x2;
    }
    else{
        k1=((x1-x)*g)/b;
        k2=((x2-x)*g)/b;
    }
  
    // cerr<<k1<<" "<<k2<<'\n';
    // // x2=x+k2*b/g
    // cerr<<x<<" "<<y<<" "<<g<<" \n";
    return abs(k2-k1)-1;
    
}

int main()
{
    
    ll  t;
    cin>>t;
    for (ll  t_itr = 0; t_itr < t; t_itr++) {
        ll  x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        ll  result = solve(x1, y1, x2, y2);

        cout << result << "\n";
    }


    return 0;
}

