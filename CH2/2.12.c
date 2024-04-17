/*设A=(a_1,...,a_m)和B=(b_1,...,b_n)均为顺序表，A′和B′分别A和B中除去最大共同前缀后的子表.
若A′=B′=NULL，则A=B；
若A′=NULL，而B′不等于NULL，或者两者均不为NULL，且A′的首元小于B′的首元，则A<B；否则A>B。
试写一个比较A,B大小的算法。*/
#include <stdio.h>
#include <stdlib.h>
#define ElemType char
typedef struct sqlist
{
    ElemType value;
    struct sqlist *next;
} sqlist;

sqlist *lalloc()
{
    return (sqlist *)malloc(sizeof(sqlist));
}

void input(sqlist *p0)
{
    sqlist *p;
    ElemType x;
    int bj = 0;
    while (scanf("%c", &x) != EOF)
    {
        switch (x)
        {
        case ',':
            continue;
        case '\n':
            bj = 1;
            break;
        default:
            p = lalloc();
            p0->next = p;
            p->value = x;
            p->next = NULL;
            p0 = p;
            break;
        }
        if (bj)
            break;
    }
    return;
}

int compare(sqlist *a, sqlist *b)
{
    while (a != NULL && b != NULL)
    {
        if (a->value < b->value)
            return 1;
        else if (a->value > b->value)
            return 2;
        a = a->next;
        b = b->next;
    }
    if (a == NULL && b != NULL)
        return 1;
    else if (a != NULL && b == NULL)
        return 2;
    else
        return 0;
}

void release(sqlist *p0)
{
    sqlist *p;
    p0 = p0->next;
    while (p0 != NULL)
    {
        p = p0->next;
        free(p0);
        p0 = p;
    }
    return;
}

int main()
{
    sqlist a = {0, NULL}, b = {0, NULL};
    input(&a);
    input(&b);
    printf("%d\n", compare(&a, &b));
    release(&a);
    release(&b);
    return 0;
}