/*试写一算法，在无头节点的动态单链表上实现线性表删除元素操作Delete(L,i)

----------------------思路------------------------------
构建链表-插入元素-确定删除位置-删除-输出-释放空间*/
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

void input(sqlist *head)
{
    sqlist *p, *p0 = head;
    int x;
    char c;
    do
    {
        scanf("%d", &x);
        p = lalloc();
        p->value = x;
        p->next = NULL;
        p0->next = p;
        p0 = p;
        head->value++;
    }while ((c = getchar()) != '\n');
    return;
}

void del(sqlist *p0, int pos)
{
    p0->value--;
    for (; pos > 0; pos--)
        p0 = p0->next;
    sqlist *p = p0->next;
    p0->next = p->next;
    free(p);
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
    sqlist head = {0, NULL};
    int x, i, bj = 1;
    char c;
    input(&head);
    scanf("%d", &x);
    if (x >= head.value || x < 0)
        printf("NULL\n");
    else{
        del(&head,x);
        if(head.value)
            print(&head);
        else
            printf("NULL\n");
    }
    release(&head);
    return 0;
}