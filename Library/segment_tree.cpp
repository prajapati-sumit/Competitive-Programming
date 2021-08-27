int segm[4*MX];

void merge(int &A,int &B,int &res){
    res=A+B;
}
void buildtree(int cur,int start,int end){
    if(start==end){
       //BASE CASE

        return;
    }
    int mid=(start+end)>>1;
    buildtree(cur<<1,start,mid);
    buildtree((cur<<1)+1,mid+1,end);
    //MERGING STEP
    merge(segm[2*cur],segm[2*cur+1],segm[cur]);

}
int query(int cur,int start,int end,int qs,int qe){
    if(start>=qs && end<=qe)
        return segm[cur];
    if(start>qe || end<qs)
        return ;          //INVALID RETURN 
    int mid=(start+end)>>1;
    int A=query(2*cur,start,mid,qs,qe);
    int B=query(2*cur+1,mid+1,end,qs,qe);
    //MERGING STEP
    int res;
    merge(A,B,res);  

    return res;
}
void update(int cur,int start,int end,int ind,int val){
    if(start==ind && start==end){
        //DO UPDATE

        return;
    }
    if(start>ind|| end<ind)
        return;          //OUT OF RANGE 
    int mid=(start+end)>>1;
    update(cur<<1,start,mid,ind,val);
    update((cur<<1)^1,mid+1,end,ind,val);
    //MERGING STEP
    merge(segm[2*cur],segm[2*cur+1],segm[cur]);

}
 
