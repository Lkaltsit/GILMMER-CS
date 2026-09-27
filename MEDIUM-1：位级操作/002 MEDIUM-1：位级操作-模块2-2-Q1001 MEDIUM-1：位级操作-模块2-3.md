```c
#include <stdio.h>


int hasCommonChar(const char *s1, const char *s2);
int main()
{
    const char s1[100]={0};
    const char s2[100]={0};
    printf("请输入第一个字符串：");
    scanf("%s",s1);
    printf("请输入第二个字符串：");
    scanf("%s",s2);
    printf("%d",hasCommonChar(s1,s2));
    return 0;
}
int hasCommonChar(const char *s1, const char *s2)
{
    int mask1 = 0;
    int mask2 = 0;
    while(*s1)
    {
        mask1=mask1|(1<<(*s1-'a'));
        s1++;
    }
    while(*s2)
    {
        mask2=mask2|(1<<(*s2-'a'));
        s2++;
    }
    int temp1=mask1&mask2;
    int ret=0;//int cnt==0;
    if(temp1==0)
    {
        return 0;//cnt=0;
    }
    else
    {
        for(int i=0;i<26;i++)
        {
            int temp2=temp1;
            if((temp2&(1<<i))!=0)
            {
                ret=1;
                break;
                //cnt++;
            }
        }
    }
    return ret;//cnt;
}
//不得不说的一环 不审题导致以为是看有几个是出现的了 然后就写成注释那样了 我就说怎么我是2而这个是1呢 不过我这个还能优化的吧？
//如果要看同一位是不是一样的话应该也是要弄得 看情况吧
```