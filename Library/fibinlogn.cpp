pll fib(ll n){
    if(n==0){
        return {0,1};
    }
    pll cur=fib(n>>1);
    ll nth=(cur.F*((2*cur.S+MD-cur.F)%MD))%MD;
    ll nth1=((cur.F*cur.F)%MD+(cur.S*cur.S)%MD)%MD;
    if(n&1)
        return {nth1,(nth+nth1)%MD};
    return {nth,nth1};
} 