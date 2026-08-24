#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a,n,i,max,min,sum=0,x,count=0;

    scanf("%d",&n);
    a=malloc(n*sizeof(int));

    if(a==NULL) return 1;

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }

    max=min=a[0];

    for(i=1;i<n;i++)
    {
        if(a[i]>max) max=a[i];
        if(a[i]<min) min=a[i];
    }

    printf("Max=%d Min=%d Sum=%d Avg=%.2f",
           max,min,sum,(float)sum/n);

    printf("\nSearch: ");
    scanf("%d",&x);

    for(i=0;i<n;i++)
        if(a[i]==x) count++;

    printf("Frequency=%d\nReverse:",count);

    for(i=n-1;i>=0;i--)
        printf(" %d",a[i]);

    free(a);
    return 0;
}
