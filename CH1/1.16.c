/*写一个算法，自大到小依次输出顺序读入的三个整数，x，y和z的值*/
#include <stdio.h>

void swap(long long *x, long long *y)
{
    long long temp;
    temp = *x;
    *x = *y;
    *y = temp;
    return;
}

int main()
{
    long long a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    if (a < b)
        swap(&a, &b);
    if (b < c)
        swap(&b, &c);
    if (a < b)
        swap(&a, &b);
    printf("%lld %lld %lld\n", a, b, c);
    return 0;
}