#include <stdio.h>
int main(void){
    double principal, rate, payment, balance, total_interest=0.0;
    int month=0, limit=360;
    printf("Enter principal monthly_rate_percent fixed_payment: ");
    if(scanf("%lf%lf%lf",&principal,&rate,&payment)!=3 || principal<=0 || rate<0 || payment<=0){puts("Invalid input.");return 1;}
    rate/=100.0; balance=principal;
    if(rate>0 && payment<=principal*rate){puts("Repayment does not exceed first month's interest; loan will not amortize.");return 0;}
    puts("Month Opening Interest Payment Closing");
    while(balance>0.005 && month<limit){
        double opening=balance, interest=opening*rate;
        balance=opening+interest; total_interest+=interest;
        double actual=payment;
        if(actual>balance) actual=balance;
        balance-=actual; ++month;
        if(balance<0.005) balance=0.0;
        printf("%5d %7.2f %8.2f %7.2f %7.2f\n",month,opening,interest,actual,balance);
    }
    if(balance<=0.005) printf("Repaid in %d months. Total interest=Rs %.2f\n",month,total_interest);
    else printf("Safety limit reached after %d months; outstanding=Rs %.2f. Review repayment plan.\n",month,balance);
    return 0;
}