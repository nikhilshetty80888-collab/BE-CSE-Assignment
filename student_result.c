#include <stdio.h>

int main()
{
    int n, i, j, m, total, high = 0;
    char name[50][20], grade;
    int marks[50][5];
    float per, hp = 0;

    printf("Students: ");
    scanf("%d", &n);
    printf("Subjects (3-5): ");
    scanf("%d", &m);

    for(i=0;i<n;i++)
    {
        printf("Name: ");
        scanf("%s", name[i]);
        total=0;

        for(j=0;j<m;j++)
        {
            scanf("%d",&marks[i][j]);
            total += marks[i][j];
        }

        per=(float)total/m;

        if(per>=90) grade='A';
        else if(per>=80) grade='B';
        else if(per>=70) grade='C';
        else if(per>=60) grade='D';
        else if(per>=50) grade='E';
        else grade='F';

        printf("%s Total=%d Percentage=%.2f Grade=%c\n",
               name[i],total,per,grade);

        if(per>hp) { hp=per; high=i; }
    }

    printf("Highest: %s %.2f%%",name[high],hp);
    return 0;
}
