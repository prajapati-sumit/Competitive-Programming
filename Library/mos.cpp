
const int MAX=1e5+1;
struct query {
    int idx, l, r;
} Q[MX];
const int nax=(1<<20),B=400;

int n, q,k,freq[nax],a[MX], ans[MX];
int gl_ans=0;

void add_element(int x){
    gl_ans+=freq[a[x]^k];
    freq[a[x]]++;
}
void remove_element(int x){
    freq[a[x]]--;
    gl_ans-=freq[a[x]^k];     
}
void MO_S() {

    for (int L = 0, R = -1, i = 1; i <= q; i++) {
        while(R<Q[i].r)
            add_element(++R);
        while(L>Q[i].l)
            add_element(--L);
        while(R>Q[i].r)
            remove_element(R--);
        while(L<Q[i].l)
            remove_element(L++);

        ans[Q[i].idx]=gl_ans;
    }
}

 
void solve(){
  
    cin>>n>>q>>k;
    repe(i,n)
        cin>>a[i];
 
    repe(i, q){
        cin >> Q[i].l >> Q[i].r ;
        Q[i].idx = i;
    }

    sort(Q + 1, Q + q + 1, [&](auto p, auto q) {
        if (p.l / B == q.l / B)
            return p.r < q.r;
        return p.l < q.l;
    });

    MO_S();
    repe(i, q)
        cout << ans[i] << "\n";

  
 
} 