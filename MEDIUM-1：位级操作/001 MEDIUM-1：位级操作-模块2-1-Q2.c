#include <stdio.h>
int main()
{
    int number,n,cnt=0;
    printf("请输入一个整数：");
    scanf("%d",&number);
    printf("请输入一位位数：");
    scanf("%d",&n);
    while(cnt!=n)
    {
            number>>1;
            cnt++;
    }
    return 0;
}