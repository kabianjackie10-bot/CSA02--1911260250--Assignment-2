#include <stdio.h>
unsigned long checks;
int prime_sqrt_for(unsigned long n){
    checks=0; if(n<2) return 0;
    for(unsigned long i=2;i*i<=n;++i){ ++checks; if(n%i==0) return 0; }
    return 1;
}
int prime_all_for(unsigned long n){
    checks=0; if(n<2)return 0;
    for(unsigned long i=2;i<n;++i){++checks;if(n%i==0)return 0;}
    return 1;
}
int prime_sqrt_while(unsigned long n){
    checks=0;if(n<2)return 0; unsigned long i=2;
    while(i*i<=n){++checks;if(n%i==0)return 0;++i;} return 1;
}
int prime_sqrt_do(unsigned long n){
    checks=0;if(n<2)return 0; unsigned long i=2;
    do { if(i*i>n) break; ++checks; if(n%i==0)return 0; ++i; } while(1);
    return 1;
}
int main(void){
    unsigned long a[]={97,100,7919,1000003};
    for(int k=0;k<4;++k){int p=prime_sqrt_for(a[k]);printf("%8lu %-9s divisions = %lu\n",a[k],p?"prime":"not prime",checks);}
    puts("All-divisor loop (same inputs):");
    for(int k=0;k<4;++k){int p=prime_all_for(a[k]);printf("%8lu %-9s divisions = %lu\n",a[k],p?"prime":"not prime",checks);}
    puts("while and do-while versions agree:");
    for(int k=0;k<4;++k){int p=prime_sqrt_while(a[k]);unsigned long w=checks;int q=prime_sqrt_do(a[k]);printf("%lu: while=%lu do-while=%lu result=%s\n",a[k],w,checks,p==q?"same":"DIFFERENT");}
    return 0;
}