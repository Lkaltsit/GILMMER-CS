#include <stdio.h>
int main()
{ 
    char choice;
    int cnt=0;
    do
    {
        
        char name[100];
        int age;
        printf("请输入您的姓名与年龄\n");
        printf("您的姓名：");
        scanf("%s",&name);
        printf("您的年龄：");
        scanf("%d",&age);
        printf("您的姓名：%s\n 您的年龄：%d\n",name,age);
        printf("是否继续输入（是/Y 否/N）\n");
        scanf(" %c",&choice);
        cnt++;
        while(choice!='Y'&&choice!='N')
        {
            printf("请重新选择：\n");
            scanf(" %c",&choice);
        }
    }
    while(choice=='Y');
     printf("已输入%d次\n",cnt);
     return 0;
}