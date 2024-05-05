/*设有一双向循环链表，每个节点中除有prior,data和next三个域外，还增设了一个访问频度域freq。
在链表被启用之前，频度域freq的值均初始化为0，而每当对链表进行一次LOCATE(L,x)的操作后，
被访问的节点（即元素值等于x的节点）中的频度域freq的值便增1，同时调整链表中节点之间的次序，使其按访问频度非递增的次序顺序排列，
以便始终保持被频繁访问的节点总是靠近表头结点。编写符合上述要求的LOCATE操作的算法。*/
#include <stdio.h>
#include <stdlib.h>
#define ElemType int
typedef struct sqlist
{
    ElemType data, freq, seq;
    struct sqlist *next, *prior;
} sqlist;
int seq;

sqlist *lalloc()
{
    return (sqlist *)malloc(sizeof(sqlist));
}

void input(sqlist *p0, int len)
{
    int x;
    sqlist *p;
    for (; len > 0; len--)
    {
        scanf("%d", &x);
        p = lalloc();
        p->data = x;
        p->next = NULL;
        p->prior = p0;
        p->freq = 0;
        p->seq = 0;
        p0->next = p;
        p0 = p;
    }
    return;
}

void insert(sqlist *a, sqlist *b)
{
    sqlist *ptemp = b->next;
    b->next = ptemp->next;
    if (b->next != NULL)
        b->next->prior = b;
    ptemp->next = a->next;
    a->next->prior = ptemp;
    a->next = ptemp;
    ptemp->prior = a;
    return;
}

void visit(sqlist *p0)
{
    int x;
    sqlist *p, *pre;
    while (scanf("%d", &x) != EOF)
    {
        for (p = p0; p->next->data != x; p = p->next)
            ;
        p->next->freq++;
        if (p->next->seq == 0)
            p->next->seq = ++seq;
        if (p->prior != NULL)
        {
            for (pre = p; pre->prior != NULL && pre->freq < p->next->freq; pre = pre->prior)
                ;
            for (; pre->prior != NULL && pre->freq == p->next->freq && pre->seq > p->next->seq; pre = pre->prior)
                ;
            if (pre->next->data != p->next->data)
                insert(pre, p);
        }
    }
}

void print_release(sqlist *p0)
{
    sqlist *p;
    p0 = p0->next;
    while (p0->next != NULL)
    {
        p = p0->next;
        printf("%d ", p0->data);
        free(p0);
        p0 = p;
    }
    printf("%d\n", p0->data);
    free(p0);
    return;
}

int main()
{
    int len;
    sqlist head = {0, 0, 0, NULL, NULL};
    scanf("%d", &len);
    input(&head, len);
    visit(&head);
    print_release(&head);
    return 0;
}