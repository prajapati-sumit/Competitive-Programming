// AUTHOR: SUMIT PRAJAPATI
#include <bits/stdc++.h>
using namespace std;




int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}


const int nax=20;
int main(int argc,char* argv[]) {
    
    srand(atoi(argv[1]));
    int t=50;
    printf("%d\n", t);
    while(t--){
        int n=rand(1,nax);
        for(int i=1;i<=n;i++) 
        {
            int x=rand(1,nax);
            cout<<x<<" ";
        }
        cout<<'\n';

        
    }
    return 0;

}                                   