// generating a tree in a not-so-stupid way
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int t=5;
    printf("%d\n", t);
    while(t--){
        int n = rand(1, 20);
        int q=rand(1,n);
        printf("%d %d\n",n,q);
        
    }
}