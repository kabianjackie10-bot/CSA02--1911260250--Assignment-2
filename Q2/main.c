#include <stdio.h>
static unsigned long calls;
int verify_card(int passenger) { (void)passenger; ++calls; return passenger % 10 == 0; }
int senior(int p) { return p % 2 == 0; }
int eligible(int p) { return p % 3 == 0; }
int main(void) {
    unsigned long calls_a=0, calls_b=0, calls_bit=0;
    int granted=0;
    for (int p=0; p<1000; ++p) {
        calls=0;
        int a = (senior(p) && eligible(p)) || verify_card(p);
        calls_a += calls; granted += a;
        calls=0;
        int b = verify_card(p) || (senior(p) && eligible(p));
        calls_b += calls;
        calls=0;
        /* Bitwise operators evaluate both operands; use boolean-valued operands. */
        int c = (senior(p) & eligible(p)) | verify_card(p);
        calls_bit += calls;
        (void)b; (void)c;
    }
    printf("Passengers=1000\nOrder A (senior && eligible) || verify: %lu calls\n", calls_a);
    printf("Order B verify || (senior && eligible): %lu calls\n", calls_b);
    printf("Bitwise & and | version: %lu calls\n", calls_bit);
    printf("Concessions in order A: %d\n", granted);
    return 0;
}