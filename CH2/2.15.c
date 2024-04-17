/*已知指针ha和hb分别指向两个单链表的头结点，并且已知两个链表的长度分别为m和n。
试写一算法将这两个链表连接在一起（即令其中一个表的首元节点连在另一个表的最后一个节点之后），假设指针hc指向连接后的链表的头结点，
并要求算法以尽可能短的时间完成链接运算。*/
#include <stdio.h>
#include <stdlib.h>
#define ElemType int
typedef struct sqlist
{
    ElemType value;
    struct sqlist *next;
} sqlist;

sqlist *lalloc()
{
    return (sqlist *)malloc(sizeof(sqlist));
}

void input(int len, sqlist *p0)
{
    sqlist *p;
    int i, x;
    for (i = 0; i < len; i++)
    {
        scanf("%d", &x);
        p = lalloc();
        p0->next = p;
        p->next = NULL;
        p->value = x;
        p0 = p;
    }
    return;
}

void link(sqlist *a, sqlist *b)
{
    while (b->next != NULL)
        b = b->next;
    b->next = a->next;
    a->next = NULL;
    return;
}

void print_release(sqlist *p0)
{
    sqlist *p;
    p0 = p0->next;
    while (p0 != NULL)
    {
        p = p0->next;
        printf("%d ", p0->value);
        free(p0);
        p0 = p;
    }
    printf("\n");
    return;
}

int main()
{
    int m, n;
    sqlist a = {0, NULL}, b = {0, NULL};
    scanf("%d%d", &m, &n);
    input(m, &a);
    input(n, &b);
    link(&a, &b);
    print_release(&b);
    return 0;
}