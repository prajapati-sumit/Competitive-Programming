// AUTHOR: SUMIT PRAJAPATI
#include <bits/stdc++.h>
using namespace std;




int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}


const int nax=1e9;
int main(int argc,char* argv[]) {
    
    srand(atoi(argv[1]));
    int t=1000;
    printf("%d\n", t);
    while(t--){
        int n=rand(1,nax);
        int n2=rand(1,nax);
        printf("%d %d\n", n,n2);
        
    }
    return 0;

}                                   