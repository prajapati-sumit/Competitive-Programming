typedef complex<double> Complex;

class FastFourierTransform{
    const double PI;

    FastFourierTransform(){
        PI=acos(-1.0);
    }
    void display(Complex C){
        char ch;
        if(C.imag()<0)
            ch='-';
        else
            ch='+';
        cout<<C.real()<<ch<<C.imag()<<"i "; 
    }
    int rev(int x,int sz){
        int res=0;
        rep(i,sz){
            res<<=1;
            res=res|(x&1!=0);
            x>>=1;
        }
       

        return res;
    }

    void FFT(vector<Complex>& a,bool invert){
        int sz=0;
        int n=a.size();
        while((1<<sz)<n)
            sz++;
        a.resize((1<<sz));
        n=(1<<sz);
        rep(i,n){
            int r=rev(i,sz);
            if(i<r)
                swap(a[i],a[r]);
        }
        Complex wlen;
        double arg;
        for(int len=2;len<=n;len<<=1){
            arg=2*PI/len* ( invert ? -1 : 1);
            wlen=polar(1.0,arg);
            for (int i = 0; i < n; i += len) {
                Complex w(1);
                for (int j = 0; j < len / 2; j++) {
                    Complex u = a[i+j], v = a[i+j+len/2] * w;
                    a[i+j] = u + v;
                    a[i+j+len/2] = u - v;
                    w *= wlen;
                }
            }
        }

        if(invert){
            for(auto &x:a)
                x/=n;
        }
    } 
    vector<int> multiply(vector<int> const& a, vector<int> const& b) {
        vector<Complex> fa(a.begin(), a.end()), fb(b.begin(), b.end());
        int n = 1;
        while (n < a.size() + b.size()) 
            n <<= 1;
        fa.resize(n);
        fb.resize(n);

        FFT(fa, false);
        FFT(fb, false);
        for (int i = 0; i < n; i++)
            fa[i] *= fb[i];
        FFT(fa, true);

        vector<int> result(n);
        for (int i = 0; i < n; i++)
            result[i] = round(fa[i].real());
        return result;
    } 
};
