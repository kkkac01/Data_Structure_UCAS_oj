/*试写一算法，实现单链表的就地逆置*/
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
            p->next = p0->next;
            p0->next = p;
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

int main()
{
    sqlist head = {0, NULL};
    input(&head);
    if (head.next != NULL)
        print_release(&head);
    else
        printf("NULL\n");
    return 0;
}