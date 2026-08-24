#include <stdio.h>

int main()
{
    int ch;
    float bal=1000, x;

    do
    {
        printf("\n1.Balance 2.Deposit 3.Withdraw 4.Transfer 5.Exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Balance=%.2f",bal); break;

            case 2:
                scanf("%f",&x);
                if(x>0) bal+=x;
                else printf("Invalid");
                break;

            case 3:
                scanf("%f",&x);
                if(x>0 && x<=bal) bal-=x;
                else printf("Invalid/Insufficient");
                break;

            case 4:
                scanf("%f",&x);
                if(x>0 && x<=bal) bal-=x;
                else printf("Invalid/Insufficient");
                break;

            case 5: printf("Thank you"); break;

            default: printf("Invalid choice");
        }
    }while(ch!=5);

    return 0;
}
