#include<cmath>
#include<iostream>

/*
Finds n, the minimum number of digits x needs to have in order
for the following equality to be true: 10^(n - 1) % 19 == 2.
Will explain why this works in README.md.
*/
int findMinN(){
    int n = 2;
    int rem = 10;

    while(rem != 2){
        n++;
        rem = (rem * 10) % 19;
    }

    return n;
}

long long findX(int n){
    long long result = 0;

    return result;
}

int main(){
    int n = findMinN();
    long long x = findX(n);

    std::cout << x << std::endl;

    return 0;
}