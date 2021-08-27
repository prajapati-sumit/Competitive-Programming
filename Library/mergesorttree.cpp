const int MX=1e5+5;

 

int n;
int a[MX];
vector<int> segm[4*MX];
void merge(vector<int>& A,vector<int>& B,vector<int>& to){
    int szA=A.size(),szB=B.size(),i=0,j=0;
    while(i<szA && j<szB)
        (A[i]<B[j])?to.pb(A[i++]):to.pb(B[j++]);
    while(i<szA)
        to.pb(A[i++]);
    while(j<szB)
        to.pb(B[j++]);

}
void buildtree(int cur,int start,int end){
    if(start==end){
       //BASE CASE
        segm[cur].pb(a[start]);
        return;
    }
    int mid=(start+end)>>1;
    buildtree(cur<<1,start,mid);
    buildtree((cur<<1)+1,mid+1,end);
    merge(segm[2*cur],segm[2*cur+1],segm[cur]);
    //MERGING STEP


}
int query(int cur,int start,int end,int qs,int qe,int val){
    if(start>=qs && end<=qe){
        int res=upper_bound(all(segm[cur]),val)-segm[cur].begin();
        res=max(0LL,(int)segm[cur].size()-res);
        return res;
    }
    if(start>qe || end<qs)
        return 0;          //INVALID RETURN 
    int mid=(start+end)>>1;
    int A=query(2*cur,start,mid,qs,qe,val);
    int B=query(2*cur+1,mid+1,end,qs,qe,val);
    //MERGING STEP
    int res= A+B; 

    return res;
}
