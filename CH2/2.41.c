/*试以循环链表作稀疏多项式的存储结构，编写求其导函数的算法，要求利用原多项式中的节点空间存放其导函数（多项式），同时释放所有无用（被删）节点。
输出为求导之后的结果，按照多项式中每一项的幂次由高到低排列
如果导数为0，则输出0*/
#include <stdio.h>
#include <stdlib.h>
typedef struct PolyTerm
{
    int coef; // 系数
    int exp;  // 指数
} PolyTerm;

typedef struct PolyNode
{
    PolyTerm data;
    struct PolyNode *next;
} PolyNode, *PolyLink;

typedef PolyLink LinkedPoly;

LinkedPoly lalloc()
{
    return (LinkedPoly)malloc(sizeof(PolyNode));
}

LinkedPoly input()
{
    char c = getchar();
    int sign = 1, coef = 0, exp = 0;
    if (c == EOF)
        return NULL;
    PolyNode *p = lalloc();
    if (c == '-')
    {
        sign = -1;
        c = getchar(); // 读符号后面的空格
        c = getchar(); // 读系数
    }
    else if (c == '+')
    {
        c = getchar(); // 读符号后面的空格
        c = getchar(); // 读系数
    }
    if (c >= '0' && c <= '9')
        while (c >= '0' && c <= '9')
        {
            coef = coef * 10 + c - '0';
            c = getchar();
        }
    else
        coef = 1;
    if (c == 'x')
    {
        c = getchar();
        if (c == '^')
        {
            c = getchar(); // 读指数
            while (c >= '0' && c <= '9')
            {
                exp = exp * 10 + c - '0';
                c = getchar();
            }
        }
        else
            exp = 1;
    }
    else
        exp = 0;
    p->next = NULL;
    p->data.coef = coef * sign;
    p->data.exp = exp;
    return p;
}

void standardization(PolyNode *p0)
{
    PolyNode *p, *pre;

    // 输入 & 合并同类项
    while ((p = input()) != NULL)
    {

        for (pre = p0; pre->next != NULL && pre->next->data.exp > p->data.exp; pre = pre->next)
            ;
        if (pre->next == NULL || pre->next->data.exp < p->data.exp)
        {
            p->next = pre->next;
            pre->next = p;
        }
        else
        {
            pre->next->data.coef += p->data.coef;
            free(p);
        }
    }

    // 剔除系数为零的项
    for (pre = p0; pre->next != NULL;)
    {
        if (pre->next->data.coef == 0)
        {
            p = pre->next;
            pre->next = p->next;
            free(p);
        }
        else
            pre = pre->next;
    }
    return;
}

void derivation(PolyNode *p0)
{
    PolyNode *p;
    while (p0->next != NULL)
        if (p0->next->data.exp)
        {
            p0->next->data.coef *= p0->next->data.exp;
            p0->next->data.exp--;
            p0 = p0->next;
        }
        else
        {
            p = p0->next;
            p0->next = p->next;
            free(p);
        }
    return;
}

void print_release(PolyNode *p0)
{
    PolyNode *p;
    if (p0->next == NULL)
    {
        printf("0\n");
        return;
    }
    if (p0->next->data.coef < -1)
        printf("- %d", -1 * p0->next->data.coef);
    else if (p0->next->data.coef == -1)
        printf("- ");
    else if (p0->next->data.coef > 1)
        printf("%d", p0->next->data.coef);
    if (p0->next->data.exp > 1)
        printf("x^%d", p0->next->data.exp);
    else if (p0->next->data.exp == 1)
        printf("x");
    if ((p0->next->data.coef == 1 || p0->next->data.coef == -1) && p0->next->data.exp == 0)
        printf("1");
    p = p0->next;
    p0->next = p->next;
    free(p);
    while (p0->next != NULL)
    {
        if (p0->next->data.coef < 0 && p0->next->data.coef != -1)
            printf(" - %d", -1 * p0->next->data.coef);
        else if (p0->next->data.coef == -1)
            printf(" - ");
        else if (p0->next->data.coef == 1)
            printf(" + ");
        else
            printf(" + %d", p0->next->data.coef);
        if (p0->next->data.exp > 1)
            printf("x^%d", p0->next->data.exp);
        else if (p0->next->data.exp == 1)
            printf("x");
        if ((p0->next->data.coef == 1 || p0->next->data.coef == -1) && p0->next->data.exp == 0)
            printf("1");
        p = p0->next;
        p0->next = p->next;
        free(p);
    }
    return;
}

int main()
{
    PolyNode head = {{0, 0}, NULL};
    standardization(&head);
    derivation(&head);
    print_release(&head);
    return 0;
}