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