#include <stdio.h>
int main()
{
    int sum_1=0;
    int sum_2=0;
    int sum_3=0;
    for(int i=0;i<11;i++)
    {
        sum_1+=i;
    }
    int j=0;
    while(j!=11)
    {
        sum_2+=j;
        j++;
    }
    int k=-1;
    do
    {
        k++;
        sum_3+=k;
    }
    while(k!=10);
    printf("%d %d %d",sum_1,sum_2,sum_3);
    return 0;
}