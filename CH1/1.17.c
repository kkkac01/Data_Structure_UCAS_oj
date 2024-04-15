/*
已知k阶斐波那契序列的定义为
f_0=f_1=f_2=...=f_{k-2}=0,f_{k-1}=1,
f_k=f_{k-1}+...+f_1+f_0
试编写求k阶裴波那契序列的第m项值的函数算法
*/
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