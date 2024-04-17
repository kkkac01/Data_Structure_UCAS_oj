/*设顺序表va中的数据为递增有序。写一个算法，将x插入到顺序表的适当位置，保证有序性
输入分为两行，第一行是va顺序表，每个元素按空格分隔，第二行是x的值。
顺序表中的元素最多为100个，所有元素的值均大于0，元素为整型。
输出插入x后，va的结果*/
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
        p0 = p0->next;
    }
    return;
}

void insert(sqlist *p0, ElemType x)
{
    sqlist *p = lalloc();
    p->next = NULL;
    p->value = x;
    while (p0->next != NULL && x > p0->next->value)
        p0 = p0->next;
    p->next = p0->next;
    p0->next = p;
    return;
}

void print(sqlist *p0)
{
    while (p0->next != NULL)
    {
        printf("%d ", p0->next->value);
        p0 = p0->next;
    }
    printf("\n");
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
    ElemType x;
    sqlist head;
    input(&head);
    scanf("%d", &x);
    insert(&head, x);
    print(&head);
    release(&head);
    return 0;
}