

const int  N = 100005;

int lpf[N];
int mobius[N];


void least_prime_factor() {
    for (int i = 2; i < N; i++)
        if (!lpf[i])
            for (int j = i; j < N; j += i)
                if (!lpf[j])
                    lpf[j] = i;
}
void Mobius() {

    mobius[1] = 1;
    for (int i = 2; i < N; i++) {
        if (lpf[i / lpf[i]] == lpf[i])
            mobius[i] = 0;
        else
            mobius[i] = -1 * mobius[i / lpf[i]];
    }
}

void init_Mobius(){
    least_prime_factor();
    Mobius();
}