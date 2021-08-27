const int MX=1e5+2;

int phi[MX];

 
void calc_phi(){
    repe(i,MX-1)
        phi[i]=i;
    for(int i=2;i<MX;i++){
        if(phi[i]==i){
            for(int j=i;j<MX;j+=i)
                phi[j]-=phi[j]/i;
        }
    }
} 