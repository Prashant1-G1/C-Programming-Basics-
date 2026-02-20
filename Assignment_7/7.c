#include <stdio.h>

union  Payment
{
    int card;
    int cash;
};

int main()
{
    union Payment p1;

    p1.card=10000;

    printf("%d\n",p1.card);
    printf("%p\n",&p1.card);

    p1.cash=50000;

    printf("%d\n",p1.cash);
    printf("%p\n",&p1.cash);


    return 0;
}
