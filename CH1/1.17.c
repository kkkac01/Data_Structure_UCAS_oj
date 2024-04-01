#include<stdio.h>

int main(){
    int a[1005]={},m,k,i,j;
    scanf("%d%d",&k,&m);
    a[k-1]=1;
    for(i=k;i<=m;i++)
        for(j=0;j<k;j++)
            a[i]+=a[i-1-j];
    printf("%d\n",a[m]);
    return 0;
}