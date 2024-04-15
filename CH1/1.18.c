/*假设有A,B,C,D,E 五个高等院校进行田径对抗赛，各院校的单项成绩均已存入计算机，并构成一张表，表中每一行的形式为
项目名称 - 性别 - 校名 - 成绩
编写算法，处理上述表格，以统计个院校的男、女总分和团体总分，并输出*/
#include <stdio.h>

typedef struct school
{
    char name;
    int femalescore, malescore;
} score;

int main()
{
    score s[5] = {{'A'}, {'B'}, {'C'}, {'D'}, {'E'}};
    char prj, gender, school;
    int sre, i;
    while (scanf("%c %c %c %d", &prj, &gender, &school, &sre) != EOF)
    {
        i = school - 'A';
        if (gender == 'M')
            s[i].malescore += sre;
        else
            s[i].femalescore += sre;
        getchar();
    }
    for (i = 0; i < 5; i++)
    {
        if (s[i].malescore != 0)
            printf("%c M %d\n", s[i].name, s[i].malescore);
        if (s[i].femalescore != 0)
            printf("%c F %d\n", s[i].name, s[i].femalescore);
        if (s[i].malescore != 0 || s[i].femalescore != 0)
            printf("%c %d\n", s[i].name, s[i].femalescore + s[i].malescore);
    }
}