// credits:cp-algorithms.com
const int MX=1e5+5;

int pi[MX];

void calc_pi(const string& s){
    int n=s.length();
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j])
            j=pi[j-1];
        if(s[i]==s[j])
            j++;
        pi[i]=j;
    }
}
