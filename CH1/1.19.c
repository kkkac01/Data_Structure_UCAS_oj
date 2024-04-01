#include <stdio.h>
int main()
{
    unsigned int a[11]={1,2,8,48,384,3840,46080,645120,10321920,185794560,3715891200};
    int n,arrsize;
    scanf("%d%d",&n,&arrsize);
    if(n>arrsize||n>11)printf("-1\n");
    else
        for(int i=0;i<n;i++)
            printf("%d ",a[i]);
    return 0;
}
