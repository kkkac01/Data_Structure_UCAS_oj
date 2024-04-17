/*已知A，B和C为三个递增有序的线性表，现要求对A表做如下操作：删去那些既在B表中出现又在C表中出现的元素。试对顺序表编写实现上述操作的算法。*/
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
    char c;
    for (c = getchar(); c != '\n'; c = getchar())
        if (c != ',')
        {
            p = lalloc();
            p->value = c;
            p->next = NULL;
            p0->next = p;
            p0 = p;
        }
    return;
}

void compare(sqlist *pfor, sqlist *plast)
{
    sqlist *p;
    int bj;
    while (pfor->next != NULL)
    {
        bj = 0;
        for (p = plast; p->next != NULL; p = p->next)
            if (p->next->value == pfor->next->value)
            {
                bj = 1;
                break;
            }
        if (!bj)
        {
            p = pfor->next;
            pfor->next = p->next;
            free(p);
        }
        else
            pfor = pfor->next;
    }
    return;
}

void del(sqlist *a, sqlist *b)
{
    sqlist *p;
    int bj;
    while (a->next != NULL)
    {
        bj = 0;
        for (p = b; p->next != NULL; p = p->next)
            if (p->next->value == a->next->value)
            {
                bj = 1;
                break;
            }
        if (bj)
        {
            p = a->next;
            a->next = p->next;
            free(p);
        }
        else
            a = a->next;
    }
    return;
}

void print_release(sqlist *p0)
{
    sqlist *p;
    p0 = p0->next;
    while (p0->next != NULL)
    {
        p = p0->next;
        printf("%c,", p0->value);
        free(p0);
        p0 = p;
    }
    printf("%c\n", p0->value);
    free(p0);
    return;
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
    sqlist a = {0, NULL}, b = {0, NULL}, c = {0, NULL};
    input(&a);
    input(&b);
    input(&c);
    compare(&b, &c);
    del(&a, &b);
    if (a.next != NULL)
        print_release(&a);
    else
    {
        printf("NULL\n");
        release(&a);
    }
    release(&b);
    release(&c);
    return 0;
}