/*已知线性表中的元素以递增有序排列，并以单链表为存储结构。
试写一高效算法，删除表中所有值大于mink且小于maxk的元素（若表中存在这样的元素），同时释放被删节点的空间。
样例 1 2 3 4 5 8 12 15 16 22\n6 18*/
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

void input(sqlist *p0)
{
    sqlist *p;
    int x;
    char c = ' ';
    for (; c != '\n'; c = getchar())
    {
        scanf("%d", &x);
        p = lalloc();
        p->value = x;
        p->next = NULL;
        p0->next = p;
        p0 = p;
    }
    return;
}

void del(sqlist *p0, int minn, int maxn)
{
    sqlist *pmin;
    while (p0->next != NULL && minn >= p0->next->value)
        p0 = p0->next;
    pmin = p0;
    while (pmin->next != NULL && maxn > pmin->next->value ){
        p0 = pmin->next;
        pmin->next = p0->next;
        free(p0);
    }
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
    sqlist head = {0, NULL};
    int minn, maxn;
    input(&head);
    scanf("%d%d", &minn, &maxn);
    del(&head, minn, maxn);
    if(head.next == NULL)
        printf("NULL\n");
    else
        print_release(&head);
    return 0;
}