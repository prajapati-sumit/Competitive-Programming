#include <bits/stdc++.h>
#include <cmath>
using namespace std;

//any extra function you want to form


int main() {
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        //inputs
        int N,M;
        long long int K;
        long long int arr[N][M];
        cin>>N>>M>>K;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>arr[i][j];
            }
        }
        //output code
        long long int output=0;  //output storing variables
        for(int i=1;i<=N;i++){
            int zz= K*i*i, sum_r=0, sum_c=0;
            int r_r=0,r_c=0,c_r=0,c_c=0;
            
            for(int j=0;j<i;j++){
                for(int k=0;k<i;k++){
                    sum_r=sum_r+ arr[j][k];
                    sum_c=sum_c+ arr[j][k];
                }
            }
            
            while((sum_r<zz && (r_r<N-i-1 &&r_c<M-i-1)) || (sum_c<zz && (c_r<N-i-1 &&c_c<M-i-1))){
               
                if((sum_r<zz && (r_r<N-i-1 &&r_c<M-i-1)) && (sum_c<zz && (c_r<N-i-1 &&c_c<M-i-1))){
                    for(int x=r_r;x<r_r+i;x++){
                        sum_r=sum_r-arr[x][r_c]+arr[x][r_c+i];
                    } 
                    r_c++;r_r++;
                    
                    for(int y=c_c;y<c_c+i;y++){
                        sum_c=sum_c-arr[c_r][y]+arr[c_r+i][y];
                    }
                    c_r++;c_c++;
                }
                else if(sum_r<zz && (r_r<N-i-1 &&r_c<M-i-1)){
                    for(int x=r_r;x<r_r+i;x++){
                        sum_r=sum_r-arr[x][r_c]+arr[x][r_c+i];
                    } 
                    r_c++;
                }
                else if(sum_c<zz && (c_r<N-i-1 &&c_c<M-i-1)){
                    for(int y=c_c;y<c_c+i;y++){
                        sum_c=sum_c-arr[c_r][y]+arr[c_r+i][y];
                    }
                    c_r++;
                } 
            }
            //cout<<r_r<<r_c<<c_r<<c_c<<endl;
            output=output+ ((N-r_r-i+1)*(M-r_c-i+1)) + ((N-c_r-i+1)*(M-r_c-i+1)) - (N-c_r-i+1)*(M-r_c-i+1);
            
        }
        cout<<output<<endl;
    }
    return 0;
}
