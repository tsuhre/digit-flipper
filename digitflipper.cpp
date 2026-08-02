#include<cmath>
#include<iostream>

/*
Finds n, the minimum number of digits x needs to have in order
for the following equality to be true: 10^(n - 1) % 19 == 2.
See README.md to see how this equality was found.
*/
int findMinN(){
    int n = 1;
    int rem = 1;

    while(rem != 2){
        n++;
        rem = (rem * 10) % 19;
    }

    return n;
}

/*
Finds x, the lowest number where moving its last digit to the
front of the number results in 2x.
*/
long long findX(int n){
    long long result = 0;
    long long power = 1;
    for(int i = 0; i < n - 1; i++){
        power *= 10;
    }

    long long numerator;
    long long p;
    long long pcopy;
    int pdigits;

    for(int d = 1; d < 10; d++){
        numerator = d * (power - 2);
        p = numerator / 19;
        pcopy = p;
        pdigits = 0;

        while(pcopy > 0){
            pcopy /= 10;
            pdigits++;
        }

        if(pdigits == n - 1){
            result = p * 10 + d;
            break;
        }
    }

    return result;
}

int main(){
    int n = findMinN();
    std::cout << "Minimum digits of x: " << n << std::endl;

    long long x = findX(n);
    std::cout << " x =  " << x << std::endl;
    std::cout << "2x = " << 2 * x << std::endl;

    return 0;
}