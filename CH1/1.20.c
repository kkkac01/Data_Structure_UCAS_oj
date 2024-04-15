/*编写算法求一元多项式P_n(x)=a_0+a_1*x+a_2*x^2+...+a_n*x^n的值*/
#include <stdio.h>

int main()
{
    int x, n, i, a[1005] = {}, sum = 0;
    scanf("%d%d", &x, &n);
    for (i = 0; i <= n; i++)
        scanf("%d", a + i);
    for (i = n; i >= 0; i--)
        sum = sum * x + a[i];
    printf("%d\n", sum);
    return 0;
}