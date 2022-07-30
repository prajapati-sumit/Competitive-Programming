#include <stdio.h>
#include <stdlib.h>
int* substract(int* arr1,int* arr2,int len){
    int one=1;
    int zero=0;
    int* x;
    x=(int*)malloc(sizeof(int)*(len));
    int i=zero;
    while(i<len){
        x[i]=arr1[i] - arr2[i];
        i=i+one;
    }
    return x;
}
int* shift(int* p,int len,int n){
    int one =1;
    int zero=0;
    int* x;
    x=(int*)malloc(sizeof(int)*(len+n));
    int i=zero;
    while(i<n){
        x[i]=zero;
        i=i+one;
    }
    int it=0;
    while(it<len){
        x[it+n]=p[it];
        it=it+one;
    }
    return x;
}
int *add(int *p1, int *p2, int n1, int len)
{
    int one=1;
    int zero=0;
    int *t;
    int  c;
    t = (int*)malloc(sizeof(int)*(len));
    int it=zero;
    while(it<n1){
        c = p1[it] + p2[it];
        t[it]=c;
        it=it+one;
    }
    while(it<len){
        c = p2[it];
        t[it] = c;
    it=it+one;
    }
    return t;
}
int* multiplication(int* arr1, int* arr2,int len){
    int *a;
    int one=1;
    int zero=0;
    int two=2;

    if(len<2){
        a=(int *)malloc(sizeof(int));
        a[zero]= arr1[zero]*arr2[zero];


    }
    else{
        if(len%two==zero){
            int break_point=len/two;

            int* a0;
            int* a1;
            int* b0;
            int* b1;
            a0=(int*)malloc(sizeof(int)*break_point);
            a1=(int*)malloc(sizeof(int)*break_point);
            b0=(int*)malloc(sizeof(int)*break_point);
            b1=(int*)malloc(sizeof(int)*break_point);
int i=0;
           while(i<break_point){

               a0[i]=arr1[i];
               i=i + one;
           }
            int ic=zero;
            while(ic<break_point){
                a1[ic]=arr1[break_point+ic];
                ic=ic+one;
            }
            int it=zero;
            while( it<break_point){
                b0[it]=arr2[it];
                it=it+one;
            }

            int ip=zero;
            while(ip<break_point){
                b1[ip]=arr2[break_point+ip];
                ip=ip+one;
            }

            int * c0;
            int* c1;
            int* c2;
            int* c2t;
          
            c0=multiplication(b0,a0,break_point);
            c1= multiplication(add(a0,a1,break_point,break_point),add(b0,b1,break_point,break_point),break_point);
            c2=multiplication(a1,b1,break_point);
            a=add(c0,shift(c2,two*break_point-one,len),two*break_point-one,two*len-one);
              c2t= substract(c1,c0,two*break_point-one);
            c2t= substract(c2t,c2,two*break_point-one);
int three=3;
            a=add(shift(c2t,two*break_point-one,break_point),a,three*break_point-one,two*len-one);
        }
        else if (len%two==one){
            int * y;
            int* z;
            z=(int *)malloc(sizeof(int)*(len+1));
            y=(int *)malloc(sizeof(int)*(len+1));

            int kp=0;
            while(kp<=len){
                y[kp]=arr1[kp];
                kp=kp+one;
            }
            y[len]=zero;
            int k=zero;
            while(k<=len){
                z[k]=arr2[k];
                k=k+one;
            }
            z[len]=zero;
            a=multiplication(z,y,len+one);
        }
    }
    return a;
}



int main(){
    int zero=0,one =1, two=2;
    int Max_power, i=zero,t=zero,x=zero;
    scanf("%d", &Max_power);
    if((Max_power+1)%two==0){
        int p1[Max_power+one], p2[Max_power+one];
        /*for(i=0; i<=Max_power; i++)
            scanf("%d", &p1[i]);*/
        while(i<=Max_power){
            scanf("%d", &p1[i]);
            i=i+one;
        }
        //for(i=0; i<=Max_power; i++)
            //scanf("%d", &p2[i]);
        while( t<=Max_power){
            scanf("%d", &p2[t]);
            t=t+one;
        }

        int * final_ans = multiplication(p1, p2, Max_power+one);
        int jt=zero;
        while(jt<two*Max_power+one){
            printf("%d ",final_ans[jt]);
            jt=jt+one;
        }
    }
    else{
        int p1[Max_power+two], p2[Max_power+two];
        while(i<=Max_power){
            scanf("%d", &p1[i]);
            i=i+one;}
        p1[Max_power+one]=zero;
            int tp=0;
         while(tp<=Max_power){
            scanf("%d", &p2[tp]);
            tp=tp+one;}
        p2[Max_power+one]=zero;
        int * final_ans = multiplication(p2, p1, Max_power+two);
        int tpx=zero;
        while(tpx<2*Max_power +one ){
            printf("%d ",final_ans[tpx]);
            tpx=tpx+one;
        }
    }
    return 0;
}