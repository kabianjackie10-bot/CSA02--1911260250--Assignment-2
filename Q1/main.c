#include <stdio.h>
int main(void) {
    int price, qty, senior;
    printf("Enter unit price, quantity and senior (1=yes, 0=no): ");
    if (scanf("%d%d%d", &price, &qty, &senior) != 3) return 1;
    int gross = price * qty;
    /* Assumption: GST is calculated after the senior discount. */
    int discount = gross * 15 / 100 * senior;
    int taxable = gross - discount;
    int tax = taxable * 5 / 100;
    int total = taxable + tax;
    int net = total > 1000 ? total - 50 : total;
    printf("gross=%d discount=%d tax=%d total=%d net=%d\n", gross, discount, tax, total, net);
    return 0;
}