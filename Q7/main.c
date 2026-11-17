#include <stdio.h>
unsigned long long divisions;
int original_prime(unsigned long n){
    divisions=0;if(n<2)return 0;
    for(unsigned long i=2;i*i<=n;++i){++divisions;if(n%i==0)return 0;}
    return 1;
}
/* Redesign: handle 2, reject even values, then test odd divisors only. */
int redesigned_prime(unsigned long n){
    divisions=0;if(n<2)return 0;if(n==2)return 1;if(n%2==0){++divisions;return 0;}
    for(unsigned long i=3;i<=n/i;i+=2){++divisions;if(n%i==0)return 0;}
    return 1;
}
int main(void){
    unsigned long values[]={97,100,7919,1000003,999983};
    puts("n original_result original_divisions redesigned_result redesigned_divisions");
    for(int k=0;k<5;++k){
        int a=original_prime(values[k]);unsigned long long ca=divisions;
        int b=redesigned_prime(values[k]);unsigned long long cb=divisions;
        printf("%lu %s %llu %s %llu\n",values[k],a?"prime":"not-prime",ca,b?"prime":"not-prime",cb);
    }
    return 0;
}