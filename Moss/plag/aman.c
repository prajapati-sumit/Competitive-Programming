//
// Created by aman on 20-02-2022.
//
#include <stdio.h>
#include <stdlib.h>

#define loop(a, n) for(i=a; i<n; i++)

int* create(int size)
{
    int *t;
    t = (int *)malloc(size * sizeof(int));
    return t;
}

int *sum(int *p1, int *p2, int n1, int n2)
{
    int *t;
    int i;
    t = create(n2);
    loop(0, n1)
        t[i] = p1[i] + p2[i];
    loop(i, n2)
        t[i] = p2[i];
    return t;
}

int* shift(int* arr,int len,int n){
    int* r;
    int i;
    r = create(len+n);

    loop(0, n)
        r[i] = 0;

    loop(0, len)
        r[i+n] = arr[i];
    return r;
}

int* sub(int *p1,int *p2,int len){
    int *q;
    int i;
    q = create(len);
    loop(0, len)
        q[i] = p1[i] - p2[i];
    return q;
}

int* mult(int* p1, int* p2, int len){
    int *res;
    int i;
    if(len<2){
        res = create(1);
        res[0] = p1[0] * p2[0];
        return res;
    }
    if(len%2==0){
        int l1 = len/2;

        int *a0, *a1, *b0, *b1;
        a0 = create(l1);
        a1 = create(l1);
        b0 = create(l1);
        b1 = create(l1);

        loop(0, l1){
            a0[i] = p1[i];
            b0[i] = p2[i];
        }
        loop(0, l1){
            a1[i] = p1[l1+i];
            b1[i] = p2[l1+i];
        }

        int *y, *x, *z;
        int *w;

        y = mult(a0,b0,l1);
        x = mult(sum(a0,a1,l1,l1),sum(b0,b1,l1,l1),l1);
        z = mult(a1,b1,l1);

        res=sum(y,shift(z,2*l1-1,len),2*l1-1,2*len-1);
        w = sub(x,y,2*l1-1);
        w = sub(w,z,2*l1-1);

        res=sum(shift(w,2*l1-1,l1),res,3*l1-1,2*len-1);
    }
    else{
        int *y;
        int *z;
        y = create(len+1);
        z = create(len+1);

        loop(0, len){
            y[i] = p1[i];
            z[i] = p2[i];
        }
        y[len]=0;
        z[len] = 0;
        res = mult(y,z,len+1);
    }
    return res;
}

int main(){
    int power, i;
    scanf("%d", &power);


    if((power+1)%2==0){
        int poly1[power+1], poly2[power+1];
        loop(0, power+1)
            scanf("%d", &poly1[i]);
        loop(0, power+1)
            scanf("%d", &poly2[i]);

        int * prod = mult(poly1, poly2, power+1);

        loop(0, 2*power+1)
            printf("%d ",prod[i]);
    }
    else{
        int poly1[power+2], poly2[power+2];
        loop(0, power+1)
            scanf("%d", &poly1[i]);
        poly1[power+1]=0;
        loop(0, power+1)
            scanf("%d", &poly2[i]);
        poly2[power+1]=0;
        int * prod = mult(poly1, poly2, power+2);

        loop(0, 2*power+1)
            printf("%d ",prod[i]);
    }
}
