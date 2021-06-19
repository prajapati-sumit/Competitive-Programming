// AUTHOR: SUMIT PRAJAPATI
#include <bits/stdc++.h>
using namespace std;




int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}


const int nax=10;
int main(int argc,char* argv[]) {
    
    srand(atoi(argv[1]));
    int t=2;
    printf("%d\n", t);
    while(t--){
        int n=rand(1,nax);
        int k=rand(1,nax);
        printf("%d %d\n", n,k);
        for(int i=0;i<n-1;i++)
            printf("%d", rand(0,1));
        printf("%d\n");
        for(int i=0;i<k;i++)
            printf("%d ", rand(1,n));
        printf("\n") ;           

    }
    return 0;

}                                   