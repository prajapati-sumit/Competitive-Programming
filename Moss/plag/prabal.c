//
// Created by Prabal on 20-02-2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int* add(int* arr1,int* arr2,int len){
//    int* p;
//    p=(int*)malloc(sizeof(int)*(len));
//    for(int i=0;i<len;i++){
//        if(arr1[i]){
//            p[i]=arr1[i] + arr2[i];
//        }
//        else{
//            p[i]=arr2[i];
//        }
//
//    }
//    return p;
//}

int *add(int *p1, int *p2, int n1, int len)
{
    int *t;
    int i, c;
    t = (int*)malloc(sizeof(int)*(len));
    for(i=0;i<n1;i++){
        c = p1[i] + p2[i];
        t[i] = p1[i] + p2[i];
    }
    for(i;i<len;i++){
        c = p2[i];
        t[i] = p2[i];
    }
    return t;
}

int* substract(int* arr1,int* arr2,int len){
    int* q;
    q=(int*)malloc(sizeof(int)*(len));
    for(int i=0;i<len;i++){
        q[i]=arr1[i] - arr2[i];
    }
    return q;
}

int* shift(int* arr,int len,int n){
    int* r;
    r=(int*)malloc(sizeof(int)*(len+n));

    for(int i=0;i<n;i++){
        r[i]=0;
    }

    for(int i=0;i<len;i++){
        r[i+n]=arr[i];
    }
    return r;

}

int* multiply(int* arr1, int* arr2,int len){
    int *a;

    if(len<2){
        a=(int *)malloc(sizeof(int)*1);
        a[0]= arr1[0]*arr2[0];


    }
    else{
        if(len%2==0){
            int mid=len/2;

            int* a0;
            int* a1;
            int* b0;
            int* b1;
            a0=(int*)malloc(sizeof(int)*mid);
            a1=(int*)malloc(sizeof(int)*mid);
            b0=(int*)malloc(sizeof(int)*mid);
            b1=(int*)malloc(sizeof(int)*mid);

//            adding values in a0
            for(int i=0;i<mid;i++){
                a0[i]=arr1[i];
            }
//             adding values in a1
            for(int i=0;i<mid;i++){
                a1[i]=arr1[mid+i];
            }
//            adding values in b0
            for(int i=0;i<mid;i++){
                b0[i]=arr2[i];
            }
//             adding values in b1
            for(int i=0;i<mid;i++){
                b1[i]=arr2[mid+i];
            }

//            declaring pointers for c0 ,c1 and c2....

            int * c0;
            int* c1;
            int* c2;
            int* c2_;
//            c0=(int*)malloc(sizeof(int)*mid+1);
//            c1=(int*)malloc(sizeof(int)*mid+1);
//            c2=(int*)malloc(sizeof(int)*mid+1);

            c0=multiply(a0,b0,mid);
            c1= multiply(add(a0,a1,mid,mid),add(b0,b1,mid,mid),mid);
            c2=multiply(a1,b1,mid);

            a=add(c0,shift(c2,2*mid-1,len),2*mid-1,2*len-1);
            c2_= substract(c1,c0,2*mid-1);
            c2_= substract(c2_,c2,2*mid-1);

            a=add(shift(c2_,2*mid-1,mid),a,3*mid-1,2*len-1);
        }
        else{
            int * y;
            int* z;
            y=(int *)malloc(sizeof(int)*(len+1));
            z=(int *)malloc(sizeof(int)*(len+1));

            for(int k=0;k<len;k++){
                y[k]=arr1[k];
            }
            y[len]=0;
            for(int k=0;k<len;k++){
                z[k]=arr2[k];
            }
            z[len]=0;
            a=multiply(y,z,len+1);
        }
    }
    return a;
}

int main(){
    int power, i;
    scanf("%d", &power);


    if((power+1)%2==0){
        int poly1[power+1], poly2[power+1];
        for(i=0; i<=power; i++)
            scanf("%d", &poly1[i]);
        for(i=0; i<=power; i++)
            scanf("%d", &poly2[i]);

        int * prod = multiply(poly1, poly2, power+1);

        for(int j=0;j<2*power+1;j++){
            printf("%d ",prod[j]);
        }
    }
    else{
        int poly1[power+2], poly2[power+2];
        for(i=0; i<=power; i++)
            scanf("%d", &poly1[i]);
        poly1[power+1]=0;
        for(i=0; i<=power; i++)
            scanf("%d", &poly2[i]);
        poly2[power+1]=0;
        int * prod = multiply(poly1, poly2, power+2);

        for(int j=0;j<2*power+1;j++){
            printf("%d ",prod[j]);
        }
    }


    return 0;

//    int arr1[]={5,1,6,0};
//    int arr2[]={1,2,0,0};
//
//    int len=4;
//    int * q;
//    q=(int*)malloc(sizeof(int)*(len+1));
//
//    q= multiply(arr1,arr2,len);
////    q=substract(arr2,arr1,4);
//    for(int j=0;j<2*len-3;j++){
//        printf("%d ",q[j]);
//    }
}
